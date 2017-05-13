#pragma once
# include <iostream>


# include "Test_Cases.h"

using namespace std;
void UI()
{
	cout << " Matthew MTYu\nCOEN 244 @Concordia University 2017\n\n";

	string showhelp = "HELP";
	while (true)
	{
		if (showhelp == "HELP") {
			cout << "--------- Main Menu --------- " << endl;
		
			cout << "Please select an Option:" << endl;
			cout << "[1] Test Case 1: Player_Manager vs Opponent playing the same move" << endl;
			cout << "[2] Test Case 2: Player_Manager vs function = (i*2+i*3) % 3" << endl;
			cout << "[3] Test Case 3: Player_Manager vs scheme_2 AHP " << endl;
			cout << "[4] Test Case 4: Player_Manager vs scheme 1 random" << endl;
			cout << "[5] Test Case 5: Player_Manager vs complex pattern" << endl;
			cout << "[6] Test Case 6: Player_Manager vs itself" << endl;
		
			cout << endl;
			cout << "[10] Play user against player manager" << endl;
			cout << "[11] Play user against scheme_2 AHP" << endl;
			cout << endl;
			cout << "[20] Play user against Rock" << endl;
			cout << "[21] Play user against Rock vs Paper" << endl;

			cout << endl;

			cout << "[0] Show menu" << endl;
			cout << "[100] Quit" << endl;
			cout << "_____________________________________________" << endl;
			showhelp = "No";
		}
		try {
			cout << "\nEnter selection (enter '0' to display menu options again): ";
			int selection;
			while (!(cin >> selection))
			{
				throw "exception";
			}

			switch (selection)
			{

			case 0:
			{
				showhelp = "HELP";
				break;
			}

			case 1:
			{
				cout << "\n[1]Player_Manager vs Opponent playing the same move" << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0){
					case1(true, 1);
				}
				else { 
					case1(false, 1); 
				}

				break;
			}
			case 2:
			{
				cout << "\n[2]Player_Manager vs function = (i*2+i*3) % 3" << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0) {
					case1(true, 2);
				}
				else {
					case1(false, 2);
				}

				break;
			}
			
			case 3:
			{
				cout << "\n[3]Player_Manager vs scheme_2 AHP " << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0) {
					case1(true, 3);
				}
				else {
					case1(false, 3);
				}
				break;
			}
		
			case 4:
			{
				cout << "\n[4]Player_Manager vs scheme 1 random" << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0) {
					case1(true, 4);
				}
				else {
					case1(false, 4);
				}
				break;
			}

			case 5:
			{
				cout << "\n[5]Player_Manager vs complex pattern" << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0) {
					case1(true, 5);
				}
				else {
					case1(false, 5);
				}
				break;
			}
			
			case 6:
			{
				cout << "\n[5]Player_Manager vs complex pattern" << endl;
				int a = 0;
				cout << "\tEnter [0] to show each moved been made.\n\tEnter any other integer to show final tally only\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a == 0) {
					case1(true, 6);
				}
				else {
					case1(false, 6);
				}
				break;
		
			}

			case 10:
			{
				cout << "\n[10] Plays against player manager" << endl;
				int a = 0;
				cout << "\tEnter [0] to cheat and see in advance what player_manager will play.\n\tElse, enter any other integer\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a != 0) {
					case1(true, 10);
				}
				else {
					case1(true, 10, true);
				}
			
				break;

			}

			case 11:
			{
				cout << "\n[11] Plays against player scheme_2 AHP" << endl;
				int a = 0;
				cout << "\tEnter [0] to cheat and see in advance what player_manager will play.\n\tElse, enter any other integer\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a != 0) {
					case1(true, 11);
				}
				else {
					case1(true, 11, true);
				}

				break;

			}


			case 20:
			{
				cout << "\n[20] Plays against Rock" << endl;
				int a = 0;
				cout << "\tEnter [0] to cheat and see in advance what player_manager will play.\n\tElse, enter any other integer\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a != 0) {
					case1(true, 20);
				}
				else {
					case1(true, 20, true);
				}

				break;

			}

			case 21:
			{
				cout << "\n[21] Plays against Rock-Paper" << endl;
				int a = 0;
				cout << "\tEnter [0] to cheat and see in advance what player_manager will play.\n\tElse, enter any other integer\n";
				while (!(cin >> a))
				{
					throw "exception";
				}
				if (a != 0) {
					case1(true, 21);
				}
				else {
					case1(true, 21, true);
				}

				break;

			}

			

			case 100:
			{
				cout << "Program terminated by user." << endl;
				return;
			}
			default:
			{
				//reaches here if input is invalid, returning to main menu.
				string temp;
				cin.clear();
				getline(cin, temp);
				cout << "Invalid option, returning to main menu.\n" << endl; ;
			}
			}
		}
		catch (...) {
			cin.clear();
			string temp;
			getline(cin, temp);
			cout << "Invalid option, returning to main menu.\n" << endl;
		}
	}
}