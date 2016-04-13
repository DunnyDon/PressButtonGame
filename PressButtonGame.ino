#include <OrangutanLCD.h> 
#include <OrangutanMotors.h> 
#include <OrangutanAnalog.h> 
 int button_A=9; 
 int button_B=12; 
 int buzzer_pin=10; 
 int i=0;  /*The range for random numbers, remember in milliseconds*/ 
 int j=3000; 
 int Rand_num; 
 long Time,New_Time; 
 int button_value; 
 void setup() 
 { 
    
   pinMode(button_A,INPUT); 
   pinMode(button_B,INPUT); 
   pinMode(buzzer_pin, OUTPUT); 
    
 } 
 void loop() 
 { 
   button_value=digitalRead(button_A);/* Keeps cheking to if the button A has been pressed*/ 
   if(button_value==HIGH) 
   {    
    Rand_num=random(i,j);/*generates random numbers from 1 to 3000*/  
    clear(); 
    Time=millis(); /*starts the timer once the button is pressed*/ 
    /*lcd_goto_xy(0,0); 
    print_long(Time);*/ 
      if(Time==Rand_num) 
      { 
      digitalWrite(buzzer_pin,HIGH); 
      /*New_Time=Time-Rand_num;*/ 
      New_Time=millis();/* starts a new timer hopefully*/ 
        while(New_Time<j)/*this is gives the user 3000 ms to push the button or it goes to the else statement*/ 
        {  int c; 
          c=digitalRead(button_B);/*checks to see if the button b has been pressed*/ 
            if(c==HIGH) 
            { 
              clear(); 
              lcd_goto_xy(0,0); 
              print_long(New_Time); 
              lcd_goto_xy(0,1); 
              print("You win"); 
            } 
        } 
        if(New_Time>j)/*if the time elapsed since the button was pressed is greater than the time allowed this next step is followed*/ 
        { 
          
        clear(); 
        lcd_goto_xy(0,0); 
        print("You lose"); 
      } 
      
   } 
 } 
 } 
