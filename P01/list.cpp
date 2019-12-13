//Mae-Jeanne Preville
//Data Structures - Dr. Griffin
//Program 1
//Date: 09/17/19


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool stringMatch(string macro, string micro)
{
	return macro.find(micro) >= 0;
}

string lower_string(string orig)
{
	string result = "";
	for (int i = 0; i < orig.size(); i++)
	{
		result += tolower(orig[i]);
	}
	return result;
} 

struct Employee 
{
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee() 
	{
		return;
	}
	
};


struct Node
{
	Employee descript;
	Node* next;

	Node(Employee info, Node *n = NULL)
	{
		descript = info;
		next = n;
	}
};

class LinkedList 
{

	public:
		LinkedList() 
		{
			Head = NULL;
		}

		void push(Employee descript) 
		{
			Node *Temp = new Node(descript, Head);
			Head = Temp;
		}

		Employee pop() 
		{
			Employee result = Head->descript;
			Node *temp_del = Head;
			Head = Head->next;
			delete temp_del;
			return result;
		}

		bool find(string employee_email) 
		{
			Node *Temp = Head;		
			while (Temp != NULL)
			{
				if (string_match(lower_string(Temp->descript.email), lower_string(employee_email)))
				{
					return true;
				}
				else
				{
					Temp = Temp->next;
				}
			}
			return false;

		}		

	
		void print()
		{
			/*Employee* Temp = Head;

			while (Temp != NULL)
			{*/
				cout << emp_id << ", " << first_name << ", "
					<< last_name << ", " << gender << ", "
					<< email << ", " << hourly_pay;

				/*if (Temp->Next) {
					cout << "->";
				}

				Temp = Temp->Next;
			}*/
		}



	private:
		Node *Head;
	
};


int main()
{
	LinkedList EmployeeDescriptList;

	ifstream fin;
	fin.open("employees.dat");
	ofstream outfile;
	outfile.open("maeOutput.txt");

	while (!fin.eof())
	{
		EmployeeDescriptList personalInfo;

		fin >> personalInfo.emp_id >> ", " >> personalInfo.first_name >> ", "
			>> personalInfo.last_name >> ", " >> personalInfo.gender >> ", "
			>> personalInfo.email >> ", " >> personalInfo.hourly_pay;

		EmployeeDescriptList.push(personalInfo);
	}

	outfile << "Mae-Jeanne Preville" << endl << endl;
	outfile << "Was word found? (1 = yes, 0 = no)" << endl;
	outfile << "Answer = " << EmployeeDescriptList.find("salon") << endl;
	
	//Displays information in
	EmployeeDescriptList.print(outfile);

	outfile.close();
	//system("pause");
	return 0;
}
