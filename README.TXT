README.TXT                                                   January 12, 1999

        This package contains the source code and binaries for a 'beta'
release of a menu program that I am working on.  At this stage, it was
only a "try it to see if it works" kind of thing.   This is only a shadow
of what I want this program to be.

WHY I WROTE THE MENU PROGRAM
    I have an old 386 laptop that I still use.  I have Windows for Workgroups
installed on it, but I often just stay at the DOS prompt.  I'm a command-line
kind of guy myself, but my family also uses my laptop.  I had some old games
and things on it that they didn't know how to run.  So, I thought, I need
a menu program.  I was home from college at the time and didn't have access
to the Internet to download, so I thought I would write a simple one.  Thus,
my menu program was born after a few hours of coding and design.

WHAT IS INCLUDED IN THE PACKAGE
     With this package, I include all source code that I wrote, not only for
the menu program, but for the test programs and small utilities that I used.
There is no documentation as of yet, but I believe it is simple enough to not
need any at this stage.  If you do have any questions, please e-mail me at
the address at the end of this document.

INSTALLING
    Extract the files into a temorary directory, making sure to re-create the
directory structure ( using the command line option -d on PKUNZIP or having
the "Use Folder Names" option checked in WinZip.  Then, run the batch file
instmenu.bat included in the archive and it will set up the proper
directories amd copy the proper files to them.  Then, it will run the MNUMAKE
program to create your menu file.  After that, run MENU.BAT
to execute the menu program.

RUNNING THE MENU PROGRAM

        To run the menu program, first change to the menu directory -- by
default, C:\MENU, and run MENU.BAT.  That's all there is to it.

HOW IT ALL WORKS
    It is all fairly simple.  To be honest, I got the concept of how to work
this from some shareware menu programs I used around five years ago.  Most of
the code is straight forward.  The menu data is loaded into an array from the
menu file.  When the user selects a menu option, it creates a batch file that
changes to the appropriate directory, runs the application with the parameters
listed, and then changes back to the menu directory.  The MENU.BAT file is
called again, completing the loop.

COMPILING
    I used the DJGPP compiler ( perhaps the best DOS compiler around ) to
make the menu program.  When I started this on my laptop, I didn't have all
of the documentation, so I wasn't aware of keyboard and screen functions to
do what I used to do in Turbo C++, so I wrote my own.  That will probably
change.  I would include make files, but since I normally use RHIDE, I really
don't yet know how they work.  I will include comments in each main program
file which files need to be compiled with it.

PLANS FOR THE FUTURE
      The menu program is going to be completely re-done in the future.
One of the first things to be done will make it completely object-oriented.
I want it to be based on a scripting language -- i.e., the menu file will
be actually a script which will allow for input and calculations and so forth.
I am still learning about language interpreters, so that may come in a while.
Also, I will add support for a mouse and make it all event driven.   I would
like to port it to Linux, as I will be installing Linux on my machine here in
a few weeks.  Basically there will be a lot of things I'll have to teach
myself in the process of writing this.

OPEN SOURCE
     I release this as open source.  Any one can use my code or my program
however they like.  All I ask is that you let me know how it has helped you.
I would also like any suggestions or ideas on how to improve my code or how to
implement a scripting language and event handler.  Please send me any changes
you have made to my code, I would appreciate it!

Travis B. Hartwell
Travis.Hartwell@usu.edu
