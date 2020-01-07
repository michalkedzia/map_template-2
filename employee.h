#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <iostream>
using namespace std;

class Employee
{
public:
    string Name;
    string Position;
    int Age;

    Employee(string n = "", string p = "", int a = 0)
    {
        // cout << "Employee(string n="", string p="" ,int a=0)" << endl;
        Name = n; Position = p, Age = a;
    }

    Employee(const Employee& e)
    {
        // cout << "Employee(const Employee & e)" << endl;
        Name = e.Name; Position = e.Position, Age = e.Age;
    }

    ~Employee() {
        // cout << "~Employee(){" << endl;
    };

    Employee& operator= (const Employee& e)
    {
        // cout << "Employee & operator= (const Employee & e)" << endl;
        if (this == &e) return *this;
        Name = e.Name; Position = e.Position; Age = e.Age;
        return *this;
    };

    friend ostream& operator << (ostream& o, const Employee& e)
    {
        // cout << "friend ostream& operator << (ostream& o, const Employee& e)" << endl;
        return o << e.Name << ' ' << e.Position << ' ' << e.Age;
    }
};

#endif /* __EMPLOYEE_H__ */

