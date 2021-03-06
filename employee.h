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
		Name = n; Position = p, Age = a;
	}

	Employee(const Employee& e)
	{
		Name = e.Name; Position = e.Position, Age = e.Age;
	}

	~Employee() {
	};

	Employee& operator= (const Employee& e)
	{
		if (this == &e) return *this;
		Name = e.Name; Position = e.Position; Age = e.Age;
		return *this;
	};

	friend ostream& operator << (ostream& o, const Employee& e)
	{
		return o << e.Name << ' ' << e.Position << ' ' << e.Age;
	}
};

#endif /* __EMPLOYEE_H__ */

