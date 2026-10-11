#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
private:
    int managerId;
    int teamSize;
    double bonus;

public:
    Manager();

    Manager(int managerId, string name, string phone,
            double salary, string department,
            int teamSize, double bonus);

    void display() override;
    double calculateSalary() override;

    ~Manager();
};

#endif