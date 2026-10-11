#include "EmployeeSystem.h"
#include <limits>
#include <cctype>



EmployeeSystem::EmployeeSystem()
{
    employeeCapacity = 100;
    attendanceCapacity = 100;

    employeeCount = 0;
    attendanceCount = 0;

    employees = new Employee[employeeCapacity];
    attendance = new Attendance[attendanceCapacity];

    loadData();
}


void EmployeeSystem::showMenu()
{
    cout << "\n==============================================" << endl;
    cout << "       EMPLOYEE MANAGEMENT SYSTEM" << endl;
    cout << "==============================================" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Display Records" << endl;
    cout << "3. Search Record" << endl;
    cout << "4. Update Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Main Transaction / Process" << endl;
    cout << "7. Report" << endl;
    cout << "8. Save / Load" << endl;
    cout << "9. Exit" << endl;
    cout << "==============================================" << endl;
}


void EmployeeSystem::run()
{
    int choice;

    do
    {
        showMenu();
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Enter a number from 1 to 9." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            addEmployee();
            break;

        case 2:
            displayEmployees();
            break;

        case 3:
            searchEmployee();
            break;

        case 4:
            updateEmployee();
            break;

        case 5:
            deleteEmployee();
            break;

        case 6:
            cout << "\n===== Main Transaction / Process =====" << endl;
            markAttendance();
            break;

        case 7:
            cout << "\n===== Report =====" << endl;
            displayEmployees();
            displayAttendance();
            break;

        case 8:
        {
            int saveLoadChoice;

            cout << "\n===== Save / Load =====" << endl;
            cout << "1. Save Data" << endl;
            cout << "2. Load Data" << endl;
            cout << "Enter choice: ";

            if (!(cin >> saveLoadChoice))
            {
                cout << "Invalid input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (saveLoadChoice == 1)
            {
                saveData();
            }
            else if (saveLoadChoice == 2)
            {
                loadData();
                cout << "Data loaded successfully." << endl;
            }
            else
            {
                cout << "Invalid choice." << endl;
            }

            break;
        }

        case 9:
            saveData();
            cout << "Exiting Employee Management System..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter 1 to 9." << endl;
        }

    } while (choice != 9);
}


void EmployeeSystem::addEmployee()
{
    if (employeeCount >= employeeCapacity)
    {
        cout << "Employee storage is full." << endl;
        return;
    }

    int id;
    string name, phone, department;
    double salary;

    cout << "Enter Employee ID: ";

    if (!(cin >> id) || id <= 0)
    {
        cout << "Invalid ID. Enter a positive number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].getEmployeeId() == id)
        {
            cout << "Employee ID already exists." << endl;
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "Name cannot be empty." << endl;
        return;
    }

    cout << "Enter Phone: ";
    getline(cin, phone);

    if (phone.empty())
    {
        cout << "Phone cannot be empty." << endl;
        return;
    }

    cout << "Enter Salary: ";

    if (!(cin >> salary) || salary < 0)
    {
        cout << "Invalid salary. Enter a non-negative number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Department: ";
    getline(cin, department);

    if (department.empty())
    {
        cout << "Department cannot be empty." << endl;
        return;
    }

    employees[employeeCount] =
        Employee(id, name, phone, salary, department);

    employeeCount++;

    cout << "Employee added successfully." << endl;
}



void EmployeeSystem::displayEmployees()
{
    if (employeeCount == 0)
    {
        cout << "No employees found." << endl;
        return;
    }

    cout << "\n===== Employee Records =====" << endl;

    for (int i = 0; i < employeeCount; i++)
    {
        cout << "\nEmployee " << i + 1 << endl;
        cout << "------------------------" << endl;
        employees[i].display();
    }
}


void EmployeeSystem::searchEmployee()
{
    int id;

    cout << "Enter Employee ID to search: ";

    if (!(cin >> id) || id <= 0)
    {
        cout << "Invalid Employee ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].getEmployeeId() == id)
        {
            cout << "\nEmployee Found!" << endl;
            cout << "------------------------" << endl;
            employees[i].display();
            return;
        }
    }

    cout << "Employee not found." << endl;
}



void EmployeeSystem::updateEmployee()
{
    int id;

    cout << "Enter Employee ID to update: ";

    if (!(cin >> id) || id <= 0)
    {
        cout << "Invalid Employee ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].getEmployeeId() == id)
        {
            string name, phone, department;
            double salary;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Name: ";
            getline(cin, name);

            if (name.empty())
            {
                cout << "Name cannot be empty." << endl;
                return;
            }

            cout << "Enter New Phone: ";
            getline(cin, phone);

            if (phone.empty())
            {
                cout << "Phone cannot be empty." << endl;
                return;
            }

            cout << "Enter New Salary: ";

            if (!(cin >> salary) || salary < 0)
            {
                cout << "Invalid salary." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Department: ";
            getline(cin, department);

            if (department.empty())
            {
                cout << "Department cannot be empty." << endl;
                return;
            }

            employees[i].setName(name);
            employees[i].setPhone(phone);
            employees[i].setSalary(salary);
            employees[i].setDepartment(department);

            cout << "Employee updated successfully." << endl;
            return;
        }
    }

    cout << "Employee not found." << endl;
}



void EmployeeSystem::deleteEmployee()
{
    int id;

    cout << "Enter Employee ID to delete: ";

    if (!(cin >> id) || id <= 0)
    {
        cout << "Invalid Employee ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].getEmployeeId() == id)
        {
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }

            employeeCount--;

            cout << "Employee deleted successfully." << endl;
            return;
        }
    }

    cout << "Employee not found." << endl;
}



void EmployeeSystem::markAttendance()
{
    if (attendanceCount >= attendanceCapacity)
    {
        cout << "Attendance storage is full." << endl;
        return;
    }

    int attendanceId, employeeId;
    string date, status;

    cout << "Enter Attendance ID: ";

    if (!(cin >> attendanceId) || attendanceId <= 0)
    {
        cout << "Invalid Attendance ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < attendanceCount; i++)
    {
        if (attendance[i].getAttendanceId() == attendanceId)
        {
            cout << "Attendance ID already exists." << endl;
            return;
        }
    }

    cout << "Enter Employee ID: ";

    if (!(cin >> employeeId) || employeeId <= 0)
    {
        cout << "Invalid Employee ID." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    bool employeeExists = false;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].getEmployeeId() == employeeId)
        {
            employeeExists = true;
            break;
        }
    }

    if (!employeeExists)
    {
        cout << "Employee does not exist. Add the employee first." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Date (DD-MM-YYYY): ";
    getline(cin, date);

    if (date.empty())
    {
        cout << "Date cannot be empty." << endl;
        return;
    }

    cout << "Enter Status (Present/Absent): ";
    getline(cin, status);

    for (char &ch : status)
    {
        ch = static_cast<char>(
            tolower(static_cast<unsigned char>(ch)));
    }

    if (status == "present")
    {
        status = "Present";
    }
    else if (status == "absent")
    {
        status = "Absent";
    }
    else
    {
        cout << "Status must be Present or Absent." << endl;
        return;
    }

    attendance[attendanceCount] =
        Attendance(attendanceId, employeeId, date, status);

    attendanceCount++;

    cout << "Attendance marked successfully." << endl;
}



void EmployeeSystem::displayAttendance()
{
    if (attendanceCount == 0)
    {
        cout << "No attendance records found." << endl;
        return;
    }

    cout << "\n===== Attendance Records =====" << endl;

    for (int i = 0; i < attendanceCount; i++)
    {
        cout << "\nAttendance " << i + 1 << endl;
        cout << "------------------------" << endl;
        attendance[i].display();
    }
}



void EmployeeSystem::saveData()
{
    FileManager::saveEmployees(employees, employeeCount);
    FileManager::saveAttendance(attendance, attendanceCount);
}



void EmployeeSystem::loadData()
{
    employeeCount = FileManager::loadEmployees(employees);
    attendanceCount = FileManager::loadAttendance(attendance);
}



EmployeeSystem::~EmployeeSystem()
{
    delete[] employees;
    delete[] attendance;
}

