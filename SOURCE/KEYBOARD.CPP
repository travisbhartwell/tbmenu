// KEYBOARD.CPP
//  Keyboard handling routines

#include <dpmi.h>
#include "..\include\keyboard.h"

WORD getKey( void )
{
    __dpmi_regs r;

    r.h.ah = 0;
    __dpmi_int( 0x16, &r );

    WORD ax;
    ax.low = r.h.al;
    ax.high = r.h.ah;

    return ax;
}

bool isKeyReady( void )
{
    __dpmi_regs r;

    r.h.ah = 1;
    __dpmi_int( 0x16, &r );

    if ( ( r.x.flags & 64 ) == 0 )
        return true;
    else
        return false;
}
