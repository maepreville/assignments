// Author:           MAE-JEANNE PREVILLE
// Assignment:       Program_04
// Date:             26 November 2019
// Title:            Program 4 - Caeser Cipher Class
// Semester:         Fall 2019
// Course:           Data Structures - Dr. Griffin 
// 
// Files:            cipher.cpp, 
//                   encrypted.txt,
//					 decrypted.txt
//
// Description:		 This program encrypts a plaintext file, and decrypts 
//					 an encrypted file using CeaserCipher Class.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Encryption {

	int totNumMsgs;
	int shiftVal;
	string encryptTxt;
	string Result;

	//Constructor
	Encryption() {

		int totNumMsgs = 0;
		int shiftVal = 0;
		string encryptTxt = " ";
		string Result = " ";
	}

};

class CaeserCipher
{
private:

public:

	/**
	*
	*
	* Description:
	*           Encrypt's a string.
	*
	* Params:
	*           Shift Value
	Message
	*
	*
	* Returns:
	*           string EncryptMsg
	*/
	string Encrypt()
	{
		string EncryptMsg = " "; // Variable to store Encrypted string.
		string encryptTxt = " ";
		int shiftVal = 0;

		// Traverse Message to be encrpted.
		for (int i = 0; i < encryptTxt.length(); i++)
		{
			UpperCase(encryptTxt); // Uppercases the message. 
			if (isupper(encryptTxt[i])) //Doublecheck uppercase. 
				EncryptMsg += char(int(encryptTxt[i] + shiftVal - 65) % 26 + 65);

			// To Encrypt Lowercase letters in string.
			else
				EncryptMsg += char(int(encryptTxt[i] + shiftVal - 97) % 26 + 97);
		}

		// Returns resulting string 
		return EncryptMsg;

	}

	/**
	*
	*
	* Description:
	*           Decrypt's a string and returns the decrypted string.
	*
	* Params:
	*           Shift Value
	Message
	*
	*
	* Returns:
	*           string DecryptMsg
	*/
	string Decrypt(int shiftVal, string encryptTxt)
	{
		string DecryptMsg = " "; // Variable to store Encrypted string.

		for (int i = 0; i < encryptTxt.length(); i++)
		{
			UpperCase(encryptTxt); // Uppercases message

			if (isupper(encryptTxt[i]))
				DecryptMsg += char(int(encryptTxt[i] + (26 - shiftVal) - 65) % 26 + 65);

			// To Decrypt Lowercase letters in string.
			else
				DecryptMsg += char(int(encryptTxt[i] + (26 - shiftVal) - 97) % 26 + 97);
		}

		//Return value
		return DecryptMsg;
	}

	/**
	*
	*
	* Description:
	*           Uppercases a string.
	*
	* Params:
	*           Shift Value
	Message
	*
	*
	* Returns:
	*           Uppercased string.
	*/
	string UpperCase(string encryptTxt)
	{
		int i = 0;

		while (encryptTxt[i] != '\0')
		{
			if (encryptTxt[i] >= 'a' && encryptTxt[i] <= 'z') {
				encryptTxt[i] = encryptTxt[i] - 32;
			}
			i++;
		}
		return encryptTxt;
	}

	void SetShift()
	{

	}

	void ReadCipherText()
	{
		ofstream infile("encrypted.txt");
	}

	void WriteCipherText()
	{
		ofstream outfile("encrypted.txt");
	}

	void ReadPlainText()
	{
		fstream infile("decrypted.txt");
	}

	/**
	*
	*
	* Description:
	*      Prints output and Results
	*
	* Params:
	*      Result from Decryption Function
	*
	*
	* Returns:
	* void
	*/
	void WritePlainText(string Result)
	{
		ofstream outfile("decrypted.txt");

		outfile << Result << endl << endl;
	}
};

int main()
{
	CaeserCipher C;
	Encryption Input;

	ifstream infile;
	infile.open("encrypted.txt");

	ofstream outfile;
	outfile.open("decrypted.txt");

	outfile << "MAE-JEANNE PREVILLE" << endl;
	outfile << "Program 4: Caeser Cipher Class" << endl;
	outfile << "Date: 26 November 2019" << endl << endl;

	int totNumMsgs = 0;
	int shiftVall = 0;
	string encryptTxtt = " ";
	string Result = " ";

	infile >> totNumMsgs; //Number of messages to be read in  

	infile >> totNumMsgs >> shiftVall >> encryptTxtt;

	int ciphOperat = 0;

	//Cipher menu displayed
	cout << "Select cipher opertion of your choice. Enter 1 or 2 for your option." << endl;
	cout << "1. Encrypt" << endl;
	cout << "2. Decrypt" << endl;
	cin >> ciphOperat;

	switch (ciphOperat)
	{
	case 1:
		Result = C.Encrypt();
		outfile << Result;
		break;

	case 2:
		infile >> totNumMsgs >> shiftVall >> encryptTxtt;

		getline(infile, encryptTxtt);

		Result = C.Decrypt(shiftVall, encryptTxtt);
		outfile << Result;
		break;
	}

	infile.close();

	//system("pause");
	//return 0;
}
