// SCREEN.CPP
//  Screen handling routines

#include <dpmi.h>
#include "..\include\screen.h"

void locCursor( int x, int y, int page )
{
    __dpmi_regs r;

    r.h.ah = 2;
    r.h.dh = x;
    r.h.dl = y;
    r.h.bh = page;

    __dpmi_int( 0x10, &r );
}

void cls( void )
{
    __dpmi_regs r;

    r.h.ah = 6;
    r.h.al = 0;
    r.h.bh = 7;
    r.x.cx = 0;
    r.h.dh = 24;
    r.h.dl = 79;

    __dpmi_int( 0x10, &r );

    locCursor( 0, 0 );
}

void print( char *string, int attribute, int x, int y )
{
    __dpmi_regs r;

    while ( *string != '\0' )
    {
        locCursor( x, y++, 0 );

        r.h.ah = 9;
        r.h.bh = 0;
        r.x.cx = 1;
        r.h.bl = attribute;
        r.h.al = *string++;

        __dpmi_int( 0x10, &r );
    }
}

cursor getCursor( void )
{
    __dpmi_regs r;

    r.h.ah = 3;
    r.h.bh = 0;

    __dpmi_int( 0x10, &r );

    cursor cur;
    cur.startLine = r.h.ch;
    cur.stopLine = r.h.cl;

    return cur;
}

void setCursor( cursor cur )
{
    __dpmi_regs r;

    r.h.ah = 1;
    r.h.ch = cur.startLine;
    r.h.cl = cur.stopLine;

    __dpmi_int( 0x10, &r );
}
