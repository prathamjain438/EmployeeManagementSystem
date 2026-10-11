#include "Person.h"

Person::Person()
{
    id = 0;
    name = "";
    phone = "";
}

Person::Person(int id, string name, string phone)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
}

void Person::display()
{
    cout << "ID      : " << id << endl;
    cout << "Name    : " << name << endl;
    cout << "Phone   : " << phone << endl;
}

Person::~Person()
{
    
}