// MNUMAKE.CPP
//  Make the menu file
//  Compile with:
//     ..\source\keyboard.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "..\include\keyboard.h"

struct menuItem
{
        string text;      // Text to display on menu
        string fileName;  // Filename of executable
        string params;    // Startup parameters
        string directory; // Directory to run executable from
};

void createMenuFile( ostream &outFile );

int main( int argc, char *argv[] )
{
    if ( argc < 2 )
    {
        cout << "Program usage: " << endl;
        cout << "   " << argv[0] << " [fileName] " << endl;
        cout << "   Where fileName is the name of the menu file you want to write." << endl;
    }
    else
    {
        ofstream outFile( argv[1] );

        createMenuFile( outFile );

        outFile.close();
    }

    return 0;
}

void createMenuFile( ostream &outFile )
{
    bool done = false;
    menuItem item;
    char line[80];
    int count = 0;

    while ( ! done )
    {
        cout << "Enter text to display on menu:  " << endl;
        cin.getline(line, 80 );
        item.text = line;

        cout << "Enter filename of the program to run:  " << endl;
        cin.getline( line, 80 );
        item.fileName = line;

        cout << "Enter any startup parameters:  " << endl;
        cin.getline( line, 80 );
        item.params = line;

        cout << "Enter directory to run the file from:  " << endl;
        cin.getline( line, 80 );
        item.directory = line;

        // Write the data to a file
        if ( count != 0 ) outFile << endl;
        outFile << item.text << endl;
        outFile << item.fileName << endl;
        outFile << item.params << endl;
        outFile << item.directory;

        WORD cont;
        cout << "Add another menu item? (Y/N) " << endl;
        cont = getKey();

        if ( cont.low == (int) 'n' )
            done = true;

        count++;
    }
}
