/*
    Chris Zuber
    
    
    Program # project
    Engr b19 c/c++
    Program Description: This code will solve a line maze constructed
	with a black line on
    white background, as long as there are no loops.  It has two
    phases: first, it learns the maze, with a "left hand on the wall"
    strategy, and computes the most efficient path to the finish.
    Second, it follows its most efficient solution.
    Input: None
    Output: All the answers to all of the questions... 42
*/


#include <pololu/3pi.h>
#include <avr/pgmspace.h>
#define stop 0,0
#define Straight_Speed 50
#define Turn_Speed 80
#define Turn_Delay 200
#define fast 100
#define med 50
#define slow 40


// go into program space.
const char welcome_line1[] PROGMEM = " Pololu",
           welcome_line2[] PROGMEM = "3\xf7 Robot",
           demo_name_line1[] PROGMEM = "Maze",
           demo_name_line2[] PROGMEM = "solver",
           levels[] PROGMEM = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};

char path[100] = "";                                    //
unsigned char path_length =0;                           // the length of the path
const char welcome [] PROGMEM = ">g32>>c32",            //music??
           go[] PROGMEM = "LI6 cdegreg4";               //music??

void initialize();
void display_readings(const unsigned int *);
void calibrate_speed();
char select_turn(unsigned char, unsigned char, unsigned char);                               
void maze_solve();
void turn(char);
void on_white();


int main()
{
    initialize ();
    maze_solve();    
    while(1);
}

/*
    Function Description- Initializes the 3pi,
    displays a welcome message, calibrates, and
    plays the initial music.
    Input:
    Output:
*/
void initialize()
{
    int bat;
    unsigned int counter, // used as a simple timer
                 position,
                 sensors[5]; // an array to hold sensor values
 
    pololu_3pi_init(2000);
    lcd_goto_xy(0,1);
    delay_ms(1000);
 
    clear();
    lcd_goto_xy(0,1);
    delay_ms(1000);

 
    while(!button_is_pressed(BUTTON_B))
    {
        bat = read_battery_millivolts();
        clear();
        print_long(bat);
        print("mV");
        lcd_goto_xy(0,1);
        print("Press B");
        delay_ms(100);
    }
    wait_for_button_release(BUTTON_B);
    delay_ms(1000);
    for(counter=0;counter<80;counter++)
    {
        if(counter < 20 || counter >= 60)
            set_motors(40,-40);
        else
            set_motors(-40,40);
        calibrate_line_sensors(IR_EMITTERS_ON);
        delay_ms(20);
    }
    set_motors(0,0);
 
    while(!button_is_pressed(BUTTON_B))
    {
        position = read_line(sensors,IR_EMITTERS_ON);
        clear();
        print_long(position);
        lcd_goto_xy(0,1);

        delay_ms(100);
    }
    wait_for_button_release(BUTTON_B);
    clear();   
    play_from_program_space(go);
    while(is_playing());
}

/*
    Function Description-
    Input:
    Output:
*/
void calibrate_speed()
{
    static int max = 100;
	int last_proportional = 0,
        power_difference,
        derivative,
        proportional;
    long integral=0;
    unsigned int sensors[5],
                 position;
 
    while(1)
    {
		clear();
        print_long(max);
		clear();
        position = read_line(sensors,IR_EMITTERS_ON);
        proportional = ((int)position) - 2000;
        derivative = proportional - last_proportional;
        integral += proportional;
        last_proportional = proportional;
        power_difference = proportional/20 + integral/10000 + derivative*3/2;
        if(power_difference > max)
            power_difference = max;
        if(power_difference < -max)
            power_difference = -max;
         
        if(power_difference < 0)
            set_motors(max+power_difference,max);
        else
            set_motors(max,max-power_difference);
		
		if (sensors[0]<100&&sensors[1]<100&&sensors[2]<100&&sensors[3]<100&&sensors[4]<100)
			on_white();
 
        if(sensors[1] < 100 && sensors[2] < 100 && sensors[3] < 100)
        {
            max++;
			return;        //break?
        }
        else if(sensors[0] > 200 || sensors[4] > 200)
        {
            return;        //break?
        }
 
    }
}

/*
    Function Description- This function decides which way
    to turn during the learning phase of maze solving.
    It uses the variables found_L, found_S, and
    found_R, which indicate whether there is an exit
    in each of the     three directions, applying the "left
    hand on the wall" strategy
    Input:
    Output:
*/
char select_turn(unsigned char found_L, unsigned char found_S, unsigned char found_R)
{    
    char returned;
    
    if(found_L)
        returned = 'L';
    else if(found_S)
        returned = 'S';
    else if(found_R)
        returned = 'R';
    else
        returned = 'B';
    return returned;
}

/*
    Function Description-
    Input:
    Output:
*/
void maze_solve()
{
    unsigned char found_L,
                  found_S,
                  found_R,
                  dir;
    unsigned int sensors[5];
    
    while(1)
    {	// FIRST MAIN LOOP BODY
		found_L=0;
        found_S=0;
        found_R=0;
        calibrate_speed();
        set_motors(Straight_Speed,Straight_Speed);
        delay_ms(50);
        read_line(sensors,IR_EMITTERS_ON);
        if(sensors[0] > 100)
            found_L = 1;
        if(sensors[4] > 100)
            found_R = 1;
        set_motors(40,40);
        delay_ms(200);

        read_line(sensors,IR_EMITTERS_ON);
        if(sensors[1] > 200 || sensors[2] > 200 || sensors[3] > 200)
            found_S = 1;

        if(sensors[1] > 200 && sensors[2] > 200 && sensors[3] > 200)
            break;
		
        dir = select_turn(found_L, found_S, found_R);
        turn(dir);
        path[path_length] = dir;
        path_length ++;
    }
}

/*
    Function Description- Turns according to the parameter dir,
    which should be 'L', 'R', 'S'
    (straight), or 'B' (back).
    Input:
    Output:
*/
void turn(char dir)
{
    switch(dir)
    {
    case 'L':
        set_motors(-Turn_Speed,Turn_Speed);
        delay_ms(Turn_Delay);
        break;
    case 'R':
        set_motors(Turn_Speed,-Turn_Speed);
        delay_ms(Turn_Delay);
        break;
    case 'B':
        set_motors(Turn_Speed,-Turn_Speed);
        delay_ms(2*Turn_Delay);
        break;
    case 'S':
        break;

    } 
}/*
	this will detect that we have taken a corner too fast
	this will only stop the robot and print the speed
*/
void on_white()
{
	while(1)
	{
	set_motors (stop);
	}
}
