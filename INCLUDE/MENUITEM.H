// MENUITEM.H
//  Header file for the menuitem class
#if ! defined ( MENUITEM_H )
#define MENUITEM_H

#include <string>
#include <iostream>

class menuItem
{
        friend istream &operator>> (istream &input, menuItem &item );
        friend ostream &operator<< (ostream &output, const menuItem &item );
    public:
        menuItem( string txt, string file, string param, string dir );
        menuItem() {};

        string getText( void );
        string getfileName( void );
        string getParams( void );
        string getDirectory( void );
    private:
        string text;      // Text to display on the menu
        string fileName;  // Filename of executable
        string params;    // Startup parameters
        string directory; // Directory to run executable from
};

#endif

