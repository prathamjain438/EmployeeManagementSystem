#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:
    int employeeId;
    double salary;
    string department;

public:
    Employee();

    Employee(int employeeId, string name, string phone,
             double salary, string department);

    virtual void display() override;
    virtual double calculateSalary();

    int getEmployeeId();
    string getName();
    string getPhone();
    double getSalary();
    string getDepartment();

    void setName(string name);
    void setPhone(string phone);
    void setSalary(double salary);
    void setDepartment(string department);

    virtual ~Employee();
};

#endif