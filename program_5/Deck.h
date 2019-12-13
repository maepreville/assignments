// Author:           MAE-JEANNE PREVILLE
// Assignment:       Program_05
// Date:             13 December 2019
// Title:            Program 5 - Card Game (Blackjack) - EXTRA CREDIT
// Semester:         Fall 2019
// Course:           Data Structures - Dr. Griffin 
// 
// Files:            blackjack.cpp, 
//                   Card.h,
//                   Deck.h,
//                   Opponent.h,
//                   Player.h,
//                   TermGame.h
//                   
// Description:		   This program is a card game in which players draw                         cards attempting to get the sum total 
//                   of their hand as close to 21 as possible. 

#include <iostream>

using namespace TermGame;

using namespace std;

//Deck class
class Deck 
{
private:
	Card* top;
	int Decksize;

public:

	/**
	 * Deck
	 * Purpose:
	 *     constructs the object
	 */

	Deck() 
  {
		top = new Card(1);
		Card* temp = top;
		for (int i = 2; i < 53; i++) 
    {
			temp->next = new Card(i);
			temp = temp->next;
		}
		Decksize = 52;
	}

	void swap(Card* deck_a, Card* deck_b) 
  {
		if (deck_a == deck_b) 
    {
			return;
		}
		Card *prevHand1 = NULL;
		Card *plyerHand1 = top;
		while (plyerHand1 != deck_a)
		{
			prevHand1 = plyerHand1;
			plyerHand1 = plyerHand1->next;
		}
		Card *prevHand2 = NULL;
		Card *plyerHand2 = top;
		while (plyerHand2 != deck_b)
		{
			prevHand2 = plyerHand2;
			plyerHand2 = plyerHand2->next;
		}

		if (plyerHand1 == NULL || plyerHand2 == NULL)
			return;

		if (prevHand1 != NULL)
			prevHand1->next = plyerHand2;
		else
			top = plyerHand2;

		if (prevHand2 != NULL)
			prevHand2->next = plyerHand1;
		else
			top = plyerHand1;

		Card* temp = plyerHand2->next;
		plyerHand2->next = plyerHand1->next;
		plyerHand1->next = temp;
	}

	void push(int A) 
  {
		//New memory
		Card * crdNode = new Card(A);
		cout << crdNode->suit;

		// check if list is empty
		if (!top) {
			top = crdNode; //adds new node if empty
		}
		else {
			// Link new node by point its next to old top
			crdNode->next = top;
			// Now update top to point to the new node
			top = crdNode;
		}
		Decksize++;
	}

	Card* pop() 
  {
		if (!top) 
    {
			//Returns NULL is stack is empty
			return NULL;
		}
		else 
    {
			Card *Temp = top;
			Card *a = top;
			top = top->next;
			
      //Deletes old top node
			delete Temp;

			Decksize--;
			return a;
		}

	}

  void shuffle(int hand[], int size)
  {
      // add random cards
      for(int i = 0; i < size; i++){
          hand[i] = rand() % 52;
      }
  }

	void print() 
  {
		Card *Temp = top;

		while (Temp != NULL) 
    {
			Temp->cardOut();
			Temp = Temp->next;
		}
		cout << "Decksize: " << Decksize << endl;
		cout << "---------------\n";
	}

};
