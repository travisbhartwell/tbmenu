// KEYCODE.CPP
//  Utility to produce an include file with keycodes defined as constants
//  Compile with:
//     ..\source\keyboard.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "..\include\keyboard.h"

string getFileName( void );
void   createFile( ostream &outFile );

int main( int argc, char *argv[] )
{
    string fileName;

    if ( argc < 2 )
    {
        // Filename to output wasn't on command line
        fileName = getFileName();
    }
    else
    {
        fileName = argv[1];
    }

    ofstream outFile( fileName.c_str() );

    createFile( outFile );

    outFile.close();

    return 0;
}

string getFileName( void )
{
    string fileName;

    cout << "Please enter file name to output to: ";
    cin >> fileName;

    return fileName;
}

void createFile( ostream &outFile )
{
    bool done = false;
    int keyValue;
    string constName;

    // Output a header to the const defines
    outFile << "// Key scan code definitions" << endl;

    while ( ! done )
    {
        cout << "Press key to define ( or ALT-X to exit ): " << endl;

        WORD key = getKey();

        if ( key.low == 0 )
        {
            if ( key.high == 45 )
            {
                // Alt-X was pressed
                done = true;
                break;
            }

            keyValue = key.high;
        }
        else
        {
            keyValue = key.low;
        }

        cout << "Type in constant name to assign to:  ";
        cin >> constName;

        outFile << "const int " << constName << " = " << keyValue << ";" << endl;
    }
}
