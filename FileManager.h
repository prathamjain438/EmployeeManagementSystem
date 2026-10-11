#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Employee.h"
#include "Attendance.h"

class FileManager
{
public:
    static void saveEmployees(Employee* employees, int count);
    static int loadEmployees(Employee* employees);

    static void saveAttendance(Attendance* attendance, int count);
    static int loadAttendance(Attendance* attendance);

private:
    FileManager();
};

#endif