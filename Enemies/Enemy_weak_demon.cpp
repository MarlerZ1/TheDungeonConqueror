#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class Enemy_weak_demon {
private:
	int hp = 350;
	int damage = 60;
	int money = 37;
public:
	void Reborn() {
		hp = 350;
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
		return 3;
	}
	string GetClassName() {
		return "Weak Demon";
	}
};

