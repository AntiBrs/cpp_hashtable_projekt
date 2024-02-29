#include <iostream>
#include <string>
#include "lista.h"
#include<Windows.h>
#include <fstream>
#include "hash.h"
#include "feladat.h"
#include"bool.h"

using namespace std;

//bool reserved[Number_of_Rooms];//szobafoglalas ellenorzo tomb
unsigned int date = 20230501;

string email()
{
    string email;
    cout << "email adress: ";
    cin >> email;
    cout << endl;
    return email;
}


bool prepaid()
{
    string tmp;
    bool prepaid;
    cout << "Paid(yes/no): ";
    cin >> tmp;
    cout << endl;
    if (!tmp.compare("yes"))
    {
        prepaid = true;
    }
    else prepaid = false;
    return prepaid;
}
unsigned int date1()
{
    unsigned int date1;
    cout << "Date of check-in(yyyymmdd): ";
    cin >> date1;
    while (date1 < date || date1 >= date + 100)
    {
        cout << "!Error! -The reservation must start in the period of 2023 May" << endl;
        cout << "Date of check-in(yyyymmdd): ";
        cin >> date1;
    }
    cout << endl;
    return date1;
}

unsigned int date2()
{
    unsigned int date2;
    cout << "Date of check-out(yyyymmdd): ";
    cin >> date2;
    while (date2<date)
    {
        cout << "!Error! -The reservation must start in the period of 2023 May" << endl;
        cout << "Date of check-in(yyyymmdd): ";
        cin >> date2;
    }
    cout << endl;
    return date2;
}

unsigned int nr_persons()
{
    unsigned int nr_persons;
    cout << "Number of people in the room: ";
    cin >> nr_persons;
    cout << endl;
    return nr_persons;
}

unsigned int room_nr()
{
    unsigned int room_nr;
    cout << "Room number: ";
    cin >> room_nr;
    while (reserved[room_nr])
    {
        cout << "The room is already occupied" << endl;
        cout << "Room number: ";
        cin >> room_nr;
    }
    reserved[room_nr] = true;
    cout << endl;
    return room_nr;
}
string tel()
{
    string tel;
    cout  << endl;
    cout << "Phone number: ";
    cin >> tel;
    cout << endl;
    return tel;
}

  
string email_F(const char* FILENAME)
{
    fstream fin(FILENAME);
    string email;
    fin >> email;
    return email;
}


bool prepaid_F(const char* FILENAME)
{
    fstream fin(FILENAME);
    string tmp;
    bool prepaid;
    fin >> tmp;
    cout << endl;
    if (!tmp.compare("igen"))
    {
        prepaid = true;
    }
    else prepaid = false;
    return prepaid;
}
unsigned int date1_F(const char* FILENAME)
{
    fstream fin(FILENAME);
    unsigned int date1;
    fin >> date1;
    return date1;
}

unsigned int date2_F(const char* FILENAME)
{
    unsigned int date2;
    fstream fin(FILENAME);
    fin >> date2;
    return date2;
}

unsigned int nr_persons_F(const char* FILENAME)
{
    unsigned int nr_persons;
    fstream fin(FILENAME);
    fin >> nr_persons;
    return nr_persons;
}

unsigned int room_nr_F(const char* FILENAME)
{
    unsigned int room_nr;
    fstream fin(FILENAME);
    fin >> room_nr;
    reserved[room_nr] = true;
    return room_nr;
}
string tel_F(const char* FILENAME)
{
    string tel;
    fstream fin(FILENAME);
    cin >> tel;
    return tel;
}
string name(const char* FILENAME)
{
    string name,tmp2;
    fstream fin(FILENAME);
    fin >> name;
    fin >> tmp2;
    name = name + " " + tmp2;
    return name;
}



void reservation_insert_FILE0(const char* FILENAME)
{
    ifstream fin(FILENAME);
    int inputnr;
    fin >> inputnr;
    for (int i = 0; i < inputnr; i++)
    {
        unsigned int room_nr, nr_persons, date1, date2;
        string tel, email, tmp, tmp2, name;
        bool prepaid;
        fin >> name;
        fin >> tmp2;
        name = name + " " + tmp2;
        fin >> room_nr;
        reserved[room_nr] = true;
        fin >> nr_persons;
        fin >> date1;
        fin >> date2;
        fin >> tel;
        fin >> email;
        fin >> tmp;
        if (!tmp.compare("igen"))
        {
            prepaid = true;
        }
        else prepaid = false;
    }
}
