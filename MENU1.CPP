// Travis B. Hartwell
// MENU1.CPP
//   Beta-1 of my menu program
//   Compile with:
//        .\source\keyboard.cpp
//        .\source\screen.cpp
//        .\source\menuitem.cpp

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include ".\include\keyboard.h"
#include ".\include\screen.h"
#include ".\include\menuitem.h"

string       getFileName( int argc, char *argv[] );
void         readMenuItems( istream &menuFile );
void         printNormal( string str, int x, int y );
void         printBold( string str, int x, int y );
unsigned int runMenu( void );
void         writeBatchFile( unsigned int choice );

vector<menuItem> menuItems;
const int startX = 10;
const int startY = 30;

int main( int argc, char *argv[] )
{
    string fileName = getFileName( argc, argv );

    ifstream menuFile( fileName.c_str() );

    if ( menuFile == NULL )
    {
        cout << "File " << fileName << " can't be opened!" << endl;
        exit(1);
    }

    // Read the menu file into the menu array
    readMenuItems( menuFile );

    cls();

    // Get the user choice
    unsigned int choice = runMenu();

    // Write the batch to run the program
    writeBatchFile( choice );

    cls();

    return 0;
}

string getFileName( int argc, char *argv[] )
{
    // If no filename is on the command line, print program usage
    if ( argc < 2 )
    {
        cout << "Program usage: " << endl;
        cout << "  " << argv[ 0 ] << " filename" << endl;
        cout << "  Where filename is the menu file." << endl;

        exit(1);
    }


    // Otherwise, return the filename
    return argv[1];
}

void readMenuItems( istream &menuFile )
{
    menuItem itemRead;

    do
    {
        menuFile >> itemRead;
        menuItems.push_back( itemRead );
    } while ( ! menuFile.eof() );

    // Add the exit option to the menu
    menuItem item( "Exit menu", "", "", "" );
    menuItems.push_back( item );
}

unsigned int runMenu( void )
{
    // Print the menuitems on the screen
    for ( int count = 0; count < menuItems.size(); count++ )
    {
        printNormal( menuItems[ count ].getText(), startX + count, startY );
    }

    unsigned int currMenuChoice = 0;

    printBold( menuItems[ currMenuChoice ].getText(), startX + currMenuChoice, startY );

    bool done = false;

    // Loop until user chooses an option
    while ( ! done )
    {
        while ( ! isKeyReady() );

        WORD key = getKey();

        // Which key did the user press?
        switch ( key.high )
        {
            case UP:
                printNormal( menuItems[ currMenuChoice ].getText(), startX + currMenuChoice, startY );
                currMenuChoice = currMenuChoice - 1;
                if ( currMenuChoice == -1 )
                    currMenuChoice = menuItems.size() - 1;
                printBold( menuItems[ currMenuChoice ].getText(), startX + currMenuChoice, startY );
                break;

            case DOWN:
                printNormal( menuItems[ currMenuChoice ].getText(), startX + currMenuChoice, startY );
                currMenuChoice = ( currMenuChoice + 1 ) % menuItems.size();
                printBold( menuItems[ currMenuChoice ].getText(), startX + currMenuChoice, startY );
                break;

                default:
                if ( key.low == ENTER )
                    done = true;
                break;
        }
    }

    return currMenuChoice;
}

void printNormal( string str, int x, int y )
{
    print( str.c_str(), RED, x, y );
}

void printBold( string str, int x, int y )
{
    print( str.c_str(), WHITE, x, y );
}

void writeBatchFile( unsigned int choice )
{
    ofstream outFile("menurun.bat");

    outFile << "@echo off" << endl;

    // If the choice is exit, run no programs
    //  Otherwise, write the program info to the batch file
    if ( choice != ( menuItems.size() - 1 ) )
    {
        outFile << "cd " << menuItems[ choice ].getDirectory() << endl;
        outFile << menuItems[ choice ].getfileName();
        outFile << " " << menuItems[ choice ].getParams() << endl;
        outFile << "cd %1" << endl;
        outFile << "menu.bat" << endl;
    }

    outFile.close();
}
