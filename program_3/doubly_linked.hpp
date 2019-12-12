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

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	int data; //Stores single digit of data

	struct Node* next; //Points to next digit
	struct Node* prev; //Points to previous digit
	Node(int);
};

//To initialize the structure with a single digit 
Node::Node(int val)
{
	data = val;
	next = prev = NULL;
}

class ResltVal
{
private:
	int Count;

	Node* head;
	Node* tail;
public:
	ResltVal();
	ResltVal(ResltVal*);
	~ResltVal();

	void InsertFront(int);
	void InsertEnd(int);
	void Print();
	void Destroy();
	int ListSize();
	//int GetLength();
	void Add(ResltVal*, ResltVal*);
	void Diff(ResltVal*, ResltVal*);
	//void Mult(ResltVal*, ResltVal*);


};

//Constructor of the Class 
ResltVal::ResltVal()
{
	head = tail = NULL;
	Count = 0;
}

ResltVal::ResltVal(ResltVal* other)
{
	head = tail = NULL;
	Count = 0;

	Node* temp = other->head;

	while (temp) {
		InsertEnd(temp->data);
		temp = temp->next;
	}
}

/**
 * Public InsertFront
 *
 * Adds item to Head of list by calling private method with a Node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void ResltVal::InsertFront(int data)
{
	Node *temp = new Node(data);

	if (!head)
	{
		head = tail = temp;
	}
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	Count++;
}

/**
 * Public InsertBack
 *
 * Adds item to Tail of list by calling private method with a Node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void ResltVal::InsertEnd(int data)
{
	Node *temp = new Node(data);

	if (!head)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	Count++;
}

/**
 * Public Print
 *
 * Prints list to stdout from head to tail
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void ResltVal::Print()
{
	ofstream outfile;
	outfile.open("output.txt");

	Node *temp = head;

	while (temp)
	{
		outfile << temp->data;
		if (temp->next)
		{
			outfile << "->";
		}
		temp = temp->next;
	}
	outfile << endl;
}

void ResltVal::Destroy()
{
	/*
	Node *temp = head;
	Node *prev = head;

	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
		delete temp;
	}
	*/

	head = tail = NULL;
	Count = 0;

}

/**
 * Public Size
 *
 * Returns size of list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     int
 */
int ResltVal::ListSize()
{
	return Count;
}

/**
* Public Add
*
* Adds data values in both lists.
*
* @Params:
*
*	   ResltVal* a : items in first list
*	   ResltVal* b : items in second list
*
* @Returns:
*
*     void
*/
void ResltVal::Add(ResltVal* LinkedList1, ResltVal* LinkedList2)
{
	ofstream outfile;
	outfile.open("output.txt");

	int Carry = 0; int Sum = 0;
	ResltVal* LL1 = new ResltVal(*LinkedList1);
	ResltVal* LL2 = new ResltVal(*LinkedList2);

	//Default copy constructor
	/*this->head = NULL;
	this->tail = NULL;
	this->Count = 0;*/

	while (LL1->tail != NULL || LL2->tail != NULL)
	{
		if (LL1->tail != NULL && LL2->tail != NULL)
		{
			Sum = ((LL1->tail->data) + (LL2->tail->data) + Carry) % 10;
			Carry = ((LL1->tail->data) + (LL2->tail->data) + Carry) / 10;
			LL1->tail = LL1->tail->prev;
			LL2->tail = LL2->tail->prev;
		}

		InsertFront(Sum);
	}

	while (Carry > 0)
		InsertFront(Carry);
}

/**
 * Public Diff
 *
 * Subtracts data values in both lists.
 *
 * @Params:
 *
 *	   ResltVal* a : items in first list
 *	   ResltVal* b : items in second list
 *
 * @Returns:
 *
 *     void
 */
void ResltVal::Diff(ResltVal* LL1, ResltVal* LL2)
{
	ofstream outfile;
	outfile.open("output.txt");

	int Carry = 0, Difference = 0;

	LL1->Print();
	LL2->Print();

	this->head = NULL;
	this->tail = NULL;
	this->Count = 0;
	char ch;

	while (LL1->tail != NULL || LL2->tail != NULL)
	{
		if (((LL1->tail->data) >= (LL2->tail->data)))
		{
			Difference = ((LL1->tail->data) - (LL2->tail->data));
			//outfile << "L1:" << LL1->tail->data << "-" << "L2:" 
				 //<< LL2->tail->data << "=" << Difference << endl;
			// outfile << "diff=" << Difference << endl;
		}
		else if ((LL1->tail->data) < (LL2->tail->data))
		{
			LL1->tail->data -= Carry;
			Carry = 0;
			//Handle borrow
			LL1->tail->data += 10;
			LL1->tail->prev->data -= 1;
			LL1->tail->prev->data += 10;
			//LL1->tail->data += 10;
			//outfile << "difference performed" << endl;
			Difference = ((LL1->tail->data) - (LL2->tail->data));
			Carry = 1;
		}

		LL1->tail = LL1->tail->prev;
		LL2->tail = LL2->tail->prev;

		InsertFront(Difference);
		//Print();
	}
}

/**
 * Public Mult
 *
 * Multiplies data values in both lists.
 *
 * @Params:
 *
 *	   ResltVal* a : items in first list
 *	   ResltVal* b : items in second list
 *
 */
 /*void ResltVal::Mult(ResltVal* a, ResltVal* b)
 {
	 int k = 0, i;
	 ResltVal* tpro = new ResltVal();
	 while (b->tail != NULL)
	 {
		 int c = 0, s = 0;
		 ResltVal* temp = new ResltVal(*a);
		 ResltVal* pro = new ResltVal();
		 while (temp->tail != NULL)
		 {
			 s = ((temp->tail->data) * (b->tail->data) + c) % 10;
			 c = ((temp->tail->data) * (b->tail->data) + c) / 10;
			 pro->InsertFront(s);
			 temp->tail = temp->tail->prev;
		 }
		 if (c != 0)
			 pro->InsertFront(c);

		 for (i = 0; i < k; i++)
			 pro->InsertEnd(0);

		 Add(this, pro);
		 k++;
		 b->tail = b->tail->prev;
		 pro->head = pro->tail = NULL;
		 pro->Count = 0;
	 }
 }*/
