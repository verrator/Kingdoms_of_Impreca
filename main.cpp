//Kingdoms of Impreca v.01

#include <iostream>
#include <fstream> //needed for file in/out
#include <stdlib.h> //for get pass function

#include <cstring> //needed to get strcmp to work

using namespace std;

//Global Variables

string name;
string password;
string tempstr; //catch all for temp strings
int tempnum; //catch all for the menu selections


void login()
{
system("clear");//clear screen
cout << "username: ";
cin >> name;
ifstream inputfile(name.c_str(),fstream::in);//opens file with the users name for input
inputfile >> name;
inputfile >> password;
inputfile.close();

tempnum = 0;

pass:
if (tempnum == 3)
{
{
exit(0);//end program if too many tries occurs
}

else
{
cout << "\npassword: ";
cin >> tempstr;
}

if (tempstr == password)
{
cout << "\nLogin Successful\n";
system ("sleep 2");
return;
}
else tempnum = tempnum + 1;
{
cout << "\nwrong password\n";
goto pass;
}
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
cin >> tempnum;

switch (tempnum)
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
cout << "\nyou are now going to the main menu\n";
quit:
return 0;
}

