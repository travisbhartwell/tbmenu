@echo off
md c:\menu
xcopy . /s /e c:\menu
cd c:\menu
c:\menu\utility\mnumake.exe c:\menu\menu
@echo Your menu is now ready!  Hit any key to run the menu or press
@echo CONTROL-C to exit!
pause
call menu.bat
