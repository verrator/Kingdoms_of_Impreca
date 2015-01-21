

//Kingdoms of Impreca v.01

#include <iostream>
#include <fstream> //needed for file in/out
#include <stdlib.h> //for get pass function

#include <cstring> //needed to get strcmp to work

using namespace std;

//Global Variables

string name;
string password;
int num_select; //catch all for the menu selections

void login()
{
}

void new_user()
{
system("clear"); // clear screen
cout << "Welcome lets get your information\n";
cout << "lets start with your kingdom name with no spaces\n";
cin >> name;
cout << "ok your kingdom is: " << name;
cout << "\nand your password\n";
cin >> password;
cout << "ok and your password will be: " << password;

cin.ignore();//flush the buffer
ofstream openfile(name.c_str(),fstream::app);//opens file with the users name for input
openfile << name << endl; //put name into file then end line
openfile << password << endl;
openfile.close(); //close the file
system("sleep 2");
cout << "\nUser Created\n";
}

void intro()
{
system("clear"); //clear the screen at start
cout << "Welcome to Kingdoms of Impreca v.01\n\n\n\n";
cout << "If you are new here press 1, else press 2 to login\n";

intro:
cin >> num_select;

switch (num_select)
{
 case 1:
        new_user();
        break;
 case 2:
        login();
       break;

 default:
        cout << "I said 1 or 2\n";
        goto intro;
}


}
int main()
{
intro();
return 0;
}


