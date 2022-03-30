#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

template <typename player, typename enemy>
bool Battle(player &playerObject, enemy enemyObject, int* DefeatedEnemies, int ChoiceSave) {

	print("You met a " + enemyObject.GetClassName() +". Try to escape ? 1 - Yes / 2 - NO /n");
	
	bool EscapeFlag = 0;

	do {

		string choiceStr;
		cin >> choiceStr;
		if (isNum(choiceStr)) {
			if (atoi(choiceStr.c_str()) == 1) {
				EscapeFlag = 1;
				break;
			}
			if (atoi(choiceStr.c_str()) == 2) {
				break;
			}
		}
		print("Incorrect choice: ");

	} while (true);

	time_t rand = time(NULL);
	if (rand % 2 == 1 and EscapeFlag) {
		print("You have successfully escaped !/n");
		return 0;
	}
	else if (EscapeFlag) print("A failed escape attempt!/n/n/n");

	while (true)
	{
		if (EscapeFlag == 1) {
			print("The " + enemyObject.GetClassName() + " is attacking you!/n");
			
			Sleep(90);
			print("Damage received: ");
			int PlayerTakeGamage = enemyObject.GetDamage();
			playerObject.SetDamageTaken(PlayerTakeGamage);
			print(PlayerTakeGamage);
			Sleep(90);
			print("/nYour health: ");
			print(playerObject.GetHp());
			cout << "/";
			print(playerObject.GetMaxHp());
			print("/n");
			EscapeFlag = 0;
			Sleep(90);
		}


		if (playerObject.GetClass() == 1) {
			print("1 - Attack or 2 - Heal (price: 20 coins)?/n");

			do {
				string choiceStr;
				cin >> choiceStr;
				if (isNum(choiceStr)) {
					if (atoi(choiceStr.c_str()) == 2) {
						if (playerObject.GetMoney() >= 20) {
							playerObject.healing();
							Sleep(90);
							print("Your health: ");
							print(playerObject.GetHp());
							cout << "/";
							print(playerObject.GetMaxHp());
							Sleep(90);
							print("/nYour money: ");
							print(playerObject.GetMoney());
							print("/n/n");
							break;
						}
						else {
							print("You don't have enough coins (");
							print(playerObject.GetMoney());
							print("/20)");
						}
					}
					if (atoi(choiceStr.c_str()) == 1) {
						print("/n");
						print("You're doing damage: ");
						int EnemyTakeGamage = playerObject.GetDamage();
						print(EnemyTakeGamage);
						Sleep(90);
						enemyObject.SetDamageTaken(EnemyTakeGamage);
						print("/n" + enemyObject.GetClassName() + " Health: ");
						print(enemyObject.GetHp());
						print("/n/n");
						Sleep(90);
						break;
					}
				}
			} while (true);
		}
		else if (playerObject.GetClass() == 2) {
			print("1 - Attack or 2 - Heal (price: 20 coins) or 3 - Recovery Mp ?/n");
			do {
				string choiceStr;
				cin >> choiceStr;
				if (isNum(choiceStr)) {
					if (atoi(choiceStr.c_str()) == 2) {
						if (playerObject.GetMoney() >= 20) {
							playerObject.healing();
							Sleep(90);
							print("Your health: ");
							print(playerObject.GetHp());
							cout << "/";
							print(playerObject.GetMaxHp());
							Sleep(90);
							print("/nYour money: ");
							print(playerObject.GetMoney());
							print("/n/n");
							break;
						}
						else {
							print("You don't have enough coins (");
							print(playerObject.GetMoney());
							print("/20)");
						}
					} else
					if (atoi(choiceStr.c_str()) == 1) {
						print("/n");
						print("You're doing damage: ");
						int EnemyTakeGamage = playerObject.GetDamage();
						print(EnemyTakeGamage);
						Sleep(90);
						print("/nYour mana: ");
						print(playerObject.GetMp());
						cout << "/";
						print(playerObject.GetMaxMp());
						print("/n");
						Sleep(90);
						enemyObject.SetDamageTaken(EnemyTakeGamage);
						print("/n" + enemyObject.GetClassName() + " Health: ");
						print(enemyObject.GetHp());
						print("/n/n");
						Sleep(90);
						break;
					} else
					if (atoi(choiceStr.c_str()) == 3) {
						playerObject.MpRecovery();
						print("Your Mp: ");
						print(playerObject.GetMp());
						cout << "/";
						print(playerObject.GetMaxMp());
						print("/n/n");
						Sleep(90);
						break;
					}
				}
			} while (true);
		}


		if (enemyObject.GetHp() <= 0) {
			print("/n/nYou killed a " + enemyObject.GetClassName() + "!/n/n");
			enemyObject.Reborn();
			(*DefeatedEnemies)++;
			break;
		}

		if (enemyObject.GetClass() == 1) print("The " + enemyObject.GetClassName() + " is attacking you!/n");
		Sleep(90);
		print("Damage received: ");
		int PlayerTakeGamage = enemyObject.GetDamage();
		playerObject.SetDamageTaken(PlayerTakeGamage);
		print(PlayerTakeGamage);
		Sleep(90);
		print("/nYour health: ");
		print(playerObject.GetHp());
		cout << "/";
		print(playerObject.GetMaxHp());
		print("/n");
		EscapeFlag = 0;
		Sleep(90);

	}
	print("/n/nYou have received ");
	print(enemyObject.GetMoney());
	print(" coins./n");
	playerObject.setMoney(enemyObject.GetMoney());
	print("You have ");
	print(playerObject.GetMoney());
	print(" coins now./n");

	if (*DefeatedEnemies >= playerObject.GetLvl() * 2) {
		Sleep(90);
		print("/nYou've got a new level: ");
		playerObject.newLevel();
		print(playerObject.GetLvl());
		print("/n/n");


		ofstream SaveGameWriteHelper("SaveGameHelper.save");
		ifstream SaveRead("save.save");
		string Buffer = "";

		if (ChoiceSave != 1) {
			getline(SaveRead, Buffer);
			SaveGameWriteHelper << Buffer;
		}

		for (int i = 0; i < ChoiceSave - 2; i++) {
			getline(SaveRead, Buffer);
			SaveGameWriteHelper << "\n" << Buffer;
		}
		getline(SaveRead, Buffer);

		if (ChoiceSave != 1) {
			SaveGameWriteHelper << endl << playerObject.GetName() << 
				":"+ to_string(playerObject.GetClass()) +":" << 
					playerObject.GetLvl() << ":" << playerObject.GetMoney() << 
						":" << playerObject.GetHp() << ":" << playerObject.GetMp() << ":";
		}
		else {
			SaveGameWriteHelper << playerObject.GetName() <<
				":" + to_string(playerObject.GetClass()) + ":" <<
				 	playerObject.GetLvl() << ":" << playerObject.GetMoney() << ":" << 
					  	playerObject.GetHp() << ":" << playerObject.GetMp() << ":";
		}

		while (!SaveRead.eof()) {
			getline(SaveRead, Buffer);
			SaveGameWriteHelper << "\n" << Buffer;
		}

		SaveGameWriteHelper.close();
		SaveRead.close();

		remove("save.save");

		ofstream SaveWrite("save.save");
		ifstream SaveGameReadHelper("SaveGameHelper.save");

		getline(SaveGameReadHelper, Buffer);
		SaveWrite << Buffer;

		while (!SaveGameReadHelper.eof()) {
			getline(SaveGameReadHelper, Buffer);
			SaveWrite << endl << Buffer;
		}
		SaveWrite.close();
		SaveGameReadHelper.close();

		remove("SaveGameHelper.save");

		*DefeatedEnemies = 0;
	}
}

