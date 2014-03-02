SET CODEDIRECTORY=%CD%
cd "%CODEDIRECTORY%"/bin
del prog.exe
cd "%CODEDIRECTORY%"
gcc .\lib\*.c -o "%CODEDIRECTORY%"\bin\prog.exe -I "%CODEDIRECTORY%"\include\
cd \ 
cd "%CODEDIRECTORY%"\bin\
prog
cd ..
