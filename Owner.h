#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef OWNER
#define OWNER

class Owner : public Employee
{
public:
	Owner(string name = "", long ID = 0, char empClass = ' ', float salary = 15000);
	/*------------------------------------------------------------------------------------------
		Owner constructor.
		Precondition: None.
		Postcondidtion: Name is initialized to an empty string, employeeID is initialized to 0,
			employeeClass is initialized to an empty character, Salary is initialized to 15000.
	------------------------------------------------------------------------------------------*/

	void display(ostream& out) const;
	/*------------------------------------------------------------------------------------------
		Output function member.
		Precondition: None.
		Postcondidtion: A text representation of this Owner object has been output to out.
	------------------------------------------------------------------------------------------*/

	void Calculate_salary(float profits, float null);
	/*-----------------------------------------------------------------------------------------
		Salary calculator function.
		Precondition: None.
		Postcondition: The salary is calculated for a given Owner.
	-----------------------------------------------------------------------------------------*/

};

//--- Definition of Owner's Constructor.
inline Owner::Owner(string name, long ID, char empClass, float salary)
	:Employee(name, ID, empClass, salary)
{ }

//--- Definition of Owner's display()
inline void Owner::display(ostream& out) const
{
	Employee::display(out);
	out << endl;
}

//--- Definition of Owner's Calculate_salary()
inline void Owner::Calculate_salary(float profits, float null)
{
	float rate = .60;
	Employee::Calculate_salary(profits, rate);
}
#endif