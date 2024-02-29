#include <iostream>
#include <string>
#include "lista.h"
#include<Windows.h>
#include <fstream>
#include "hash.h"
#include<conio.h>


using namespace std;
string takePasswdFromUser()
{
    HANDLE hStdInput
        = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdInput, &mode);
    SetConsoleMode(
        hStdInput,
        mode & (~ENABLE_ECHO_INPUT));
    string ipt;
    getline(cin, ipt);
    cout << endl;
    SetConsoleMode(hStdInput, mode);
    return ipt;
}
void ret()
{
    string tmp;
    cout << endl;
    cout << endl;
    cout << "Press ENTER to get back to the menu" << endl;
    getline(cin, tmp);
}
int main()
{
    
  
   hash_table hotel,hotel2;//nev es szam szerinti hasitas
   hotel.reservation_insert_FILE("hotel.in");
   hotel2.reservation_insert_FILE2("hotel.in");
   string passwd="adatszerkezet",input,tmp;
   int k = 3,ido=5000;
   cout << "                                                                    WELCOME" << endl;
   while (1)
   {
       cout << "Password: ";
       input = takePasswdFromUser();
       if (!input.compare(passwd))
       {
           cout << "~Successful login!~ Press ENTER to get to the MENU" << endl;
           getline(cin, tmp);
           break;
       }
       else
       {
           cout << "Incorrect Password! remaining tries(" << k-1 << ")" << endl;
           k--;
       }
       if (k == 0)
       {
           system("cls");
           cout << endl << endl << endl << endl;
           cout << "                                                        System is locked!";
           cout << "~After some time you can try again..." << endl;
           Sleep(ido);
           ido *= 10;
           system("cls");
           k = 3;
       }

   }
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);//szinekert felelos kodsor
   int choice = 1;
   char cursor = '>';
   int szam;
   string nev, nev2;
   while (true) 
   {
       system("cls"); // clear screen
       cout << "~ Using the arrow keys choose an option and press ENTER ~\n\n\n\n";
       cout << "                                                                         MENU" << endl;
       cout << "                                                           -------------------------------------" << endl;
       cout << endl;     
       cout << ((choice == 1) ? cursor : '\t') << "                                                             List of the customers\n";
       cout << ((choice == 2) ? cursor : '\t') << "                                                             Data of customers(ALL)\n";
       cout << ((choice == 3) ? cursor : '\t') << "                                                             Search by name\n";
       cout << ((choice == 4) ? cursor : '\t') << "                                                             Search by room nr\n";
       cout << ((choice == 5) ? cursor : '\t') << "                                                             Delete customer data(name)\n";
       cout << ((choice == 6) ? cursor : '\t') << "                                                             Insert reservation\n";
       cout << ((choice == 7) ? cursor : '\t') << "                                                             EXIT\n";
       cout << "                                                          ---------------------------------------" << endl;
       cout << endl;


       char key = _getch(); //input

       switch (key) 
       {
       case 72: // up arrow
           if (choice > 1) choice--;
           break;
       case 80: // down arrow
           if (choice < 7) choice++;
           break;
       case 13: // enter
           switch (choice) 
           {
           case 1:
               system("cls");

               hotel.listALL();
               cout << endl;
               cout << endl;
               ret();
               break;
           case 2:
               system("cls");

               hotel.printALL_AllData();
               ret();
               break;
           case 3:
               system("cls");
               cout << endl << endl << endl << endl;
               cout << "> Type the name('firstname lastname')" << endl;
               cin >> nev;
               cin >> nev2;
               nev=nev + " " + nev2;
               hotel.print(nev);
               ret();
               getline(cin, tmp);
               break;
           case 4:
               system("cls");
               cout << endl << endl << endl << endl;
               cout << "> Type the room number you are searching for:" << endl;
               cin >> szam;
               hotel2.print(szam);
               ret();
               getline(cin, tmp);
               break;
           case 5:
               system("cls");
               cout << endl << endl << endl << endl;
               cout << "Type the name('firstname lastname')" << endl;
               cin >> nev;
               cin >> nev2;
               nev = nev + " " + nev2;
               hotel.rmv(nev);       
               cout <<"DONE" << endl;
               ret();
               getline(cin, tmp);
               break;
           case 6:
               system("cls");
               cout << endl << endl << endl << endl;
               cout << "(The inserted customer data can be searched by name only)" << endl;
               cout << "Type the name('firstname lastname')" << endl;
               cin >> nev;
               cin >> nev2;
               nev = nev + " " + nev2;
               hotel.insert(nev);
               cout << endl;
               cout << endl;
               ret();
               getline(cin, tmp);
               break;
           case 7:
               cout << endl;
               cout << "Bye,Bye :)";
               return 0;
               break;
           }
       }
   }

    return 0;
}