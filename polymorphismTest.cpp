#include "Manager.h"
#include <iostream>
using namespace std;

int main()
{
    Employee* person = new Manager(
        201,
        "Rahul",
        "9876543210",
        50000,
        "IT",
        5,
        10000
    );

    cout << "===== Runtime Polymorphism =====" << endl;

    person->display();

    cout << "Total Salary: "
         << person->calculateSalary() << endl;

    delete person;

    return 0;
}

