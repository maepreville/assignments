//Mae-Jeanne Preville
//Data Structures - Dr. Griffin
//Program 1
//Date: 09/17/19


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int menu()
{
	int choice = 0;

	while (choice < 1 || choice > 3)
	{
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Delete Employee\n";
		cout << "    3 - Quit\n";
		cout << "Choice: ";
		cin >> choice;
	}
	return choice;
}


bool substringMatch(string macro, string micro)
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
	
	Employee(string id, string first, string last, string sex, string mail, double pay) {
		emp_id = id;
		first_name = first;
		last_name = last;		
		gender = sex;
		email = mail;
		hourly_pay = pay;
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


		/*bool find(string pokemon_name)
		{
			Node *temp = head;
			while (temp != NULL)
			{
				//if (temp->poke.name == pokemon_name)
				if (string_match(lower_string(temp->poke.name), lower_string(pokemon_name)))
				{
					return true;
				}
				else
				{
					temp = temp->next;
				}
			}
			return false;
		}*/



	private:
		Node *Head;
	
};


int main()
{
	LinkedList EmployeeDescriptList;

	/*string empid;
	string first;
	string last;
	string email;
	string gender;
	double pay;

	string line;
	string *tokens;*/
	ifstream fin;
	fin.open("employees.dat");

	int choice = 0;

	while (choice != 3) {
		choice = menu();
	}

	while (!fin.eof())
	{
		EmployeeDescriptList personalInfo;

		fin >> personalInfo.emp_id >> ", " >> personalInfo.first_name >> ", "
			>> personalInfo.last_name >> ", " >> personalInfo.gender >> ", "
			>> personalInfo.email >> ", " >> personalInfo.hourly_pay;

		EmployeeDescriptList.push(personalInfo);
	}

	cout << EmployeeDescriptList.find("salon") << endl;


	system("pause");
	return 0;
}
