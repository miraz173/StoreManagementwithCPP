# Store Database Management System
user--> login, register, exit
all the variable must be in separate file to make the program behave properly. Because program will store each --> line <-- in separate string variables. Will be reading in lines because variables might be multi-word string and "file >> string_variable"
reads only one word.

to eliminate the program: taskkill /F /IM "main.exe" /T

to read multi-word string from txt file and store it to string_variable, use: getline(ifstream_File, string_variable);
to read multi-word string from txt file and store it to char_variable[num], use: ifstream_File.getline(char_variable, num, '\n');