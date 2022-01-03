#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef CHEF
#define CHEF

class Chef : public Employee
{
public:
	Chef(string name = "", long ID = 0, char empClass = ' ', string specialty = "", float salary = 10000);
	/*------------------------------------------------------------------------------------------
		Chef constructor.
		Precondition: None.
		Postcondidtion: Name is initialized to an empty string, employeeID is initialized to 0,
			employeeClass is initialized to an empty character, expertise is initialized to an
			empty string, Salary is initialized to 10000.
	------------------------------------------------------------------------------------------*/

	void display(ostream& out) const;
	/*------------------------------------------------------------------------------------------
		Output function member.
		Precondition: None.
		Postcondidtion: A text representation of this Chef object has been output to out.
	------------------------------------------------------------------------------------------*/

	void Calculate_salary(float profits, float null);
	/*-----------------------------------------------------------------------------------------
		Salary calculator function.
		Precondition: None.
		Postcondition: The salary is calculated for a given Chef.
	-----------------------------------------------------------------------------------------*/

private:
	string expertise;				//Chef's expertise
};

//--- Definition of Chef's Constructor
inline Chef::Chef(string name, long ID, char empClass, string specialty, float salary)
	:Employee(name, ID, empClass, salary), expertise(specialty)
{ }

//--- Defintion of Chef's display()
inline void Chef::display(ostream& out) const
{
	Employee::display(out);
	out << "\t" << expertise << endl;
}

//--- Defintion of Employee's Calculate_salary()
inline void Chef::Calculate_salary(float profits, float null)
{
	float rate = .20;
	Employee::Calculate_salary(profits, rate);
}

#endif