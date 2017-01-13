// SCREEN.H
//  Screen handling routines

#if ! defined ( SCREEN_H )
#define SCREEN_H

const int RED   = 0x4;
const int WHITE = 0xF;
const int BLUE  = 0x1;

struct cursor
{
        int startLine, stopLine;
};

void   locCursor( int x, int y, int page = 0 );
void   cls( void );
void   print( char *string, int attribute, int x, int y );
cursor getCursor( void );
void   setCursor( cursor cur );

#endif
