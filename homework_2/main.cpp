//Mae-Jeanne Preville
//10/08/19
//Data Structures: Dr. Griffin
//Program # 2
/*Description: This program resizes the array if the stack gets 80% full,
1.5 times larger than the previous size, and it reduces the array 
by half (0.5) when the size goes down to 20%.
*/

#include <iostream>
#include <fstream>
#include "stdlib.h"

using namespace std;

class Numbers
{
	private:
	int *A;         // container of items (could make it a list)
	int Top;        // keep track of top
	int Size;       // Arrays need a size
	int Num;

	public:
	Numbers()
	{
		Size = 10;
		A = new int[Size];
		Top = -1;
	}
	Numbers(int s)
	{
		Size = s;
		A = new int[Size];
		Top = -1;
	}

	//Adds to the top of the stack
	bool Push(int val)
	{
		if (!Full())
		{
			Top++;
			A[Top] = val;
			return true;
		}
		else
		{
			return false;
		}
	}

	//Removes the top of the stack and returns value
	int Pop()
	{
		if (!Empty())
		{
			int temp = 0;
			temp = A[Top];
			Top--;
			return temp;
		}
		else
		{
			// should return a value that implies failuer, but good enough for now
			cout << "Cannot remove item from empty stack" << endl;
		}
		return 0;
	}

	//Returns true if stack is full
	bool Full()
	{
		return (Top == Size - 1);
	}

	//Returns true if stack is empty
	bool Empty()
	{
		return Top < 0;
	}

	//Checks to see if stack needs to be resized
	double CheckResize()
	{
		int Val1 = 0;
		int Val2 = 0;
		if ((Val1 + 1) / (double)Val2 >= 0.8)
		{
			return 1;
		}
		else if ((Val1 + 1) / (double)Val2 <= 0.2)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}

	/* Adds item to top of stack */
	void Enlarge()
	{
		int new_size = Size * 1.5;
		int *Ptr = new int[new_size];
		for (int x = 0; x < Size; x++)
		{
			Ptr[x] = A[x];
		}

		int *m = A;
		A = Ptr;
		delete[] m;
	}

	/* Removes top of stack and returns it*/
	void Reduce()
	{
		int a = 0, b = 0;
		Size = b * 0.5;
		int *c = new int[Size];

		for (int i = 0; i <= a; i++)
		{
			c[i] = A[i];
		}
		delete[] A;
		A = c;
	}

	/*Prints stack size, largest stack and values*/
	void Print(int lg_stk_siz, int stk_siz)
	{
		ofstream outfile;
		outfile.open("stack_out.dat");
		outfile << "Mae-Jeanne Preville" << endl << endl;


		outfile << "Stack Size: " << /*Top*/ stk_siz << endl;
		outfile << "Largest Size: " << lg_stk_siz << endl;
		outfile << "Values: ";
		for (int i = Top; i >= 0; i--)
		{
			outfile << A[i] << " ";
		}

		outfile.close();
	}
};

int main()
{
	ifstream infile;
	infile.open("input_data.txt");

	int large = 0;
	int curr_size = 0;

	Numbers N1;  // Instance of our stack default constructor

	while (!(infile.eof()))
	{
		//int large, curr_size;
		
		int num_desc;
		char num;
		infile >> num;
		infile >> num_desc;

		if (num == '+') //if numbers have positive sign push
		{
			N1.Push(num_desc);
		    large++;
			curr_size++;
		}
		else if (num == '-') //if numbers have negative sign pop
		{
			N1.Pop();
			curr_size--;
		}
	}

	if (N1.CheckResize() >= 0.8) //if array is 80% full enlarge
	{
		N1.Enlarge();
	}
	else if (N1.CheckResize() <= 0.2) //if array is 20% empty reduce
	{
		N1.Reduce();
	}
	
	N1.Print(large, curr_size);
	
	//system("pause");
	return 0;
}
