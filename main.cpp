//Kingdoms of Impreca v.01

#include <iostream>
#include <fstream> //needed for file in/out
#include <stdlib.h> //for get pass function
#include <cstring> //needed to get strcmp to work
#include <time.h>
using namespace std;

//Global Variables

string name;
string password;
string tempstr; //catch all for temp strings
int tempnum; //catch all for the menu selections
int gold = 200;

//lottery variables
int lotterynum;
int jackpot;
string lotteryfile = "lottery";
//============================

//Functions

void lottery()
{

system("clear");
ifstream inputfile(lotteryfile.c_str(),fstream::in);//opens lottery file
inputfile >> lotterynum;
inputfile >> jackpot;
inputfile.close();

cout << "Lottery of the Kingdoms\n";
cout << "Your Gold: " << gold << endl;
cout << "Current Jackpot: "<< jackpot << endl;
cout << "It costs 100 gold to take a guess\n";
cout << "The lottery number is between 100 - 999\n";
cout << "press 1 to take a guess or 2 to go back\n";

cin >> tempnum;

switch(tempnum)
{
case 1:
if (gold < 100)
{
cout << "\nyou do not have enough gold\n";
system("sleep 2");
return;
}
else
{
gold = gold - 100;
cout << "your guess: ";
cin >> tempnum;
if (tempnum == lotterynum)
{
gold = gold + jackpot;
jackpot = 5000;

srand (time(NULL));
tempnum = rand() % 999 + 100;
lotterynum = tempnum;
ofstream outputfile(lotteryfile.c_str(),fstream::out);//opens lottery file
outputfile << lotterynum << endl;
outputfile << jackpot;
outputfile.close();
cout << "\nCongratulations!! You won the jackpot!!\n";
system("sleep 2");
}
else
{
cout << "\nsorry you didnt guess correctly\n";
system("sleep 2");
return;
}
case 2:
return;

default:
return;
}
}
}

void menu()
{
menu_start:
system("clear");// clear screen
cout << "Main Menu\n\n";
cout << "1) Build Buildings 2) Generate Resources 3)Market\n";
cout << "4) Recruit Heroes  5) Messages           6)News\n";
cout << "7) Lottery         8) Diplomacy          9)Status\n";
cout << "0) quit";

cout << "\n\n\n\nSelect 1-9 ";
cin >> tempnum;

switch(tempnum)
{
case 1: 
cout << "\nbuilding not yet implimented\n";
system("sleep 2");
goto menu_start;
case 2:
cout << "\nresources not yet implimented\n";
system("sleep 2");
goto menu_start;
case 3:
cout << "\nmarket not yet implimented\n";
system("sleep 2");
goto menu_start;
case 4:
cout << "\nrecruiting not yet implimented\n";
system("sleep 2");
goto menu_start;
case 5:
cout << "\nmessages not yet implimented\n";
system("sleep 2");
goto menu_start;
case 6:
cout << "\nnews not yet implimented\n";
system("sleep 2");
goto menu_start;
case 7:
lottery();
goto menu_start;
case 8:
cout << "\ndiplomacy not yet implimented\n";
system("sleep 2");
goto menu_start;
case 9:
cout << "\nstatus not yet implimented\n";
system("sleep 2");
goto menu_start;
case 0: exit(0);
default: 
cout << "\nPlease press 1-8\n";
system("sleep 2");
goto menu_start;
}
}


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
exit(0);//end program if too many tries occurs
}

else
{
string tempstr = getpass("Enter Password: ");//password masking
if (strcmp(tempstr.c_str(), password.c_str()) == 0) //c.str() to convert strings for comparing
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
return;
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
//================================================

int main()

{
intro();
menu();
quit:
return 0;
}
