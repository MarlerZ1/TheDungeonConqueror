#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

#include "Functions.cpp"
#include "Battle.cpp"

#include "Enemies/Enemy_thief.cpp"
#include "Enemies/Enemy_skeleton_archer.cpp"
#include "Enemies/Enemy_weak_demon.cpp"
#include "Enemies/Enemy_demon.cpp"
#include "Enemies/Enemy_death_claw.cpp"

#include "PlayerClasses/knight.cpp"
#include "PlayerClasses/wizard.cpp"
using namespace std;

int main() {
	
	cout << "\n\n\n\n\n\n					Welcome to 'The Dungeon Conqueror'! \n ";
	cout << "\n\n\n			Please wait for the end of the message output before entering actions. \n\n\n";
	cout << "\n					      Press any key to start";
	
	while (true) {
		if (_getch()) break;
	}
	
	
	
	int ClassChoice = 0;
	int ChoiceSave = 0;
	int GameStartchoice = 0;
	
	knight playerKnight;
	wizard playerWizard;

	bool flag = false;

	while (!flag) {

		ifstream SaveRead("save.save");
		ofstream SaveWrite("save.save", ios::app);

		system("cls");

		print("1 - New Game/n2 - Upload a save/n");

		GameStartchoice = 0;
		do {

			string choiceStr;
			cin >> choiceStr;
			if (isNum(choiceStr)) GameStartchoice = atoi(choiceStr.c_str());
			if (GameStartchoice < 1 or GameStartchoice > 2)  print("Incorrect choice: ");

		} while (GameStartchoice < 1 or GameStartchoice > 2);



		if (GameStartchoice == 1) {
			flag = 1;
			system("cls");

			print("Select a class:/n1 - Knight/n2 - Wizard/n");



			do {
				string choiceStr;
				cin >> choiceStr;
				if (isNum(choiceStr)) ClassChoice = atoi(choiceStr.c_str());
				if (ClassChoice < 1 or ClassChoice > 2) print("Incorrect choice: ");

			} while (ClassChoice < 1 or ClassChoice > 2);

			
			print("Enter the name of the character:/n");
			string name;

			do {
				cin >> name;
				if (!correctName(name)) print("Incorrect name/n");
			} while (!correctName(name));
			
			
			
			if (ClassChoice == 1) playerKnight.SetName(name);
			else playerWizard.SetName(name);

			SaveWrite << name << ":" << ClassChoice << ":1:0:";
			if (ClassChoice == 1) SaveWrite << "600:100:\n";
			else SaveWrite << "150:600:\n";
			
			string gameSaves;
			while (!SaveRead.eof()) {
				getline(SaveRead, gameSaves);
				ChoiceSave++;
			}
		
			SaveRead.close();
			SaveWrite.close();


			system("cls");
		}
		else if (GameStartchoice == 2) {
			system("cls");
			string gameSaves;
			getline(SaveRead, gameSaves);
			if (gameSaves == "") {
				print("No saved games/nBack?");
				string crutch;
				cin >> crutch;

			}
			else {
				int score = 1;
				print("Select a save cell: /n");
				do {
					int SeparatorCountCounter = 0;
					for (int i = 0; i < gameSaves.length(); i++) {
						if (gameSaves[i] == ':') SeparatorCountCounter++;
						if (SeparatorCountCounter > 6) break;
					}
					if (SeparatorCountCounter != 6) {
							cout << "SAVE ERROR";
							exit(0);
					}
					
					print(score);
					print(" - ");

					int i = 0;
					while (gameSaves[i] != ':') {
						print(gameSaves[i]);
						i++;
					}
					cout << " ";
					i++;
					
					string ClassChoiceStr = "";
					while (gameSaves[i] != ':') {
						ClassChoiceStr += gameSaves[i];
						i++;
					}
					i++;
					if (!isNum(ClassChoiceStr) or (ClassChoiceStr != "1" and  ClassChoiceStr != "2")) {
						print(" SAVE ERROR ");
						exit(0);
					}
					switch (atoi(ClassChoiceStr.c_str())) {
						case 1:
							print(" Knight ");
							break;
						case 2:
							print(" Wizard ");
							break;
					}
					
					string LvlStr = "";
					while (gameSaves[i] != ':') {
						LvlStr += gameSaves[i];
						i++;
					}
					i++;
					if (!isNum(LvlStr) or atoi(LvlStr.c_str()) < 1) {
						print(" SAVE ERROR ");
						exit(0);
					}
					print(LvlStr);
					print(" Lvl");


					string moneyStr = "";
					while (gameSaves[i] != ':') {
						moneyStr += gameSaves[i];
						i++;
					}
					if (!isNum(moneyStr) or atoi(moneyStr.c_str()) < 0) {
						print(" SAVE ERROR ");
						exit(0);
					}
					i ++;
					print(" Money - ");
					print(moneyStr);
					print(" ");

					string hpStr = "";
					while (gameSaves[i] != ':') {
						hpStr += gameSaves[i];
						i++;
					}
					if (!isNum(hpStr) or atoi(hpStr.c_str()) < 0) {
						print(" SAVE ERROR ");
						exit(0);
					}
					print(" HP - ");
					print(hpStr);
					print(" ");
					i++;
					
					string mpStr = "";
					while (gameSaves[i] != ':') {
						mpStr += gameSaves[i];
						i++;
					}
					if (!isNum(mpStr) or atoi(mpStr.c_str()) < 0) {
						print(" SAVE ERROR ");
						exit(0);
					}
					print(" MP - ");
					print(mpStr);
					print("/n");

					getline(SaveRead, gameSaves);
					score++;
				} while (!SaveRead.eof());
				
				do {
					string choiceStr;
					cin >> choiceStr;
					if (isNum(choiceStr)) ChoiceSave = atoi(choiceStr.c_str());

					if (ChoiceSave < 1 or ChoiceSave > score - 1) print("Incorrect choice: ");

				} while (ChoiceSave < 1 or ChoiceSave > score - 1);
				
				SaveRead.close();
				ifstream SaveRead("save.save");
				
				for (int i = 0; i < ChoiceSave; i++) {
					getline(SaveRead, gameSaves);
				}
				
				int i = 0;
				string name = "";
				while (gameSaves[i] != ':') {
					name += gameSaves[i];
					i++;
				}
				i++;
				ClassChoice = gameSaves[i] - '0';
				i += 2;
				int lvl = gameSaves[i] - '0';
				i += 2;
				string moneyStr = "";
				while (gameSaves[i] != ':') {
					moneyStr += gameSaves[i];
					i++;
				}
				i++;
				string hpStr = "";
				while (gameSaves[i] != ':') {
					hpStr += gameSaves[i];
					i++;
				}
				i++;
				string mpStr = "";
				while (gameSaves[i] != ':') {
					mpStr += gameSaves[i];
					i++;
				}
				switch (ClassChoice) {
				case 1:
					playerKnight.SetName(name);
					playerKnight.SetLvl(lvl);
					playerKnight.setHpAndMp(atoi(hpStr.c_str()), atoi(mpStr.c_str()));
					playerKnight.setMoney(atoi(moneyStr.c_str()));
					break;
				case 2:
					playerWizard.SetName(name);
					playerWizard.SetLvl(lvl);
					playerWizard.setHpAndMp(atoi(hpStr.c_str()), atoi(mpStr.c_str()));
					playerWizard.setMoney(atoi(moneyStr.c_str()));
					break;
				}
				system("cls");
				flag = 1;
				
				SaveRead.close();
				SaveWrite.close();
			}
		}
	}
	
	if (ClassChoice == 1) playerKnight.GetSpecifications();
	else playerWizard.GetSpecifications();

	if (GameStartchoice == 1) print("Do you want to start your adventure ?/n1 - Yes / 2 - No ");
	else print("Do you want to continue your adventure ?/n1 - Yes / 2 - No ");

	do {
		string choiceStr;
		cin >> choiceStr;
		if (isNum(choiceStr)) {
			if (atoi(choiceStr.c_str()) == 2) exit(0);
			if (atoi(choiceStr.c_str()) == 1) break;
		}
	} while (true);

	Enemy_thief thief;
	Enemy_skeleton_archer skeleton_archer;
	Enemy_weak_demon weak_demon;
	Enemy_demon demon;
	Enemy_death_claw death_claw;

	int DefeatedEnemies = 0;
	if (ClassChoice == 1) {
		while (true) {

			print("/nTo exit the game, press 'ESC'. Press to continue/n/n");
			if (_getch() == 27) exit(0);

			time_t rand;
			switch (playerKnight.GetLvl()) {
				case 1:
					Battle(playerKnight, thief, &DefeatedEnemies, ChoiceSave);
					break;
				case 2:
					rand = time(NULL) % 2;
					switch (rand) {
						case 1:
							Battle(playerKnight, skeleton_archer, &DefeatedEnemies, ChoiceSave);
							break;
						default:
							Battle(playerKnight, thief, &DefeatedEnemies, ChoiceSave);
							break;
					}
					break;
				case 3:
					rand = time(NULL) % 3;
					switch (rand) {
						case 1:
							Battle(playerKnight, skeleton_archer, &DefeatedEnemies, ChoiceSave);
							break;
						case 2:
							Battle(playerKnight, weak_demon, &DefeatedEnemies, ChoiceSave);
							break;
						default:
							Battle(playerKnight, thief, &DefeatedEnemies, ChoiceSave);
							break;
					}
					break;
				case 4:
					rand = time(NULL) % 4;
					switch (rand) {
					case 1:
						Battle(playerKnight, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					case 2:
						Battle(playerKnight, weak_demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 3:
						Battle(playerKnight, demon, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerKnight, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;
				default:
					rand = time(NULL) % 5;
					switch (rand) {
					case 1:
						Battle(playerKnight, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					case 2:
						Battle(playerKnight, weak_demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 3:
						Battle(playerKnight, demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 4:
						Battle(playerKnight, death_claw, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerKnight, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;

			}
		}
	}

	else {
		while (true) {

			print("/nTo exit the game, press 'ESC'. Press to continue/n/n");
			if (_getch() == 27) exit(0);

			time_t rand;
			switch (playerWizard.GetLvl()) {
				case 1:
					Battle(playerWizard, thief, &DefeatedEnemies, ChoiceSave);
					break;
				case 2:
					rand = time(NULL) % 2;
					switch (rand) {
					case 1:
						Battle(playerWizard, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerWizard, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;
				case 3:
					rand = time(NULL) % 3;
					switch (rand) {
					case 1:
						Battle(playerWizard, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					case 2:
						Battle(playerWizard, weak_demon, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerWizard, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;
				case 4:
					rand = time(NULL) % 4;
					switch (rand) {
					case 1:
						Battle(playerWizard, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					case 2:
						Battle(playerWizard, weak_demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 3:
						Battle(playerWizard, demon, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerWizard, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;
				default:
					rand = time(NULL) % 5;
					switch (rand) {
					case 1:
						Battle(playerWizard, skeleton_archer, &DefeatedEnemies, ChoiceSave);
						break;
					case 2:
						Battle(playerWizard, weak_demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 3:
						Battle(playerWizard, demon, &DefeatedEnemies, ChoiceSave);
						break;
					case 4:
						Battle(playerWizard, death_claw, &DefeatedEnemies, ChoiceSave);
						break;
					default:
						Battle(playerWizard, thief, &DefeatedEnemies, ChoiceSave);
						break;
					}
					break;

			}
		}
	}

}
