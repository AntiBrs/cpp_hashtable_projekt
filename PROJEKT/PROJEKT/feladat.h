#ifndef Feladat
#define Feladat
#include <iostream>
#include <string>
#include "lista.h"
#include<Windows.h>
#include <fstream>
#include "hash.h"
#include "lista.h"
using namespace std;

extern unsigned int date;//Foglalasok periodusanak kezdete
//----------------------------------------------BEOLVASASOK-------------------------------------------------------
unsigned int room_nr();//szobaszam beolvasas
unsigned int date1();//check in datum
unsigned int date2();//check out datum
bool prepaid();//fizetett e az illeto
unsigned int nr_persons();//szobaban tartozkodo szemelyek
string tel();//telefonszam
string email();//emailcim
#endif

