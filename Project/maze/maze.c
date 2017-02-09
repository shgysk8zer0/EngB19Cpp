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
#define max 80
#define Straight_Speed 50
#define Turn_Speed 80
#define Turn_Delay 200
#define fast 100
#define med 50
#define slow 40

// go into program space.
char path[100] = "";                                    //
unsigned char path_length =0;                           // the length of the path
const char welcome_line1[] PROGMEM = " Pololu",
           welcome_line2[] PROGMEM = "3\xf7 Robot",
           demo_name_line1[] PROGMEM = "Maze",
           demo_name_line2[] PROGMEM = "solver",           
           welcome [] PROGMEM = ">g32>>c32",            //music??
           go[] PROGMEM = "LI6 cdegreg4";               //music??
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

void initialize();
void load_custom_characters() ;
void display_readings(const unsigned int *);
void follow_segment();
void display_path() ;
char select_turn(unsigned char, unsigned char, unsigned char);
void simplify_path();                                    
void maze_solve();
void turn(char);
void dance ();


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
    load_custom_characters();
    print_from_program_space(welcome_line1);
    lcd_goto_xy(0,1);
    print_from_program_space(welcome_line2);
    play_from_program_space(welcome);
    delay_ms(1000);
 
    clear();
    print_from_program_space(demo_name_line1);
    lcd_goto_xy(0,1);
    print_from_program_space(demo_name_line2);
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
        display_readings(sensors);
        delay_ms(100);
    }
    wait_for_button_release(BUTTON_B);
    clear();
    print("AHHH!");      
    play_from_program_space(go);
    while(is_playing());
}

/*
    Function Description-
    Input:
    Output:
*/
void load_custom_characters()
{
    lcd_load_custom_character(levels+0,0); // no offset, e.g. one bar
    lcd_load_custom_character(levels+1,1); // two bars
    lcd_load_custom_character(levels+2,2); // etc...
    lcd_load_custom_character(levels+3,3);
    lcd_load_custom_character(levels+4,4);
    lcd_load_custom_character(levels+5,5);
    lcd_load_custom_character(levels+6,6);
    clear(); // the LCD must be cleared for the characters to take effect
}

/*
    Function Description-
    Input:
    Output:
*/
void display_readings(const unsigned int *calibrated_values)
{
    unsigned char i;
    const char display_characters[10] = {' ',0,0,1,2,3,4,5,6,255};
    char c;
 
    for(i=0;i<5;i++)
    {
        c = display_characters[calibrated_values[i]/101];
        print_character(c);
    }
}

/*
    Function Description-
    Input:
    Output:
*/
void follow_segment()
{
    int last_proportional = 0,
        power_difference,
        derivative,
        proportional;
    long integral=0;
    unsigned int sensors[5],
                 position;
 
    while(1)
    {
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
 
 
        if(sensors[1] < 100 && sensors[2] < 100 && sensors[3] < 100)
        
            break;
        
        else if(sensors[0] > 200 || sensors[4] > 200)
        {
            break;
        }
 
    }
}

/*
    Function Description- Displays the current
    path on the LCD, using two rows if necessary.
    Input:
    Output:
*/
void display_path ( )
{
   path [path_length] = 0;    
   clear();
   print (path);
   
   if (path_length > 8)
    {
        lcd_goto_xy (0,1);
        print (path+8 );
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
    int i;
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
        follow_segment();
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
        simplify_path();
        display_path();
    }
     
    while(1)
    {   // SECOND MAIN LOOP BODY
		while(!button_is_pressed(BUTTON_B))
			set_motors(stop);
        for(i=0;i<path_length;i++)
        {
            follow_segment();
            set_motors(med,med);
            delay_ms(50);
            set_motors(slow,slow);
            delay_ms(200);
            turn(path[i]);
        }
        follow_segment();
		set_motors(stop);
		delay_ms(5000);
		dance();
    }
}

/*
    Function Description-cuts u-turns and finds shortest path
    Input: none
    Output: none
*/
void simplify_path()
{
    int total_angle = 0;
    int i;
    
    if(path_length < 3 || path[path_length-2] != 'B')
         return; //break;
    for(i=1;i<=3;i++)
    {
        switch(path[path_length-i])
        {
            case 'R':
                total_angle += 90;
                break;
            case 'L':
                total_angle += 270;
                break;
            case 'B':
                total_angle += 180;
                break;
        }
    }
    total_angle = total_angle % 360;
 
    switch(total_angle)
    {
        case 0:
            path[path_length - 3] = 'S';
            break;
        case 90:
            path[path_length - 3] = 'R';
            break;
        case 180:
            path[path_length - 3] = 'B';
            break;
        case 270:
            path[path_length - 3] = 'L';
            break;
    }
        path_length -= 2;
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
}

/*
	dance description
*/
void dance()
{
	set_motors(-80, -80);
	delay_ms(400);
	set_motors(Turn_Speed, -Turn_Speed);
	delay_ms(2*Turn_Delay);
	set_motors(0,80);
	delay_ms(800);
	set_motors(160,0);
	delay_ms(800);
	set_motors(stop);
	delay_ms(500);
	while(1);
	set_motors(-100,100);
}
