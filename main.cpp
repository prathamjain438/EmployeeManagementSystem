#include "EmployeeSystem.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
    try
    {
        EmployeeSystem system;
        system.run();
    }
    catch (const exception& e)
    {
        cerr << "System error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "An unexpected error occurred." << endl;
        return 1;
    }

    return 0;
}

