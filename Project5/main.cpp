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
	cout << "Работа с файлами успешно закончена!" << endl;
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
	cout << "\tПоиск слова\nВведите слово: "; cin >> word;
	while (!info.eof()) {
		getline(info, cin_text);
		int temp_text = cin_text.find(word);
		while (temp_text != string::npos) {
			temp_text = cin_text.find(word, temp_text + word.size());
			amount++;
		}
	}
	if (amount == 0)cout << "Вашего слова слова нету в текстовом файле!" << endl;
	else cout << "Ваше слово встречаеться в тексовом файле " << amount << " раза!" << endl;
	cout << "Работа с файлом успешно закончена!" << endl;
	info.close();
}
void FindReplWord(const char* text, const char* text_copy) {
	ifstream info(text); ofstream info_copy(text_copy);
	string cin_text, word, word_repl; int amount = 0;
	cout << "\tЗамена слова\nВведите слово которое хотите заменить: "; cin >> word;
	cout << "Введите слово на которое хотите заменить: "; cin >> word_repl;
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
	if (amount == 0)cout << "Вашего слова нету в файле!";
	info.close(); info_copy.close();
	cout << "\nРабота с файлами успешно закончена!" << endl;
}
void FindOneWord(const char* text) {
	ifstream info(text);
	string temp_text; char player; int amount = 0;
	cout << "\nПоиск символа в словах\nВведите символ: "; cin >> player;
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
	if (amount == 0)cout << "В тексте нету таких слов которые начинаються на " << player << endl;
	else cout << "В тексте есть " << amount << " таких слов которые начинаються на " << player << endl;
	cout << "Работа с файлом успешно закончена!" << endl;
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
	cout << "Информация в файле успешно заменена!" << endl;
}
void MassTextFile(const char* text) {
	ofstream info(text);
	vector<string> mass;
	cin.ignore();
	do {
		mass.resize(mass.size() + 1);
		ClearCleen();
		cout << "\t\tЗапонение массива в файл\nВведите " << mass.size() << "-ый элемент массива(введите enter что-бы продолжить)";
		getline(cin, mass[mass.size() - 1]);
	} while (mass[mass.size() - 1].empty() == false);
	for (int i = 0; i != mass.size() - 1; i++) {
		info << mass[i] << endl;
	}
	info.close();
	cout << "Информация в файле успешно заполнена!" << endl;
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
	cout << "Работа с файлами успешно закончена!" << endl;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int choice = 1;
	string enter;
	do {
		do {
			ClearCleen();
			cout << "   Главное меню\n[1] - Классная работа\n[2] - Домашняя работа\n[0] - Выход\n";
			if (choice >= 0 && choice <= 2)cout << "Вваш выбор: ";
			else cout << "Введите ваш выбор снова: ";
			cin >> choice;
		} while (choice < 0 || choice>2);
		if (choice == 1) {
			do {
				ClearCleen();
				cout << "\t\tМеню\n[1] - Удаление последней строчки файла\n[2] - Найти длинну самой длинной строки файла\n[3] - Подсчет количества определенного слова в файле\n[4] - Замена слова файла\n[0] - Выйти";
				if (choice >= 0 && choice <= 4)cout << "Ваш выбор: ";
				else cout << "Введите ваш выбор снова: ";
				cin >> choice;
			} while (choice < 0 || choice>4);
		}
		else if (choice == 2) {
			do {
				ClearCleen();
				cout << "\t\tМеню\n[1] - Количество слов которые начинаються на определенную букву\n[2] - Замена 0 на 1 и на оборот в файлах\n[3] - Заполнение файла из массива\n[4] - Подсчет количества символов - в файле\n[5] - Подсчет количества букв в файле\n[6] - Фиьтрация нерпиемлимых слов\n[0] - Выйти\n";
				if (choice >= 0 && choice <= 6)cout << "Ваш выбор: ";
				else cout << "Введите ваш выбор снова: ";
				cin >> choice;
			} while (choice < 0 || choice>6);
			if (choice != 0)choice += 4;
		}
		else break;
		switch (choice) {
		case 0:break; break;
		case 1:DeleteLastLine("text.txt", "text_copy.txt"); break;
		case 2:cout << "Самая длинная строчка состоит из " << SizeLine("text.txt") << " символов!" << endl; break;
		case 3:FindWord("text.txt"); break;
		case 4:FindReplWord("text.txt", "text_copy.txt"); break;
		case 5:FindOneWord("text.txt"); break;
		case 6:RaplecaTextCopy("text.txt", "text_copy.txt"); break;
		case 7:MassTextFile("text.txt"); break;
		case 8:cout << "В файле находиться " << AmountLettersWord("text.txt", choice) << " символов" << endl; break;
		case 9:cout << "В файле находиться " << AmountLettersWord("text.txt", choice) << " слов" << endl; break;
		case 10:CensorshipFiltering("text.txt", "text_copy.txt", "censore.txt"); break;
		}
		cin.ignore();
		do {
			cout << "Нажмите enter что-бы продолжить: "; getline(cin, enter);
		} while (enter.empty() == false);
	} while (choice != 0);
	return 0;
}