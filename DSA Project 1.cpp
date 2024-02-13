#include <iostream>
#include "dateType.h"
#include "personType.h"
using namespace std;
// Program to verify that the modified personType class is working correctly
int main()
{
	personType defPerson;
	defPerson.print();
	cout << endl;

	personType person("John", "Doe");
	person.print();
	cout << endl;
	person.setFirstName("Jane");
	person.setLastName("Smith");
	person.print();
	cout << endl;
}
