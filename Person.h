#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string phone;

public:
    Person();
    Person(int id, string name, string phone);

    virtual void display();

    virtual ~Person();
};

#endif