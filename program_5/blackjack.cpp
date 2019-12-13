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
#include <string>
#include "TermGame.h"
#include "Card.h"
#include "Deck.h"
#include "Opponent.h"
#include "Player.h"

using namespace TermGame;

using namespace std;

int main() {
	Deck stkOfCrds;
	Player Player1;
	Opponent Player2;

	//stkOfCrds.print();
	Player2.startHand(&stkOfCrds);

	Player1.play(&stkOfCrds, &Player2);

	int playerScore = Player1.crdVal(); //score of player one
	int Player2Score;

	Player2Score = Player2.play(&stkOfCrds, playerScore);

	cout << "Dealers hand: \n";
	Player2.print(); //Displays player 2's hand

	cout << "This is your score: " << 21 - playerScore << endl;
	cout << "Dealer score is: " << 21 - Player2Score << endl;

	if (playerScore < 0) {
		cout << "Bust" << endl;
	}
	else if (Player2Score < 0) {
		cout << "Dealer bust" << endl;
	}
	else {
		if (Player2Score < playerScore) {
			cout << "You lost" << endl;
		}
		else if (Player2Score == playerScore) {
			cout << "It's a tie" << endl;
		}
		else {
			cout << "You've won" << endl;
		}
	}
}
