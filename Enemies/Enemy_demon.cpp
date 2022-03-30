#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class Enemy_demon {
private:
	int hp = 720;
	int damage = 100;
	int money = 71;
public:
	void Reborn() {
		hp = 720;
	}
	void SetDamageTaken(int damage) {
		hp -= damage;
		if (hp < 0) hp = 0;
	}

	int GetHp() {
		return hp;
	}

	int GetDamage() {
		return damage;
	}

	int GetMoney() {
		return money;
	}
	int GetClass() {
		return 4;
	}
	string GetClassName() {
		return "Demon";
	}
};
