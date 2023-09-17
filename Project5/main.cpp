#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;
void ClearCleen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
#pragma region Task1
int  AmountLine(const char* text) {
	ifstream info(text);
	int amount = 0; string cin_text;
	while (!info.eof()) {
		getline(info, cin_text);
		amount++;
	}
	if (cin_text.size() == 0)amount--;
	info.close();
	return amount--;
}
void DeleteLastLine(const char* text, const char* text_copy) {
	ifstream info(text); ofstream info_copy(text_copy);
	string cin_text;
	int amount = AmountLine("text.txt");
	while (!info.eof()) {
		amount--;
		if (amount == 0)break;
		getline(info, cin_text);
		info_copy << cin_text << endl;
	}
	cout << "������ � ������� ������� ���������!" << endl;
	info.close(); info_copy.close();
}
#pragma endregion
int  SizeLine(const char* text) {
	ifstream info(text);
	int amount = 0; string cin_text;
	while (!info.eof()) {
		getline(info, cin_text);
		if (amount < cin_text.size())amount = cin_text.size();
	}
	info.close();
	return amount;
}
void FindWord(const char* text) {
	ifstream info(text);
	string cin_text, word, word_repl; int amount = 0;
	cout << "\t����� �����\n������� �����: "; cin >> word;
	while (!info.eof()) {
		getline(info, cin_text);
		int temp_text = cin_text.find(word);
		while (temp_text != string::npos) {
			temp_text = cin_text.find(word, temp_text + word.size());
			amount++;
		}
	}
	if (amount == 0)cout << "������ ����� ����� ���� � ��������� �����!" << endl;
	else cout << "���� ����� ������������ � �������� ����� " << amount << " ����!" << endl;
	cout << "������ � ������ ������� ���������!" << endl;
	info.close();
}
void FindReplWord(const char* text, const char* text_copy) {
	ifstream info(text); ofstream info_copy(text_copy);
	string cin_text, word, word_repl; int amount = 0;
	cout << "\t������ �����\n������� ����� ������� ������ ��������: "; cin >> word;
	cout << "������� ����� �� ������� ������ ��������: "; cin >> word_repl;
	while (!info.eof()) {
		getline(info, cin_text);
		int temp_text = cin_text.find(word);
		while (temp_text != string::npos) {
			amount++;
			cin_text.replace(cin_text.begin() + temp_text, cin_text.begin() + temp_text + word.size(), word_repl);
			temp_text = cin_text.find(word, temp_text + word_repl.size());
		}
		info_copy << cin_text << endl;
	}
	if (amount == 0)cout << "������ ����� ���� � �����!";
	info.close(); info_copy.close();
	cout << "\n������ � ������� ������� ���������!" << endl;
}
void FindOneWord(const char* text) {
	ifstream info(text);
	string temp_text; char player; int amount = 0;
	cout << "\n����� ������� � ������\n������� ������: "; cin >> player;
	while (!info.eof()) {
		getline(info, temp_text);
		if (toupper(temp_text[0]) == toupper(player))amount++;
		if (temp_text.find(' ') != string::npos) {
			for (int i = temp_text.find(' '); i != temp_text.size(); i++) {
				if (isspace(temp_text[i]) && isspace(temp_text[i + 1]) == false && i != temp_text.size() - 1) {
					if (toupper(temp_text[i + 1]) == toupper(player))amount++;
				}
			}
		}
	}
	info.close();
	if (amount == 0)cout << "� ������ ���� ����� ���� ������� ����������� �� " << player << endl;
	else cout << "� ������ ���� " << amount << " ����� ���� ������� ����������� �� " << player << endl;
	cout << "������ � ������ ������� ���������!" << endl;
}
void RaplecaText(const char* text, const char* text_copy) {
	ifstream info_copy(text_copy); ofstream info(text);
	string temp_text;
	while (!info_copy.eof()) {
		getline(info_copy, temp_text);
		if (temp_text.find('1') != string::npos || temp_text.find('0') != string::npos) {
			for (int i = 0; i != temp_text.size(); i++) {
				if (temp_text[i] == '1')temp_text[i] = '0';
				else if (temp_text[i] == '0')temp_text[i] = '1';
			}

		}
		info << temp_text << endl;
	}
}
void RaplecaTextCopy(const char* text, const char* text_copy) {
	ifstream info(text); ofstream info_copy(text_copy);
	string temp_text, copy_text;
	while (!info.eof()) {
		getline(info, temp_text);
		if (temp_text.find('0') != string::npos) {
			for (int i = temp_text.find('0'); i != temp_text.size(); i++) {
				if (temp_text[i] == '0')temp_text[i] = '1';
			}
		}
		info_copy << temp_text << endl;
	}
	info.close(); info_copy.close();
	RaplecaText("text.txt", "text_copy.txt");
	cout << "���������� � ����� ������� ��������!" << endl;
}
void MassTextFile(const char* text) {
	ofstream info(text);
	vector<string> mass;
	cin.ignore();
	do {
		mass.resize(mass.size() + 1);
		ClearCleen();
		cout << "\t\t��������� ������� � ����\n������� " << mass.size() << "-�� ������� �������(������� enter ���-�� ����������)";
		getline(cin, mass[mass.size() - 1]);
	} while (mass[mass.size() - 1].empty() == false);
	for (int i = 0; i != mass.size() - 1; i++) {
		info << mass[i] << endl;
	}
	info.close();
	cout << "���������� � ����� ������� ���������!" << endl;
}
int AmountLettersWord(const char* text, int choice) {
	ifstream info(text);
	string temp_text;
	int amount = 0;
	while (!info.eof()) {
		getline(info, temp_text);
		if (choice == 8)amount += temp_text.size();
		else {
			if (temp_text.find(' ') != string::npos) {
				if (temp_text[0] != ' ')amount++;
				for (int i = temp_text.find(' '); i != temp_text.size(); i++) {
					if (i != temp_text.size() - 1 && isspace(temp_text[i]) && isspace(temp_text[i + 1]) == false)amount++;
				}
			}
			else if (temp_text.size() > 0)amount++;
		}
	}
	return amount;
}
void CensorshipFiltering(const char* text, const char* text_copy, const char* censore) {
	ifstream file(text); ofstream file1(text_copy); ifstream file3(censore);
	string temp_text, text_censore;
	while (!file.eof()) {
		getline(file, temp_text);
		while (file3 >> text_censore) {
			int temp_repl = temp_text.find(text_censore);
			while (temp_repl != string::npos) {
				temp_text.replace(temp_text.begin() + temp_repl, temp_text.begin() + temp_repl + text_censore.size(), text_censore.size(), '#');
				temp_repl = temp_text.find(text_censore, temp_repl + text_censore.size());
			}
		}
		file1 << temp_text << endl;
	}
	file.close(); file1.close(); file3.close();
	cout << "������ � ������� ������� ���������!" << endl;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int choice = 1;
	string enter;
	do {
		do {
			ClearCleen();
			cout << "   ������� ����\n[1] - �������� ������\n[2] - �������� ������\n[0] - �����\n";
			if (choice >= 0 && choice <= 2)cout << "���� �����: ";
			else cout << "������� ��� ����� �����: ";
			cin >> choice;
		} while (choice < 0 || choice>2);
		if (choice == 1) {
			do {
				ClearCleen();
				cout << "\t\t����\n[1] - �������� ��������� ������� �����\n[2] - ����� ������ ����� ������� ������ �����\n[3] - ������� ���������� ������������� ����� � �����\n[4] - ������ ����� �����\n[0] - �����";
				if (choice >= 0 && choice <= 4)cout << "��� �����: ";
				else cout << "������� ��� ����� �����: ";
				cin >> choice;
			} while (choice < 0 || choice>4);
		}
		else if (choice == 2) {
			do {
				ClearCleen();
				cout << "\t\t����\n[1] - ���������� ���� ������� ����������� �� ������������ �����\n[2] - ������ 0 �� 1 � �� ������ � ������\n[3] - ���������� ����� �� �������\n[4] - ������� ���������� �������� - � �����\n[5] - ������� ���������� ���� � �����\n[6] - ��������� ������������ ����\n[0] - �����\n";
				if (choice >= 0 && choice <= 6)cout << "��� �����: ";
				else cout << "������� ��� ����� �����: ";
				cin >> choice;
			} while (choice < 0 || choice>6);
			if (choice != 0)choice += 4;
		}
		else break;
		switch (choice) {
		case 0:break; break;
		case 1:DeleteLastLine("text.txt", "text_copy.txt"); break;
		case 2:cout << "����� ������� ������� ������� �� " << SizeLine("text.txt") << " ��������!" << endl; break;
		case 3:FindWord("text.txt"); break;
		case 4:FindReplWord("text.txt", "text_copy.txt"); break;
		case 5:FindOneWord("text.txt"); break;
		case 6:RaplecaTextCopy("text.txt", "text_copy.txt"); break;
		case 7:MassTextFile("text.txt"); break;
		case 8:cout << "� ����� ���������� " << AmountLettersWord("text.txt", choice) << " ��������" << endl; break;
		case 9:cout << "� ����� ���������� " << AmountLettersWord("text.txt", choice) << " ����" << endl; break;
		case 10:CensorshipFiltering("text.txt", "text_copy.txt", "censore.txt"); break;
		}
		cin.ignore();
		do {
			cout << "������� enter ���-�� ����������: "; getline(cin, enter);
		} while (enter.empty() == false);
	} while (choice != 0);
	return 0;
}