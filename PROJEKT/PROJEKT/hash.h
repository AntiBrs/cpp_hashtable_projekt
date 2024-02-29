#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include "lista.h"
#include<Windows.h>
#include <fstream>
using namespace std;

const int N = 10000;//10 000 szoba vanl

extern class hash_table
{
public:
    unsigned int key;//hasitokulcs
    string name;//nev valtozo  (a nev lehet barmilyen karakterlanc billentyuzetrol)
    LinkedList* lista;//lancolt lista ami az adatokat tarolja
    hash_table();//konstruktor
    ~hash_table();//destruktor
    unsigned int hash(const string& String);//karakterlanc szerinti hasito fuggveny
    unsigned int hashnr(int Number);//szam szerinti hasito fuggveny
    void insert(string string);//elem beillesztese, szukseges a neve(egy karakterlanc, ket szo kozotte egy space idealis esetben)
    void reservation_insert_FILE(const char* FILENAME);//fajlbol olvasva nev(karakterlanc) szerinti hasitassal valo beillesztes
    void reservation_insert_FILE2(const char* FILENAME);//fajlbol olvasva szobaszam(szam) szerinti hasitassal valo beillesztes
    void print(int number);//egy szam altal azonositott elem minden adatanak kiiratasa
    void print(string string);//egy karakterlanc szrint azonositott elem minden adatanak kiiratasa
    void printALL_AllData();//minden ugyfel minden adatanak kiiratasa
    void listALL();//listazas
    bool check(string string);//benne van e az adott karakterlancal rendelkezo elem
    bool check(int number);//benne vane az adott szammal rendelkezo elem
    void rmv(string string);//torles karakterlanc szerint
};
#endif
