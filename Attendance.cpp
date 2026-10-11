#include "Attendance.h"

Attendance::Attendance()
{
    attendanceId = 0;
    employeeId = 0;
    date = "";
    status = "";
}

Attendance::Attendance(int attendanceId, int employeeId,
                       string date, string status)
{
    this->attendanceId = attendanceId;
    this->employeeId = employeeId;
    this->date = date;
    this->status = status;
}

void Attendance::mark()
{
    cout << "Attendance marked successfully." << endl;
}

void Attendance::display()
{
    cout << "Attendance ID : " << attendanceId << endl;
    cout << "Employee ID   : " << employeeId << endl;
    cout << "Date          : " << date << endl;
    cout << "Status        : " << status << endl;
}


int Attendance::getAttendanceId()
{
    return attendanceId;
}

int Attendance::getEmployeeId()
{
    return employeeId;
}

string Attendance::getDate()
{
    return date;
}

string Attendance::getStatus()
{
    return status;
}

Attendance::~Attendance()
{

}