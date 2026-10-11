#include "Employee.h"

Employee::Employee()
{
    employeeId = 0;
    salary = 0;
    department = "";
}

Employee::Employee(int employeeId, string name, string phone,
                   double salary, string department)
    : Person(employeeId, name, phone)
{
    this->employeeId = employeeId;
    this->salary = salary;
    this->department = department;
}

void Employee::display()
{
    cout << "Employee ID : " << employeeId << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Salary      : " << salary << endl;
    cout << "Department  : " << department << endl;
}

double Employee::calculateSalary()
{
    return salary;
}

int Employee::getEmployeeId()
{
    return employeeId;
}

string Employee::getName()
{
    return name;
}

string Employee::getPhone()
{
    return phone;
}

double Employee::getSalary()
{
    return salary;
}

string Employee::getDepartment()
{
    return department;
}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setPhone(string phone)
{
    this->phone = phone;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

void Employee::setDepartment(string department)
{
    this->department = department;
}

Employee::~Employee()
{

}