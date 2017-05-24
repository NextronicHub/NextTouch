#include "Arduino.h"

/*
/////////////////////////////////////////////////////////////////////////
// KEY MAPPINGS: WHICH KEY MAPS TO WHICH PIN ON THE NextTouch BOARD?  //
/////////////////////////////////////////////////////////////////////////
  
  - edit the keyCodes array below to change the keys sent by the NextTouch for each input
  - the comments tell you which input sends that key 
  - change the keys by replacing them. for example, you can replace 'q' with any other individual letter,
    number, or symbol on your keyboard
  - you can also use codes for other keys such as modifier and function keys 

*/

int keyCodes[NUM_INPUTS] = {
  // Arrows pinout setup
 
  KEY_UP_ARROW,      // Atmega_pin 6       NextTouch_pin    up arrow pad     
  KEY_DOWN_ARROW,    // Atmega_pin 12      NextTouch_pin    down arrow pad
  KEY_LEFT_ARROW,    // Atmega_pin 9       NextTouch_pin    left arrow pad
  KEY_RIGHT_ARROW,   // Atmega_pin 8       NextTouch_pin    right arrow pad
   
  
  // alphabets pinout setup
         
  'q',                // Atmega_pin 7     NextTouch_pin 1
  's',                // Atmega_pin 15    NextTouch_pin 4
  'd',                // Atmega_pin 11    NextTouch_pin 6
  'f',                // Atmega_pin 3     NextTouch_pin 7
  'g',                // Atmega_pin 2     NextTouch_pin 8
  'h',                // Atmega_pin 4     NextTouch_pin 9
  'j',                // Atmega_pin 10    NextTouch_pin 10
  'k',                // Atmega_pin 5     NextTouch_pin 11
  'l',                // Atmega_pin 13    NextTouch_pin 13
 
 // mouse pinout setup

  //MOUSE_MOVE_DOWN,    // Atmega_pin 6       NextTouch_pin    up arrow pad 
  //MOUSE_MOVE_UP,      // Atmega_pin 12      NextTouch_pin    down arrow pad
  //MOUSE_MOVE_LEFT,    // Atmega_pin 9       NextTouch_pin    left arrow pad
  //MOUSE_MOVE_RIGHT,   // Atmega_pin 8       NextTouch_pin    right arrow pad
  //MOUSE_LEFT,         //10
  //MOUSE_RIGHT         //11
};

/*

///////////////////////////
// ADDITIONAL KEY CODES ///
///////////////////////////

- you can use these codes in the keyCodes array above
- to get modifier keys, function keys, etc 

KEY_LEFT_CTRL
KEY_LEFT_SHIFT    
KEY_LEFT_ALT    
KEY_LEFT_GUI    
KEY_RIGHT_CTRL    
KEY_RIGHT_SHIFT   
KEY_RIGHT_ALT 
KEY_RIGHT_GUI   

KEY_BACKSPACE   
KEY_TAB       
KEY_RETURN      
KEY_ESC       
KEY_INSERT      
KEY_DELETE      
KEY_PAGE_UP     
KEY_PAGE_DOWN   
KEY_HOME
KEY_END       
KEY_CAPS_LOCK 
  
KEY_F1        
KEY_F2        
KEY_F3        
KEY_F4        
KEY_F5        
KEY_F6        
KEY_F7        
KEY_F8        
KEY_F9        
KEY_F10
KEY_F11       
KEY_F12     

*/  
                                         
///////////////////////////
// NOISE CANCELLATION /////
///////////////////////////
#define SWITCH_THRESHOLD_OFFSET_PERC  5    // number between 1 and 49
                                           // larger value protects better against noise oscillations, but makes it harder to press and release
                                           // recommended values are between 2 and 20
                                           // default value is 5

#define SWITCH_THRESHOLD_CENTER_BIAS 55   // number between 1 and 99
                                          // larger value makes it easier to "release" keys, but harder to "press"
                                          // smaller value makes it easier to "press" keys, but harder to "release"
                                          // recommended values are between 30 and 70
                                          // 50 is "middle" 2.5 volt center
                                          // default value is 55
                                          // 100 = 5V (never use this high)
                                          // 0 = 0 V (never use this low
                                          

/////////////////////////
// MOUSE MOTION /////////
/////////////////////////
#define MOUSE_MOTION_UPDATE_INTERVAL  35   // how many loops to wait between 
                                           // sending mouse motion updates
                                           
#define PIXELS_PER_MOUSE_STEP         4     // a larger number will make the mouse
                                           // move faster

#define MOUSE_RAMP_SCALE              150  // Scaling factor for mouse movement ramping
                                           // Lower = more sensitive mouse movement
                                           // Higher = slower ramping of speed
                                           // 0 = Ramping off
                                            
#define MOUSE_MAX_PIXELS              10   // Max pixels per step for mouse movement

