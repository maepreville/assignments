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

//Opponent class
class Opponent 
{
private:
	Card* left;

public:
	Opponent() 
  { // defalt constructor
		left = NULL;
	}

	void push(Card* crdNode) 
  {
		// check if list is empty
		if (!left) 
    {
			// If empty stack just point to new node
			left = crdNode;
			left->next = NULL;
		}
		else 
    {
			// Link new node by point its next to old top
			crdNode->next = left;
			// Now update top to point to the new node
			left = crdNode;
		}

	}

	int crdVal() 
  {
		Card* temp = left;
		int score = 0;
		int ace = 0;

		if (left == NULL)
			return score;

		while (temp) 
    {
			if (temp->cardFce == 1) 
      {
				score += 11;
				ace += 1;

			}
			else if (temp->cardFce == 11 || temp->cardFce == 12 || temp->cardFce == 13) 
      {
				score += 10;
			}
			else 
      {
				score += temp->cardFce;
			}
			temp = temp->next;
		}

		for (int i = 0; i < ace; i++) 
    {
			if (score > 21) 
      {
				score -= 10;
			}
		}
		score = 21 - score;
		return score;
	}

	void print() 
  {
		Card *Temp = left;
		while (Temp != NULL) 
    {
			Temp->cardOut();
			Temp = Temp->next;
		}
		cout << "---------------\n";
	}

	void printHide() 
  {
		left->cardOut();
	}

	void startHand(Deck* Dk) 
  {
		push(Dk->pop());
		push(Dk->pop());
	}

	int play(Deck* Dk, int plyrScore) 
  {
		int score = crdVal();

		bool risk = true;
		if (plyrScore < 0) 
    {
			risk = false;
		}

		while (score > plyrScore && risk) 
    {
			push(Dk->pop());
			score = crdVal();
		}
    
		return crdVal();
	}

};
