#ifndef EMPLOYEESYSTEM_H
#define EMPLOYEESYSTEM_H

#include "Employee.h"
#include "Attendance.h"
#include "FileManager.h"

class EmployeeSystem
{
private:
    Employee* employees;
    Attendance* attendance;

    int employeeCount;
    int attendanceCount;

    int employeeCapacity;
    int attendanceCapacity;

public:
    EmployeeSystem();

    void showMenu();
    void run();

    void addEmployee();
    void displayEmployees();
    void searchEmployee();
    void updateEmployee();
    void deleteEmployee();

    void markAttendance();
    void displayAttendance();

    void saveData();
    void loadData();

    ~EmployeeSystem();
};

#endif