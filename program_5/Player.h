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

//Player class
class Player 
{
private:
	Card* left;

public:

	Player() {
		left = NULL;
	}

	int crdVal() {
		Card* temp = left;
		int score = 0;
		int ace = 0;

		if (left == NULL)
			return score;

		while (temp) {
			if (temp->cardFce == 1) {
				score += 11;
				ace += 1;
			}
			else if (temp->cardFce == 11 || temp->cardFce == 12 || temp->cardFce == 13) {
				score += 10;
			}
			else {
				score += temp->cardFce;
			}
			temp = temp->next;
		}

		for (int i = 0; i < ace; i++) {
			if (score > 21) {
				score -= 10;
			}
		}
		score = 21 - score;

		return score;
	}

	void print() {
		Card *Temp = left;

		while (Temp != NULL) {
			Temp->cardOut();
			// cout << "cardNmbr: " << Temp->cardNmbr << " suit: " << Temp->suit << " cardFce: " << Temp->cardFce << endl;
			Temp = Temp->next;
		}
		cout << "---------------\n";
	}

	int play(Deck* Dk,  Opponent* Dlr) 
  {
  	int score;
		Card* selected = left;
		bool fold = false;
    int move;

		cout << "Dealer hand: \n";

		Dlr->printHide();

		push(Dk->pop());
		push(Dk->pop());

		while (fold == 0 && crdVal() >= 0) {
			cout << "Current hand: \n";
			print();

      cout << "Select an operation: "<< endl;
      cout << "Press 1 to Fold" << endl <<
      "Press 2 to hit" << endl << 
      "Press 3 to see hand" << endl;

      cin >> move;

			move = toupper(move);

			if (move == 1)
				fold = true;

			else if (move == 2) 
      {
				push(Dk->pop());
			}
			else if (move == 3) 
      {
				cout << "Dealers hand: \n";
				Dlr->printHide();
			}
		}

		return score;
	}

  void push(Card* crdNode) {

		// check if list is empty
		if (!left) {
			left = crdNode;
			left->next = NULL;
		}
		else {
			// Link new node by point its next to old top and
			// Now update top to point to the new node
			crdNode->next = left;
			left = crdNode;
		}
	}

};

