// Author:           MAE-JEANNE PREVILLE
// Assignment:       Program_03
// Date:             14 November 2019 
// Title:            Program 3 - Arbituary Math
// Semester:         Fall 2019
// Course:           Data Structures - Dr. Griffin 
// 
// Files:            apm.cpp, 
//                   doubly_linked.hpp, 
//                   input_data.txt 
//                   output.num
//
// Description:		 This program calculates sum, diffference and product of
//					       two numbers and stores the value in another doubly 
//					       linked list.

#include "doubly_linked.hpp"
#include <fstream>
#include <iostream>

// Driver code 
int main()
{
	ifstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("output.txt");

	outfile << "MAE-JEANNE PREVILLE" << endl;
	outfile << "Program 3 - Arbituary Math" << endl;
	outfile << "Date: 14 November 2019 " << endl;

	int NumofOperations;
	char MathOptr = ' ';
	string Num1;
	string Num2;
	char NumData;
	int IntValNumData;
	char ch;
	bool debug = false;

	ResltVal* Copy_1;
	ResltVal* Copy_2;

	// get how many operations
	infile >> NumofOperations;

	//driver 
	for (int j = 0; j < NumofOperations;j++) {

		ResltVal* Num_1 = new ResltVal();
		ResltVal* Num_2 = new ResltVal();
		ResltVal* Num_3 = new ResltVal();

		//Prep each operation 
		infile >> MathOptr >> Num1 >> Num2;

		//Create first linked list
		for (int i = 0; i < Num1.length(); i++) {
			Num_1->InsertEnd((int)(Num1[i] - '0'));
		}

		//Handles difference if num1 is longer than num2
		if (Num1.length() > Num2.length())
		{
			int subLength = Num1.length() - Num2.length();

			for (int i = 0; i <= subLength-1; i++)
			{
				Num_2->InsertFront(0);
			}
		}
		else if (Num1.length() < Num2.length())
		{
			int subLength = Num2.length() - Num1.length();

			for (int i = 0; i <= subLength - 1; i++)
			{
				Num_1->InsertFront(0);
			}
		}

		//confident here
		if (debug) {
			outfile << "list 1" << endl;
			Num_1->Print();
			cin.get(ch);
		}

		outfile << endl;

		// prep second linked list
		for (int x = 0; x < Num2.length(); x++) {
			Num_2->InsertEnd((int)(Num2[x] - '0'));
		}

		if (debug) {
			outfile << "list 2" << endl;
			Num_2->Print();
			cin.get(ch);
		}

		// Make copies to due operations without destroying original
		Copy_1 = new ResltVal(Num_1);
		Copy_2 = new ResltVal(Num_2);

		if (debug) {
			Copy_1->Print();
			Copy_2->Print();

			Num_1->Destroy();
			Num_2->Destroy();
		}
		
		// here we know what operation is
		// we know who our tow values are
		// so we choose

		switch (MathOptr)
		{
			case '+':

				outfile << "Sum: " << endl;
				outfile << Num1 << endl;
				outfile << Num2 << endl << endl;

				Num_3->Add(Copy_1, Copy_2);
				Num_3->Print();
				outfile << endl;
				break;

			case '-':

				outfile << "Difference: " << endl;
				outfile << Num1 << endl;
				outfile << Num2 << endl << endl;

				Num_3->Diff(Copy_1, Copy_2);
				Num_3->Print();
				outfile << endl;

				break;

			/*case '*':

				outfile << "Product: " << endl;
				outfile << Num1 << endl;
				outfile << Num2 << endl << endl;

				Num_3->Mult(Copy_1, Copy_2);
				Num_3->Print();
				outfile << endl;

				break;
			}*/
		}
		outfile << "===========================" << endl;
	}	   

	//infile.close();
	//outfile.close();

	//return 0;
	system("pause");
}
