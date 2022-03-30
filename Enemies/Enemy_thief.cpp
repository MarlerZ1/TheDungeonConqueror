#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class Enemy_thief {
private:
	int hp = 130;
	int damage = 15;
	int money = 17;
public:
	void Reborn() {
		hp = 130;
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
		return 1;
	}
	string GetClassName() {
		return "Thief";
	}
};

