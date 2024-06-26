#include "Arduino.h"

/*
/////////////////////////////////////////////////////////////////////////
// KEY MAPPINGS: WHICH KEY MAPS TO WHICH PIN ON THE MEOW MEOW BOARD? //
/////////////////////////////////////////////////////////////////////////
  
  - edit the keyCodes array below to change the keys sent by the Meow Meow for each input
  - the comments tell you which input sends that key (for example, by default 'w' is sent by pin A6)
  - change the keys by replacing them. for example, you can replace 'w' with any other individual letter,
    number, or symbol on your keyboard
  - you can also use codes for other keys such as modifier and function keys (see the
    the list of additional key codes at the bottom of this file)

*/

int keyCodes[NUM_INPUTS] = {            
  //     top side of the meow meow board
  's',                // pin A0 
  'd',                // pin A1
  KEY_LEFT_ARROW,   // right arrow pad A2
  KEY_RIGHT_ARROW,    // left arrow pad A3
  KEY_DOWN_ARROW,    // down arrow pad A4
  KEY_UP_ARROW,      // up arrow pad A5
  'w',                // pin A6
  'a',                // pin A7
  MOUSE_LEFT,        // click button pad A8
  ' ',               // space button pad A9
};

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

////////////////////////
// MOUSE MOTION /////////
/////////////////////////
#define CALIBRATION                   140   // number between 0 and 1000
                                           // Initial calibration percentage
                                           // recommended values are between 20 and 150
                                           // default value is 50
                                           //Change this variable to something between 
                                           //your capacitive touch serial readouts for 
                                           //on and off
/*

///////////////////////////
// ADDITIONAL KEY CODES ///
///////////////////////////

- you can use these codes in the keyCodes array above
- to get modifier keys, function keys, etc 
  
MOUSE_MOVE_UP
MOUSE_MOVE_DOWN
MOUSE_MOVE_LEFT
MOUSE_MOVE_RIGHT
MOUSE_LEFT      
MOUSE_RIGHT         

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
