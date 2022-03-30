#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class Enemy_death_claw {
private:
	int hp = 1000;
	int damage = 150;
	int money = 143;
public:
	void Reborn() {
		hp = 1000;
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
		return 5;
	}
	string GetClassName() {
		return "Death Claw";
	}
};
