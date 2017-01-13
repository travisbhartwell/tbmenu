// Keyboard.H
//   Keyboard handling routines

#if ! defined ( _KEYBOARD_H )
#define _KEYBOARD_H

struct WORD
{
        int low, high;
};

// Scan codes of useful keys
const int UP    = 72;
const int DOWN  = 80;
const int LEFT  = 75;
const int RIGHT = 77;
const int ESC   = 27;
const int ENTER = 13;

// Returns the scan code of the key pressed
WORD getKey( void );
bool isKeyReady( void );

#endif

