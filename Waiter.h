#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef WAITER
#define WAITER

class Waiter : public Employee
{
public:
	Waiter(string name = "", long ID = 0, char empClass = ' ', int Year = 0, float salary = 3000);
	/*------------------------------------------------------------------------------------------
		Owner constructor.
		Precondition: None.
		Postcondidtion: Name is initialized to an empty string, employeeID is initialized to 0,
			employeeClass is initialized to an empty character, years is initialized to 0, 
			Salary is initialized to 3000.
	------------------------------------------------------------------------------------------*/

	void display(ostream& out) const;
	/*------------------------------------------------------------------------------------------
		Output function member.
		Precondition: None.
		Postcondidtion: A text representation of this Waiter object has been output to out.
	------------------------------------------------------------------------------------------*/

	void Calculate_salary(float tips, float null);
	/*-----------------------------------------------------------------------------------------
		Salary calculator function.
		Precondition: None.
		Postcondition: The salary is calculated for a given Waiter.
	-----------------------------------------------------------------------------------------*/

private:
	int years;						//Waiter's years of service
};

//--- Definition of Waiter's Constructor
inline Waiter::Waiter(string name, long ID, char empClass, int service, float salary)
	:Employee(name, ID, empClass, salary), years(service)
{ }

//--- Definition of Waiter's display()
inline void Waiter::display(ostream& out) const
{
	Employee::display(out);
	out << "\t\t\t\t" << years << endl;
}

//--- Definition of Waiter's Calculate_salary()
inline void Waiter::Calculate_salary(float tips, float null)
{
	float rate = 1.00;
	Employee::Calculate_salary(tips, rate);
}
#endif
