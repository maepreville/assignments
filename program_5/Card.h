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

//Card class
class Card 
{
public:
	Card* next;

	int suit;
  int cardNmbr;
	int cardFce;

	Card() 
  { //defalt constructor
		next = NULL;
		cardNmbr = 0;
		cardFce = 0;
		suit = 0;
	}
	Card(int num) 
  {
		next = NULL;
		cardNmbr = num;
		cardFce = (num % 13) + 1;
		suit = num / 13.1;
	}

/**
* Card
* Purpose:
*     print the Card,determines the suit of the Card
* Params:
*     void
* Returns:
*     void
*/
  void cardOut(){

    char cardFces[] = {'A', '2', '3', '4', '5', '6', '7','8','9', 'T', 'J', 'Q', 'K'};
    string suits[] = {"♥", "♦","♣", "♠"};
    int x = 0;

    int suit;
    int cardFce;

    string blank = "";
    blank += "┌────┐\n";
    blank += "│    │\n";
    blank += cardFces[cardFce];
    blank += suits[suit];
    blank += "│    │\n";
    blank += "└────┘\n";

    cout << blank;
  }

};
