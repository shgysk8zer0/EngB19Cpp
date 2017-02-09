/*
	3pi-mazesolver - demo code for the Pololu 3pi Robot
	This code will solve a line maze constructed with a black line on
	white background, as long as there are no loops.  It has two
	phases: first, it learns the maze, with a "left hand on the wall"
	strategy, and computes the most efficient path to the finish.
	Second, it follows its most efficient solution.
*/
#include <pololu/3pi.h>
#include <avr/pgmspace.h>


const char levels[] PROGMEM = 
{
      ObOOOOO,
      ObOOOOO,
      ObOOOOO,
      ObOOOOO,
      ObOOOOO,
      ObOOOOO,
      ObOOOOO,
      Oblllll,
      Oblllll,
      Oblllll,
      Oblllll,
      Oblllll,
      Oblllll,
      Oblllll;
} 


const char welcome_linel[] PROGMEM = " Pololu",
           welcome_line2[] PROGMEM = "3\xf7 Robot",
           demo_name_linel[] PROGMEM = "Maze",
           demo_name_line2[] PROGMEM = "solver",
           welcome [] PROGMEM = ">g32"c32",
           go[] PROGMEM = "LI6 cdegreg4";
char path[100] = "";
unsigned char path__length =0; // the length of the path

void	initialize();
void	load_custom_characters() ;
void	display_readings(const unsigned int *) ;
void	follow_segment();
void	display_path() ;
char	select_turn(unsigned char, unsigned char, unsigned char);
void	simplify_path() ;
void	maze_solve() ;
void	turn(char);

int main ()
{
    initialize ();
    maze_solve();    
    while(1);
}

/* 
	Initializes the 3pi, displays a welcome message, calibrates, and 
	plays the initial music. 
*/

void initialize ()
{
    unsigned int counter, 	// used as a simple timer
				sensors[5], // an array to hold sensor values
				position;	//

    pololu_3pi_init(2000);
    load_custom_characters(); 

	print_from_program_space(welcome_linel); 
	lcd_goto_xy(0,l);
	print_from_program_space(welcome_line2); 
	play_from_program_space(welcome);
	delay ms(1000); 

	clear ();
	print_from_program_space(demo_name_linel);
	lcd_goto_xy(0,l);
	print_from_program_space(demo_name_line2);
	delay_ms(1000);

	while(!button_is_pressed(BUTTON_B))
	{
	   int bat = read_battery_millivolts();
	   
	   clear (); 
	   print_long(bat);
	   print ( "mV" ) ; 
	   lcd_goto_xy (0,1) ; 
	   print ( "Press B") ;
	   delay__ms (100) ;
	}
 
	wait_for_button_release (BUTTON_B); 
	delay_ms (1000);

	for ( count er=0; counter<80; count er++)
	{
		if (counter < 20 |  counter >= 60)
			set_motors(40, -40) ;
		else
			set motors(-40,40);
 
		calibrate_line_sensors(IR_EMITTERS_ON);
		delay_ms(20);
	}
	set_motors(0,0);

	while(!button_is_pressed(BUTTON_B))
	position = read_line(sensors,IR_EMITTERS_ON);
	clear();
	print_long(position) ;
	lcd_goto_xy(0,1);
	display_readings(sensors) ;
   
	delay__ms (100);
}
wait_for_button_release(BUTTON_B);
clear() ; 
print("Go!");
 
play_from__program_space (go); 
while(is_playing());
}

void load_custom_characters()
{ 

     lcd_load_custom_character(levels + 0, 0)	// no offset, e.g. one bar 
     lcd_load_custom_character(levels+1,1)		// two bars
     led load custom character(levels+2,2)		// etc...
     lcd_load_custom_character (levels+3,3) 
     lcd_load_custom_character ( levels + 4 , 4 )
     lcd_load_custom_character (levels + 5, 5 ) 
     lcd_load_custom_character (levels + 6, 6)
     
     clear (); 
}


void display_readings (const unsigned int *calibrated_values) 
{
     unsigned char i;
	 const char display_characters [ 10];
	 char c;
    
	for(i=0;i<5;i++) 
     {
		display_characters [ 10] = {' ',0,0,1,2,3,4,5,6,255};
        char c = display characters [calibrated_values [i] /101] ;
		print_character(c);
     }
}
void follow_segment()
{
	int last_proportional = 0,
		proportinal,
		derivative,
		power_difference,
		position;
	long integral = 0;
	unsigned int sensors[5],
				 position;
	const int max = 60;
		 while(1)
		{
		 
			position = read_line(sensor,IR_EMITTERS_ON);
		 
			proportinal = (position) - 2000
			derivative = proportional - last_proportional; 
			integral += proportional;
			last_proportional = proportional;
			power_difference = proportional/20 + integral/10000 + derivative*3/2;
			max = 60; 
			max = 60; 
			if(power_difference > max)
				power_difference = max; 
			if(power_difference < -max)
				power_difference = -max;
			if(power_difference < 0)
				set_motors(max+power_difference,max); 
			else
				set_motors(max,max-power_difference)

			if(sensors[1] < 100 && sensors[2] < 100 && sensors[3] < 100)
				return; 
			else if(sensors [0] > 200 || sensors[4] > 200)
				return;
		}
}
/*
	Displays the current path on the LCD, using two rows if necessary.
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
	This function decides which way to turn during the learning phase of 
	maze solving.  It uses the variables found_left, found_straight, and 
	found_right, which indicate whether there is an exit in each of the 
	three directions, applying the "left hand on the wall" strategy, 
*/
char select_turn(unsigned char found_left, unsigned char found_straight,
unsigned char found_right) 
int total_angle,
	i;
{
   if(found_left)
      return 'L';
   else if(found_straight)
   `  return 'S';
   else if(found_right)
      return 'R'; 
   else
      return 'B';
   if !(path_length < 3  | path[path_length-2] != 'B')
   {
		total_angle = 0;
		i;
      for(i=l;i<=3;i++)
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
   }
total_angle = total_angle % 360;

   switch (total_angle)
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
          path[path_length - 3] = ' L' ;
          break;
   }
          path_length -= 2;
}

void maze_solve()
{
     while (1)
	{
         // FIRST MAIN LOOP BODY 
		unsigned char found_left=0,
					  found_straight=0,
					  found_right=0,
					  dir,
					  sensors [5];
		 
         follow_segment();
         set_motors(50,50);
         delay_ms(50);
         read_line(sensors,IR_EMITTERS_ON);
         
        if(sensors[0] > 100)
                found_left = 1;
        if(sensors[4] > 100)
                 found_right = 1;
		set_motors(40,40); 
		delay_ms(200);
		read_line(sensors,IR_EMITTERS_ON);
        if(sensorst[l] > 200 || sensors[2] > 200  I sensors[3] > 200)
                found_straight = 1;
        if (sensors[1] > 600 && sensors[2] > 600 && sensors[3] > 600) 
           break;
		dir = select_turn (f ound_left, f ound_straight, f ound_right );
        turn(dir) ;
        path [path_length] = dir; 
        path_length ++;
		simplify_path();
		display path(); 
	} 
	while (1)
	{
		  set_motors (0,0) ; 
		  play("a32");
		  
			while ( !button_is_pressed(BUTTON_B) )
			{
				  if(get_ms() % 2000 < 1000)
				{
					clear () ;
					print ("Solved!") ;
					lcd_goto_xy(0,l) ;
					print ("Press B") ;
				}
				  else
				  display_path();
				  delay_ms(30);
			}
			while (button_is_pressed(BUTTON_B) ) ;
			delay ms (1000); 
			int i ;
			for (i=0;i<path length; i++)
			 
			// SECOND MAIN LOOP BODY 
			follow_segment();
			set_motors(50,50);
			delay_ms (50) ; 
			set_motors (40,40); 
			delay_ms (200) ;
			turn(path[i]);
	}
	follow_segment();
}
/*
	Turns according to the parameter dir, which should be 'L', 'R', 'S' 
	(straight), or 'B' (back). 
*/
void turn (char dir) 
{
     switch (dir)
     {
		 case 'L' :
			  set_motors (-80,80);
			  delay_ms (200) ;
			  break; 
		 case ' R' :
			  set_motors (80, -80) ;
			  delay_ms (200) ;
			  break; 
		 case 'B' :
			  set_motors (80, -80) ;
			  delay_ms (400) ;
			  break; 
		 case 'S':
			  break;
     }
}
