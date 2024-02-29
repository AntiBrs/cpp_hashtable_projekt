#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;

class Node//ugyfel
{
public:
    string name;//nev
    Node* next;//kovetkezo ugyfelre mutato pointer
    unsigned int room_nr;//szobaszam
    unsigned int nr_persons;//szobaban tartozkodo szemelyek szama
    string tel;//telefonszam
    string email;//email
    unsigned int date1, date2;//bejelentkezes es kijelentkezesi datum
    bool prepaid;//fizetes ellenorzo(fizetve volt/utolag lesz fizetve)
    Node(string firstname_lastname, unsigned int room_number, unsigned int nr_of_persons, string email_adress, string telephine_number, unsigned int date_of_check_in, unsigned int date_of_checkout, bool is_it_paid);
    //konstruktor, ugyfel minden adata szukseges az adott sorrendben
};

class LinkedList
{
public:
    Node* head;//lista fejere mutato pointer
    LinkedList();//konstruktor
    ~LinkedList();//destruktor
    void insert(string firstname_lastname, unsigned int room_number, unsigned int nr_of_persons, string email_adress, string telephone_number, unsigned int date_of_check_in, unsigned int date_of_checkout, bool is_it_paid);
    //beillesztes,minden adat szukseges
    void displayALL_name();//osszes nev kiiratasa
    void displayALL_name_date_roomnr();//osszes nev kiiratasa a fogalals periodusaval es szobaszammal egyutt 
    void displayALL_custumer_data();//minden ugyfel adatainak kiiratasa
    void display_custumer_data(string name);//foglalas adatainak nev szerintikeresese es kiiratasa
    void display_custumer_data(int roomnr);//foglalas adatainak szobaszam szerintikeresese es kiiratasa
    bool search(string name);//nev szerinti kereses
    bool search2(int roomnr);//szobaszam szerinti kereses
    void remove(string name);//torles a nev szerint
};

#endif

