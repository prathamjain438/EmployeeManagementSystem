#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <iostream>
#include <string>

using namespace std;

class Attendance
{
private:
    int attendanceId;
    int employeeId;
    string date;
    string status;

public:
    Attendance();

    Attendance(int attendanceId, int employeeId,
               string date, string status);

    void mark();
    void display();

    int getAttendanceId();
    int getEmployeeId();
    string getDate();
    string getStatus();

    ~Attendance();
};

#endif