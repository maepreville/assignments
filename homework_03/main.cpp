/*Mae-Jeanne Preville
 Date: Oct 15th 2019
 Homework #3 - Dr. Griffin
 Description: List based Stack that holds an animal type
 */

#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream fin("animals.txt");  // input file of animal info                   

	Animal *a;                 // animal pointer used to hold popped animals

	string name;
	double weight;
	double scary;

	ListStack LS;                 // List based stack object

	// While still animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary;
		a = new Animal(name, weight, scary);                         // allocate memory for an animal
		LS.Push(a);                               // push animal onto the stack
	}

	LS.Print();             // Print the stack

	cout << endl;           // ummm

	a = LS.Pop();           // get animal off top of stack
	
	
	cout << "________" << endl << endl;
	cout << a << endl;      // print animal (cout operator overloaded)

	a = LS.Pop();           // get animal off top of stack again

	cout << "________" << endl << endl;
	cout << a << endl;      // print animal (cout operator overloaded)

	cout << "________" << endl << endl;
	LS.Print();             // print the stack

	system("pause");
	return(0);
}
