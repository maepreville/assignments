//Mae-Jeanne Preville
//Data Structures - Dr. Griffin
//Program # 1
//Date: 09/03/19
/*Two functions loadClassList that opens the file and reads the data.
printClassList which will print out the results in a nicely formatted manner.
*/

#include <iostream> // write to and read from stdin and stdout
#include <string>   //
#include <fstream>  // read a write files
#include <iomanip>

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program

using namespace std; // so we don't have to put std:: in front of cin, cout.

struct Student
{
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};

int loadClassList(Student *classList, string input_data)
{
	ifstream fin; // get a stream variable
	fin.open("input_data.txt"); // open the stream using our fileName param
	int i = 0; //counter

	// While we have not reached the end of file
	while (!fin.eof())
	{
		// Read one line in the file into one struct at array location `i`
		fin >> classList[i].fname >> classList[i].lname;
		fin >> classList[i].numGrades;
		for (int j = 0; j < classList[i].numGrades; j++)
		{
			fin >> classList[i].grades[j];
		}
		//increment `i`
		i++;
	}
	fin.close();

	//return student count
	return i;
}

void printClassList(Student *classList, int classSize)
{
	ofstream outfile;
	outfile.open("student_output.dat");

	outfile << "Mae-Jeanne Preville" << endl;
	outfile << "Students" << endl;
	outfile << "====================================" << endl;

	for (int i = 0; i < classSize; i++)
	{
		outfile << i + 1 << ". " << classList[i].fname << " "
			<< classList[i].lname << ":";

		for (int j = 0; j < classList[i].numGrades; j++)
		{
			outfile << setw(4) << classList[i].grades[j] << "  ";
		}
		outfile << endl;

	}

	outfile.close();
}

int main()
{
	srand(2345);  // seed with integer means same randoms generated every time

	int A[SIZE];        // Array to hold students read from file
	Student classList[100];
	int classSize = 0;

	// Call the loadClassList function to open a file and load an array
	// of `Student` structs.
	classSize = loadClassList(classList, "input_data.txt");

	// Function to print out an array of students in a formatted way.
	printClassList(classList, classSize);

	//system("pause");
	return 0;
}
