#include <string>
#include <iostream>
#include "..\include\menuitem.h"

menuItem::menuItem( string txt, string file, string param, string dir )
        : text( txt ), fileName( file ), params( param ), directory( dir ) {}

string menuItem::getText( void )
{
    return text;
}

string menuItem::getfileName( void )
{
    return fileName;
}

string menuItem::getParams( void )
{
    return params;
}

string menuItem::getDirectory( void )
{
    return directory;
}

istream &operator>> ( istream &input, menuItem &item )
{
    // Temporary buffer to store strings
    char line[80];

    input.getline( line, 80 );
    item.text = line;

    input.getline( line, 80 );
    item.fileName = line;

    input.getline( line, 80 );
    item.params = line;

    input.getline( line, 80 );
    item.directory = line;

    return input;
}

ostream &operator<< ( ostream &output, const menuItem &item )
{
    output << item.text << endl;
    output << item.fileName << endl;
    output << item.params << endl;
    output << item.directory << endl;

    return output;
}

