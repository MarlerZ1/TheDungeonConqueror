#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

class wizard {
private:
	int hp = 150;
	int maxHp = 150;
	int mp = 600;
	int maxMp = 600;
	int damage = 200;
	int lvl = 1;
	int money = 0;
	string name;
	
public:
	void healing() {
		hp += 75;
		if (hp > maxHp) hp = maxHp;
		money -= 20;
	}


	void SetName(string name) {
		this->name = name;
	}

	void MpRecovery() {
		mp += (maxMp / 4);
		if (mp > maxMp) mp = maxMp;
	}

	void newLevel() {
		lvl++;
		damage += 0.1 * lvl * damage;
		maxHp += 0.1 * lvl * hp;
		maxMp += 0.1 * lvl * mp;
		hp += 0.3 * maxHp;
		mp += 0.3 * maxMp;
		if (hp > maxHp) hp = maxHp;
		if (mp > maxMp) mp = maxMp;
	}

	void setHpAndMp(int hp, int mp) {
		this->hp = hp;
		this->mp = mp;
	}

	void SetLvl(int lvl) {
		this->lvl = lvl;
		cout << mp << endl;
		for (int i = 2; i <= this->lvl; i++) {
			damage += 0.1 * i * damage;
			maxHp += 0.1 * i * hp;
			maxMp += 0.1 * i * mp;
		}
	}

	void SetDamageTaken(int damage) {
		hp -= damage;
		if (hp <= 0) {
			hp = 0;
			system("cls");
			print("YOU DIED!");
			exit(0);
		}
	}

	void setMoney(int money) {
		this->money += money;
	}

	int GetMp() {
		return mp;
	}

	int GetMaxMp() {
		return maxMp;
	}

	int GetHp() {
		return hp;
	}

	int GetMaxHp() {
		return maxHp;
	}

	int GetDamage() {
		mp -= 150;
		if (mp < 0) mp = 0;
		return damage;
	}

	int GetMoney() {
		return money;
	}

	string GetName() {
		return name;
	}

	int GetLvl() {
		return lvl;
	}

	int GetClass() {
		return 2;
	}
	void GetSpecifications() {
		print("Name - ");
		print(name);
		print("/nLvl - ");
		print(lvl);
		print("/nHP - ");
		print(hp);
		cout << "/";
		print(maxHp);
		print("/nMP - ");
		print(mp);
		cout << "/";
		print(maxMp);
		print("/nDamage - ");
		print(damage);
		print("/nMoney - ");
		print(money);
		print("/n");
	}
};
