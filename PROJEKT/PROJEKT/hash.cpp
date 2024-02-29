#include <iostream>
#include <string>
#include "lista.h"
#include<Windows.h>
#include <fstream>
#include "hash.h"
#include "feladat.h"
#include "bool.h"

using namespace std;
    unsigned int hash_table:: hash(const string& name) 
    {
        unsigned long hash = 5381;
        int c = name.length();
        for (int i=0;i<c; i++)
        {
            hash = ((hash << 5) + hash) + c; 
        }
        return hash % (N/10);
    }
    unsigned int hash_table:: hashnr(int roomNumber) 
    {
        unsigned long hash = 0;
        hash += roomNumber * 2654435761;
        hash = hash % 1000;
        return (unsigned int)hash;
    }

    hash_table::hash_table()
    {
        lista = new LinkedList[N / 10];
    }
    hash_table::~hash_table()
    {
        for (int i = 0; i < N / 10; i++)
        {
            lista[i].~LinkedList();
        }
    }
    void hash_table::insert(string string)
    {
        lista[hash(string)].insert(string, room_nr(), nr_persons(), email(), tel(), date1(), date2(), prepaid());
    }
    void hash_table::print(int roomnr)
    {
        lista[hashnr(roomnr)].display_custumer_data(roomnr);
    }
    void hash_table::print(string name)
    {
        lista[hash(name)].display_custumer_data(name);
    }
    void hash_table::printALL_AllData()
    {
        for (int i = 0; i < N/10; i++)
        {
            lista[i].displayALL_custumer_data();
        }
    }
    void hash_table::listALL()
    {
        for (int i = 0; i < N / 10; i++)
        {
            lista[i].displayALL_name_date_roomnr();
        }
    }
    bool hash_table::check(string string)
    {
        return lista[hash(string)].search(string);
    }
    bool hash_table::check(int number)
    {
        return lista[hashnr(number)].search2(number);
    }
    void hash_table::rmv(string name)
    {
        lista[hash(name)].remove(name);
    }
    void hash_table::reservation_insert_FILE(const char* FILENAME)
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
            lista[hash(name)].insert(name, room_nr, nr_persons, email, tel, date1, date2, prepaid);
        }
    }
    void hash_table::reservation_insert_FILE2(const char* FILENAME)
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

            lista[hashnr(room_nr)].insert(name, room_nr, nr_persons, email, tel, date1, date2, prepaid);
        }
    }




