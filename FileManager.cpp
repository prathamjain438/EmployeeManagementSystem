#include "FileManager.h"
#include <fstream>

using namespace std;

FileManager::FileManager()
{
}


void FileManager::saveEmployees(Employee* employees, int count)
{
    ofstream file("employees.txt");

    if (!file)
    {
        cout << "Error opening employee file." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << employees[i].getEmployeeId() << endl;
        file << employees[i].getName() << endl;
        file << employees[i].getPhone() << endl;
        file << employees[i].getSalary() << endl;
        file << employees[i].getDepartment() << endl;
    }

    file.close();

    cout << "Employee records saved successfully." << endl;
}



int FileManager::loadEmployees(Employee* employees)
{
    ifstream file("employees.txt");

    if (!file)
    {
        return 0;
    }

    int count = 0;

    while (true)
    {
        int id;
        string name;
        string phone;
        double salary;
        string department;

        if (!(file >> id))
        {
            break;
        }

        file.ignore();

        if (!getline(file, name))
        {
            break;
        }

        if (!getline(file, phone))
        {
            break;
        }

        if (!(file >> salary))
        {
            break;
        }

        file.ignore();

        if (!getline(file, department))
        {
            break;
        }

        if (id <= 0)
        {
            continue;
        }

        employees[count] =
            Employee(id, name, phone, salary, department);

        count++;
    }

    file.close();

    return count;
}


void FileManager::saveAttendance(Attendance* attendance, int count)
{
    ofstream file("attendance.txt");

    if (!file)
    {
        cout << "Error opening attendance file." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << attendance[i].getAttendanceId() << endl;
        file << attendance[i].getEmployeeId() << endl;
        file << attendance[i].getDate() << endl;
        file << attendance[i].getStatus() << endl;
    }

    file.close();

    cout << "Attendance records saved successfully." << endl;
}



int FileManager::loadAttendance(Attendance* attendance)
{
    ifstream file("attendance.txt");

    if (!file)
    {
        return 0;
    }

    int count = 0;

    while (true)
    {
        int attendanceId;
        int employeeId;
        string date;
        string status;

        if (!(file >> attendanceId))
        {
            break;
        }

        if (!(file >> employeeId))
        {
            break;
        }

        file.ignore();

        if (!getline(file, date))
        {
            break;
        }

        if (!getline(file, status))
        {
            break;
        }

        if (attendanceId <= 0 || employeeId <= 0)
        {
            continue;
        }

        attendance[count] =
            Attendance(attendanceId, employeeId, date, status);

        count++;
    }

    file.close();

    return count;
}

