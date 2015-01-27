//Kingdoms of Impreca v.01

#include <iostream>
#include <fstream> //needed for file in/out
#include <stdlib.h> //for get pass function
#include <cstring> //needed to get strcmp to work
#include <string>
#include <time.h>
using namespace std;


//Global Variables

string tempstr; //catch all for temp strings
int tempnum; //catch all for the menu selections

char* date_time;

struct tm current;

void get_time()
{
time_t now = time(0); // the time right now
date_time = ctime(&now); //update the time
time(&now);//get current time
current = *localtime(&now);
return;
}


//player variables
string name;
string password;
int ts_year = 0; //timestamp for year
int ts_month = 0;//timestamp for month
int ts_day = 0; //timestamp for day
int turns = 5000;
int food = 1000;
int wood = 1000;
int stone = 1000;
int iron = 1000;
int gold = 1000;

//message variables

string news = ".news";
string space = " ";
string message = "";
string nl = "\n";

//lottery variables
int lotterynum;
int jackpot;
string lotteryfile = "lottery";

//world news variables

string worldnews = "world_news";

//market variables

string marketfile = "market";
int market_food;
int market_wood;
int market_stone;
int market_iron;
int market_gold;

//============================

//Functions

void market_save()//mquick
{
ofstream outputfile(marketfile.c_str(),fstream::in);//opens file with the users name for input
outputfile << market_food << endl;
outputfile << market_wood << endl;
outputfile << market_stone << endl;
outputfile << market_iron << endl;
outputfile << market_gold << endl;
outputfile.close();
}




void send_message()
{

        cout << "\n" << "which kingdom do you want to send a message? ";

        cin >> tempstr;

        string file = tempstr + news;

        string nl = "\n";

        ifstream openfile(file.c_str());

        if (openfile.is_open())
{

        openfile.close();

        cout << "\n" << "Please type your message for " << tempstr << " below. Remember do not hit return until you are finished";

        cin.ignore();

        getline(cin, message);

        ofstream openfile(file.c_str(),fstream::app);

        time_t now = time(0); // the time right now

        date_time = ctime(&now); //update the time

        openfile << date_time + space + message + nl;

        openfile.close();

        system("sleep 1");

        cout << "\nMessage sent\n";

        system("sleep 2");

        return;
}

        else
                {
                        cout << "\nThat user does not exist\n";

                        system("sleep 1");
                        return;
                }

return;

}

void read_message()
{
readmessage_start:
system("clear");
string file = name + news;
ifstream openfile(file.c_str());
while (!openfile.eof())
{
getline(openfile, message);
cout << message << endl;
}

openfile.close();
cout << "\n\n\nPress 1 to return ";

cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto readmessage_start;
        }

switch(tempnum)
{
case 1: return;
default: return;
}
}

void messaging()
{
messages_start:
system("clear");
cout << "The Kingdoms Messaging System\n\n";
cout << "Press 1 to send message\n";
cout << "Press 2 to read messages\n";
cout << "Press 0 to return\n";

cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto messages_start;
        }

switch(tempnum)
{
case 1: send_message();
return;
case 2: read_message();
return;
case 0: return;
default: return;
}
}

void world_news()
{
worldnews_start:
system("clear");
string file = "world_news";
ifstream openfile(file.c_str());
while (!openfile.eof())
{
getline(openfile, message);
cout << message << endl;
}

openfile.close();
cout << "\n\n\nPress 1 to return ";

cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto worldnews_start;
        }

switch(tempnum)
{
case 1: return;
default: return;
}
}

void save()
{
cin.ignore();//flush the buffer
ofstream openfile(name.c_str(),fstream::out);//opens file with the users name for input
openfile << name << endl; //put name into file then end line
openfile << password << endl;
openfile << ts_year << endl; //timestamp for year
openfile << ts_month << endl;//timestamp for month
openfile << ts_day << endl; //timestamp for day
openfile << turns << endl;
openfile << food << endl;
openfile << wood  << endl;
openfile << stone  << endl;
openfile << iron  << endl;
openfile << gold  << endl;
openfile.close(); //close the file
return;
}


void market_buy()
{
cout << "\n1) Food  2) Wood  3)Stone  4)Iron 0)Cancel\n";
mbuy_start:
cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto mbuy_start;
        }
switch(tempnum)
{
case 1:cout << "\nHow much food do you want to buy? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto mbuy_start;
        }

if (tempnum > market_food)
{
cout << "\nThe market does not have enough food\n";
system("sleep 2");
return;
}
else if ((tempnum * 3) > gold)
{
        cout << "\nYou do not have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold + (tempnum * 3);
        gold = gold - (tempnum * 3);
        food = food + tempnum;
        market_food = market_food - tempnum;
        save();
        market_save();
        return;
        }

case 2:cout << "\nHow much wood do you want to buy? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto mbuy_start;
        }

if (tempnum > market_wood)
{
cout << "\nThe market does not have enough wood\n";
system("sleep 2");
return;
}
else if ((tempnum * 5) > gold)
{
        cout << "\nYou do not have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold + (tempnum * 5);
        gold = gold - (tempnum * 5);
        wood = wood + tempnum;
        market_wood = market_wood - tempnum;
        save();
        market_save();
        return;
        }

case 3:cout << "\nHow much stone do you want to buy? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto mbuy_start;
        }

if (tempnum > market_stone)
{
cout << "\nThe market does not have enough stone\n";
system("sleep 2");
return;
}
else if ((tempnum * 10) > market_gold)
{
        cout << "\nYou donot have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold + (tempnum * 10);
        gold = gold - (tempnum * 10);
        stone = stone + tempnum;
        market_stone = market_stone - tempnum;
        save();
        market_save();
        return;
        }

case 4:cout << "\nHow much iron do you want to buy? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto mbuy_start;
        }

if (tempnum > market_iron)
{
cout << "\nThe market does not have enough iron\n";
system("sleep 2");
return;
}
else if ((tempnum * 20) > market_gold)
{
        cout << "\nYou do not have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold + (tempnum * 20);
        gold = gold - (tempnum * 20);
        iron = iron + tempnum;
        market_iron = market_iron - tempnum;
        save();
        market_save();
        return;
        }
default: cout << "\nPlease pick from 1-4\n";
system("sleep 2");
goto mbuy_start;
}
}
void market_sell()
{
cout << "\n1) Food  2) Wood  3)Stone  4)Iron 0)Cancel\n";
msell_start:
cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto msell_start;
        }

switch(tempnum)
{
case 1:cout << "\nHow much food do you want to sell? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          return;
        }

if (tempnum > food)
{
cout << "\nYou dont have enough food\n";
system("sleep 2");
return;
}
else if (tempnum > market_gold)
{
cout << "\nThe market does not have enough gold\n";
system("sleep 2");
return;
}
else 
{
market_gold = market_gold - tempnum;
gold = gold + tempnum;
food = food - tempnum;
market_food = market_food + tempnum;
save();
market_save();
return;
}

case 2:cout << "\nHow much wood do you want to sell? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto msell_start;
        }

if (tempnum > wood)
{
cout << "\nYou dont have enough wood\n";
system("sleep 2");
return;
}
else if ((tempnum * 2) > market_gold)
{
        cout << "\nThe market does not have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold - (tempnum * 2);
        gold = gold + (tempnum * 2);
        wood = wood - tempnum;
        market_wood = market_wood + tempnum;
        save();
        market_save();
        return;
        }

case 3:cout << "\nHow much stone do you want to sell? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto msell_start;
        }

if (tempnum > stone)
{
cout << "\nYou dont have enough stone\n";
system("sleep 2");
return;
}
else if ((tempnum * 5) > market_gold)
{
        cout << "\nThe market does not have enough gold\n";
        system("sleep 2");
        goto msell_start;
        }
        else 
        {
        market_gold = market_gold - (tempnum * 5);
        gold = gold + (tempnum * 5);
        stone = stone - tempnum;
        market_stone = market_stone + tempnum;
        save();
        market_save();
        return;
        }

case 4:cout << "\nHow much iron do you want to sell? ";
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto msell_start;
        }

if (tempnum > iron)
{
cout << "\nYou dont have enough iron\n";
system("sleep 2");
return;
}
else if ((tempnum * 10) > market_gold)
{
        cout << "\nThe market does not have enough gold\n";
        system("sleep 2");
        return;
        }
        else 
        {
        market_gold = market_gold - (tempnum * 10);
        gold = gold + (tempnum * 10);
        iron = iron - tempnum;
        market_iron = market_iron + tempnum;
        save();
        market_save();
        return;
        }

case 0: return;
default: cout << "\nPlease press 1,2,3,4 or 0\n";
goto msell_start;
}
}
void market() //quick
{
market_start:
system("clear");
cout << "The Kingdoms Market Place\n\n";
cout << "Your Resources: Food: " << food << " Wood: " << wood << endl;
cout << "               Stone: " << stone << " Iron: " << iron << endl;
cout << "                Gold: " << gold << endl;

cout << "\n\nFood costs 3 gold to buy and sells for 1 gold\n";
cout << "Wood costs 5 gold to buy and sells for 2 gold\n";
cout << "Stone costs 10 gold to buy and sells for 5 gold\n";
cout << "Iron costs 20 gold to buy and sells for 10 gold\n\n\n";

ifstream inputfile(marketfile.c_str(),fstream::in);//opens file with the users name for input
inputfile >> market_food;
inputfile >> market_wood;
inputfile >> market_stone;
inputfile >> market_iron;
inputfile >> market_gold;
inputfile.close();

cout << "Market Food: " << market_food << endl; 
cout << "Market Wood: " << market_wood << endl;
cout << "Market Stone: " << market_stone << endl;
cout << "Market Iron: " << market_iron << endl;
cout << "Market Gold: " << market_gold<< endl;

cout << "\n\n1) Buy   2) Sell    0)Return\n";

cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto market_start;
        }

switch(tempnum)
{
case 1:
market_buy();
goto market_start;

case 2:
market_sell();
goto market_start;

case 0: return;
default: cout << "\nPlease press 1,2, or 0\n"; 
goto market_start;
}

}



void new_turns()
{
get_time();

int tempyear = current.tm_year;
int tempmonth = current.tm_mon;
int tempday = current.tm_mday;

if (tempyear > ts_year)
{
cout << "\nYou gain your next 500 daily turns\n";
system("sleep 3");
ts_year = tempyear;
ts_month = tempmonth;
ts_day = tempday;
turns = turns + 500; 
save();
return;
}
else if (tempmonth > ts_month)
{
cout << "\nYou gain your next 500 daily turns\n";
system("sleep 3");
ts_year = tempyear;
ts_month = tempmonth;
ts_day = tempday;
turns = turns + 500;
save();
return;
}
else if (tempday > ts_day)
{
cout << "\nYou gain your next 500 daily turns\n";
system("sleep 3");
ts_year = tempyear;
ts_month = tempmonth;
ts_day = tempday;
turns = turns + 500;
save();
return;
}
else
{
cout << "\nNew turns available at midnight\n";
system("sleep 2");
return;
}
}

void status()
{
status_start:
system("clear");
cout << "Your Kingdom Status:\n\n";
cout << "Turns: " << turns <<  " Food: " << food << " Wood: " << wood <<" Stone: " << stone << " Iron: " << iron << " Gold: " << gold << endl;

cout << "\n\n\nPress 1 to return ";

cin >> tempnum;
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto status_start;
        }

switch(tempnum)
{
case 1: return;
default: return;
}
}
void lottery()
{
lottery_start:
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
if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto lottery_start;
        }
else
{
switch(tempnum)
{
case 1: 
if (gold < 100)
{
cout << "\nyou do not have enough gold\n";
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


ofstream newsfile(worldnews.c_str(),fstream::out);//opens world news file
tempstr = " jackpot was won by ";
newsfile << date_time << tempstr << name << nl;
newsfile.close();

cout << "\nCongratulations!! You won the jackpot!!\n";
save(); 
system("sleep 2");
}
else
{
cout << "\nsorry you didnt guess correctly\n";
save();
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
}

void menu()
{
menu_start:
system("clear");// clear screen
cout << "Main Menu\n\n";
cout << "1) Build Buildings 2) Generate Resources 3)Market\n";
cout << "4) Recruit Heroes  5) Messages           6)World News\n";
cout << "7) Lottery         8) Diplomacy          9)Status\n";
cout << "0) Quit";

cout << "\n\n\n\nSelect 1-9 ";

cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto menu_start;
        }


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
market();
goto menu_start;
case 4:
cout << "\nrecruiting not yet implimented\n";
system("sleep 2");
goto menu_start;
case 5:
messaging();
goto menu_start;
case 6:
world_news();
goto menu_start;
case 7:
lottery();
goto menu_start;
case 8:
cout << "\ndiplomacy not yet implimented\n";
system("sleep 2");
goto menu_start;
case 9:
status();
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
inputfile >> ts_year; //timestamp for year
inputfile >> ts_month;//timestamp for month
inputfile >> ts_day; //timestamp for day
inputfile >> turns;
inputfile >> food;
inputfile >> wood;
inputfile >> stone;
inputfile >> iron;
inputfile >> gold;
inputfile >> gold;
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
name_start:
system("clear"); // clear screen
cout << "Welcome lets get your information\n";
cout << "lets start with your kingdom name with no spaces\n";
cin >> name;

ifstream openfile(name.c_str());

if (openfile.is_open())//check to make sure no one else already has this user account
{
cout << "\nThis user already exists, please pick a different name\n";
system("sleep 2");
goto name_start;
}

else
{

cout << "ok your kingdom is: " << name;
cout << "\nand your password\n";
cin >> password;
cout << "ok and your password will be: " << password;

char* date_time;

struct tm current;

        time_t now = time(0); // the time right now

        date_time = ctime(&now); //update the time

time(&now);//get current time

current = *localtime(&now);

ts_year = current.tm_year;
ts_month = current.tm_mon;
ts_day = current.tm_mday;

cin.ignore();//flush the buffer
ofstream openfile(name.c_str(),fstream::app);//opens file with the users name for input
openfile << name << endl; //put name into file then end line
openfile << password << endl;
openfile << ts_year << endl; //timestamp for year
openfile << ts_month << endl;//timestamp for month
openfile << ts_day << endl; //timestamp for day
openfile << turns << endl;
openfile << food << endl;
openfile << wood  << endl;
openfile << stone  << endl;
openfile << iron  << endl;
openfile << gold  << endl;
openfile.close(); //close the file

string file = name + news;//create the users news file
ofstream newsfile(file.c_str(),fstream::app);
newsfile.close();

ofstream worldnewsfile(worldnews.c_str(),fstream::out);//opens world news file
tempstr = " A new kingdom is born:  ";
worldnewsfile << date_time << tempstr << name << nl;
worldnewsfile.close();

system("sleep 2");
cout << "\nUser Created\n";
return;
}
}

void intro()
{
system("clear"); //clear the screen at start
cout << "Welcome to Kingdoms of Impreca v.01\n\n\n\n";
cout << "If you are new here press 1, else press 2 to login\n";

intro:
cin >> tempnum;

if(cin.fail())
        {
          cin.clear();
          cin.ignore();
          cout << "\nIncorrect entry. Try again: \n";
          system("sleep 2");
          goto intro;
        }


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
new_turns();
menu();
quit:
return 0;
}

