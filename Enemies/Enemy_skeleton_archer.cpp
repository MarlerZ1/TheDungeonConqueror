#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

class Enemy_skeleton_archer {
private:
	int hp = 200;
	int damage = 35;
	int money = 25;
public:
	void Reborn() {
		hp = 200;
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
		return 2;
	}
	string GetClassName() {
		return "Skeleton archer";
	}
};
