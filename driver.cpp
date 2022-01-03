#include <iostream>
#include <list>
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"

using namespace std;

int main()
{
	float null = NULL;															//null initialized to NULL.
	char answer;																//Character for user input.
	float profit = 0;															//profit initialized to 0.
	float tipOne = 0;															//tipOne initialized to 0.
	float tipTwo = 0;															//tipTwo initialized to 0.
	float tipThree = 0;															//tipThree initialized to 0.

	//Prints the description of the program.
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "||Description: This is a database for a restaurant with six employees. The user will be prompted to||" << endl;
	cout << "||indicate if the restaurant encounter a profit or loss for that current month. Then the user must ||" << endl;
	cout << "||enter the amount the restaurant gained or lost including the sign. After the user will then be   ||" << endl;
	cout << "||prompted to enter the amount of tips each waiter recieved for that current month. Finally, a     ||" << endl;
	cout << "||table will be printed showing all the data for each employee of the restaurant.                  ||" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	//Prompts user for monthly profit and tips for each waiter. 
	cout << "Did the restaurant encounter a profit or loss for the month? (+/-): ";
	cin >> answer;
	cout << endl;
	if (answer == '+')
	{
		cout << "How much did the restaurant profit this month?: $";
		cin >> profit;
	}
	else
	{
		cout << "How much did the restaurant lose this month?: $";
		cin >> profit;
	}
	cout << "How much did the first waiter earn in tips?: $";
	cin >> tipOne;
	cout << "How much did the second waiter earn in tips?: $";
	cin >> tipTwo;
	cout << "How much did the third waiter earn in tips?: $";
	cin >> tipThree;
	cout << endl;

	Employee* ptr;																//Creates an Employee pointer.
	list<Employee*> empList;													//Creates a list of Employee pointers.
	ptr = new Owner("Peter Marrone", 12345, 'O');								//Assigns ptr to a new Owner object.
	empList.push_back(ptr);														//Pushes ptr onto the list.													
	ptr->Calculate_salary(profit, null);										//Calculates salary for current Employee ptr.
	ptr = new Chef("Kavon Cacho", 12456, 'C', "Italian");						//Assigns ptr to a new Chef object.
	empList.push_back(ptr);														//Pushes ptr onto the list.
	ptr->Calculate_salary(profit, null);										//Calculates salary for current Employee ptr.
	ptr = new Chef("Tristan Gilbert", 12567, 'C', "French");					//Assigns ptr to a new Chef object.
	empList.push_back(ptr);														//Pushes ptr onto the list.
	ptr->Calculate_salary(profit, null);										//Calculates salary for current Employee ptr.
	ptr = new Waiter("Jared Bryant", 12678, 'W', 3);							//Assigns ptr to a new Waiter object.
	empList.push_back(ptr);														//Pushes ptr onto the list.
	ptr->Calculate_salary(tipOne, null);										//Calculates salary for current Employee ptr.
	ptr = new Waiter("Zack Stark", 12789, 'W', 5);								//Assigns ptr to a new Waiter object.
	empList.push_back(ptr);														//Pushes ptr onto the list.
	ptr->Calculate_salary(tipTwo, null);										//Calculates salary for current Employee ptr.
	ptr = new Waiter("Austin Whitacre", 13123, 'W', 7);							//Assigns ptr to a new Waiter object.
	empList.push_back(ptr);														//Pushes ptr onto the list.
	ptr->Calculate_salary(tipThree, null);										//Calculates salary for current Employee ptr.

	//Sets up table for printing of the database.
	cout << "Name:" << "\t\t\t" << "ID:" << "\t " << "Class:" << "\t  " << "Salary:" << "\t" << "Expertise:" << "\t" << "Years of Service:" << endl;
	cout << endl;

	//Cycles through Employee list and displays them. 
	for (list<Employee*>::iterator it = empList.begin(); it != empList.end(); it++)
	{
		ptr = *it;
		ptr->display(cout);
	}
}