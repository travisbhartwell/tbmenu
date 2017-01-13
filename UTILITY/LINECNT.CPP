// LINECNT.CPP
// Counts the number of non-blank lines in a file

#include <iostream>
#include <fstream>
#include <string>

int countLines( istream &inFile );

int main( int argc, char *argv[] )
{
    string fileName;

    if ( argc < 2 )
    {
        cout << "Program usage: " << endl;
        cout << argv[0] << " [fileName] " << endl;
    }
    else
    {
        fileName = argv[1];

        ifstream inFile( fileName.c_str() );

        int lines = countLines( inFile );
        cout << "Number of non-blank lines in " << fileName << " : ";
        cout << lines << endl;

        inFile.close();
    }
    return 0;
}

int countLines( istream &inFile )
{
    char line[1024];
    int lineSize = 1024;
    int count = 0;

    while ( inFile.getline( line, lineSize ) )
    {
        if ( line[0] != '\0' )
        {
            count++;
        }
    }

    return count;
}
