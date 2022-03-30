#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

bool isNum(string choice) {
	int i = 0;
	int score = 0;
	for (i; i < choice.size(); i++) {
		if (isdigit(choice[i])) score++;
	}
	if (i == score) return 1;
	else {
		return 0;
	}
}


bool correctName(string name){
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ':' or name.length() > 10) return 0;
	}
	return 1;
}

void print(string strOne) {
	for (int i = 0; i < strOne.length(); i++) {
		if (strOne[i] != '/' or (strOne[i + 1] != 'n' and i + 1 < strOne.length())) {
			cout << strOne[i];
			Sleep(35);
			Beep(14000, 1);
		}
		else {
			cout << endl;
			i++;
		}
	}
}

void print(char charMessage) {
	cout << charMessage;
	Sleep(35);
	Beep(14000, 1);
		
}
void print(int intMessage) {
	cout << intMessage;
	Sleep(35);
	Beep(14000, 1);

}

