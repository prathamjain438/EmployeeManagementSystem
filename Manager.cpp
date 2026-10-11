#include "Manager.h"

Manager::Manager()
{
    managerId = 0;
    teamSize = 0;
    bonus = 0;
}

Manager::Manager(int managerId, string name, string phone,
                 double salary, string department,
                 int teamSize, double bonus)
    : Employee(managerId, name, phone, salary, department)
{
    this->managerId = managerId;
    this->teamSize = teamSize;
    this->bonus = bonus;
}

void Manager::display()
{
    cout << "Manager ID  : " << managerId << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Salary      : " << salary << endl;
    cout << "Department  : " << department << endl;
    cout << "Team Size   : " << teamSize << endl;
    cout << "Bonus       : " << bonus << endl;
}

double Manager::calculateSalary()
{
    return salary + bonus;
}

Manager::~Manager()
{

}