#include <iostream>
using namespace std;

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
	Employee(string name = "", long ID = 0, char empClass = ' ', float salary = 0);
	/*------------------------------------------------------------------------------------------
		Employee constructor.
		Precondition: None.
		Postcondidtion: Name is initialized to an empty string, employeeID is initialized to 0,
			employeeClass is initialized to an empty character, Salary is initialized to 0. 
	------------------------------------------------------------------------------------------*/

	virtual void display(ostream& out) const;
	/*-----------------------------------------------------------------------------------------
		Output function member.
		Precondition: ostream out is open.
		Postcondition: A text representation of this Employee object has been output to out.
	-----------------------------------------------------------------------------------------*/

	virtual void Calculate_salary(float profits, float rate);
	/*----------------------------------------------------------------------------------------- 
		Salary calculator function.
		Precondition: None.
		Postcondition: The salary is calculated for a given Employee. 
	-----------------------------------------------------------------------------------------*/

private:
	string Name;					//Employee's Name
	long employeeID;				//Employee's ID number
	char employeeClass;				//Employee's class
	float Salary;					//Employee's Salary
};

//--- Definition of Employee's Constructor
inline Employee::Employee(string name, long ID, char empClass, float salary)
	:Name(name), employeeID(ID), employeeClass(empClass), Salary(salary)
{ }

//--- Definition of Employee's display()
inline void Employee::display(ostream& out) const
{
	out << Name << "\t\t" << employeeID << "\t " << employeeClass << "\t  " <<  "$" << Salary;
}

//--- Definition of output operator <<
inline ostream& operator<<(ostream& out, const Employee& employee)
{
	employee.display(out);
	return out;
};

//--- Definition of Employee's Calculate_salary()
inline void Employee::Calculate_salary(float profits, float rate)
{
	if (profits > 0)
	{
		Salary = (profits * rate) + Salary;
	}
	else
	{
		Salary = Salary;
	}
}

#endif
