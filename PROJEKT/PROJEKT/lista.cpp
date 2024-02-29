#include <iostream>
#include <string>
#include "lista.h"
#include "feladat.h"
#include "bool.h"
using namespace std;

    Node::Node(string firstname_lastname, unsigned int room_number, unsigned int nr_of_persons, string email_adress, string telephine_number, unsigned int date_of_check_in, unsigned int date_of_checkout, bool is_it_paid)
    {
        name = firstname_lastname;
        room_nr = room_number;
        nr_persons = nr_of_persons;
        email = email_adress;
        date1 = date_of_check_in;
        date2 = date_of_checkout;
        tel = telephine_number;
        prepaid = is_it_paid;
        next = nullptr;
    }


    LinkedList::LinkedList()
    {
        head = nullptr;
    }
    LinkedList::~LinkedList()
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            Node* tmp = current_node;
            current_node = current_node->next;
            delete tmp; 
        }
    }


    void LinkedList:: insert(string firstname_lastname, unsigned int room_number, unsigned int nr_of_persons, string email_adress, string telephone_number, unsigned int date_of_check_in, unsigned int date_of_checkout, bool is_it_paid)
    {
        Node* new_node = new Node(firstname_lastname, room_number, nr_of_persons, email_adress, telephone_number, date_of_check_in, date_of_checkout, is_it_paid);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            Node* current_node = head;
            while (current_node->next != nullptr)
            {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
        new_node->name = firstname_lastname;
        new_node->room_nr = room_number;
        new_node->nr_persons = nr_of_persons;
        new_node->email = email_adress;
        new_node->tel = telephone_number;
        new_node->date1 = date_of_check_in;
        new_node->date2 = date_of_checkout;
        new_node->prepaid = is_it_paid;
    }

    void LinkedList::displayALL_name()
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            cout << current_node->name << endl;
            current_node = current_node->next;
        }
    }
    void LinkedList::displayALL_name_date_roomnr()
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            cout << current_node->name << ": ";
            cout << current_node->date1 << "    " << current_node->date2;
            cout << "       Room:" << current_node->room_nr << endl;
            current_node = current_node->next;
        }
    }

    bool LinkedList::search(string name)
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            if (!current_node->name.compare(name))
            {
                return true;
            }
            current_node = current_node->next;
        }
        return false;
    }
    bool LinkedList::search2(int roomnr)
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            if (roomnr==current_node->room_nr)
            {
                return true;
            }
            current_node = current_node->next;
        }
        return false;
    }
    void LinkedList::displayALL_custumer_data()
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            //cout << "\033[1;46m";
            cout << "                                   --------------------------Custumer Information--------------------------" << endl;
            cout << "                                 > Name: " << current_node->name << endl;
            cout << "                                 > Roomm number:  " << current_node->room_nr << endl;
            cout << "                                 > email adress:  " << current_node->email << endl;
            cout << "                                 > Telephone number:   " << current_node->tel << endl;
            cout << "                                 > Date of checking in and out: " << current_node->date1 << "   ->     " << current_node->date2 << endl;
            cout << "                                 > Number of people staying in the room: " << current_node->nr_persons << endl;
            if(current_node->prepaid)cout << "                                 > Paid: Yes" << endl;
            else cout << "                                 > Paid: No" << endl;
            cout << "                                   ------------------------------------------------------------------------" << endl;
            current_node = current_node->next;
        }
    }

    void LinkedList::display_custumer_data(string name)
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            if (!current_node->name.compare(name))
            {
                cout << "                                   --------------------------Custumer Information--------------------------" << endl;
                cout << "                                 > Name: " << current_node->name << endl;
                cout << "                                 > Roomm number:  " << current_node->room_nr << endl;
                cout << "                                 > email adress:  " << current_node->email << endl;
                cout << "                                 > Telephone number:   " << current_node->tel << endl;
                cout << "                                 > Date of checking in and out: " << current_node->date1 << "   ->     " << current_node->date2 << endl;
                cout << "                                 > Number of people staying in the room: " << current_node->nr_persons << endl;
                if (current_node->prepaid)cout << "                                 > Paid: Yes" << endl;
                else cout << "                                 > Paid: No" << endl;
                cout << "                                   ------------------------------------------------------------------------" << endl;
            }
            current_node = current_node->next;
        }
    }
    void LinkedList::display_custumer_data(int roomnr)
    {
        Node* current_node = head;
        while (current_node != nullptr)
        {
            if (current_node->room_nr==roomnr)
            {
                cout << "                                   --------------------------Custumer Information--------------------------" << endl;
                cout << "                                 > Name: " << current_node->name << endl;
                cout << "                                 > Roomm number:  " << current_node->room_nr << endl;
                cout << "                                 > email adress:  " << current_node->email << endl;
                cout << "                                 > Telephone number:   " << current_node->tel << endl;
                cout << "                                 > Date of checking in and out: " << current_node->date1 << "   ->     " << current_node->date2 << endl;
                cout << "                                 > Number of people staying in the room: " << current_node->nr_persons << endl;
                if (current_node->prepaid)cout << "                                 > Paid: Yes" << endl;
                else cout << "                                 > Paid: No" << endl;
                cout << "                                   ------------------------------------------------------------------------" << endl;
            }
            current_node = current_node->next;
        }
    }

    void LinkedList::remove(string data)
    {
        Node* current_node = head;
        Node* previous_node = nullptr;

        while (current_node != nullptr)
        {
            if (!current_node->name.compare(data))
            {
                if (previous_node == nullptr)
                {
                    head = current_node->next;
                }
                else
                {
                    previous_node->next = current_node->next;
                }
                delete current_node;
                return;
            }
            previous_node = current_node;
            current_node = current_node->next;
        }
    }
