#include <iostream>
#include <fstream>
#include <cctype>
#include <Windows.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fin; // 10 lines 100 (or 101) characters each
	ofstream fout; 
	int lettersCount = 0, digitsCount = 0;
	char currChar;

	fin.open("source.txt", ios::in);

	if (!fin) {
		cout << "Ошибка открытия файла source.txt" << endl << "Возможно, он отсутствует? Если это так, создайте и заполните его." << endl << "[Enter]";
		cin.get();
		return 1;
	}
	
	while (!fin.eof()) {
		currChar = fin.get();
		if (currChar <= 0x7F && currChar >= 0)
			if (isdigit(currChar)) //cout << "fount digit! digitsCount = " << ++digitsCount << endl;
				digitsCount++;
			else if (isalpha(currChar)) //cout << "found letter! lettersCount = " << ++lettersCount << endl;
				lettersCount++;
			//else if (iscntrl(currChar)) cout << "found control symbol" << endl;
	}
	cout << "Всего цифр: " << digitsCount << endl << "Всего букв: " << lettersCount << endl;
	
	fin.clear();
	fin.seekg(0);

	if (digitsCount >= lettersCount) {    // write digits only to the file
		cout << endl << "Записываем в файл только цифры" << endl;
		
		fout.open("dest.txt", ios::trunc);

		while (!fin.eof()) {
			currChar = fin.get();
			if (currChar <= 0x7F && currChar >= 0)
				if (isdigit(currChar) || iscntrl(currChar)) fout.put(currChar);
		}

		fout.close(); 
		cout << "Результат работы смотрите в файле destDigits.txt по месту запуска программы" << endl;
	}
	else {                                // wrire letters only to the file
		cout << "Записываем в файл только буквы" << endl;
		
		fout.open("destLetters.txt", ios::trunc);

		while (!fin.eof()) {
			currChar = fin.get();
			if (currChar <= 0x7F && currChar >= 0)
				if (isalpha(currChar) || iscntrl(currChar)) fout.put(currChar);
		}

		cout << "Результат работы смотрите в файле destLetters.txt по месту запуска программы" << endl;
	}

	fin.close();

	cout << endl << "[Enter]";
	cin.get();

	return 0;
}

/*
Вариант 7.
Подсчитать в исходном файле количество цифр и символов.
В выходной файл записать те данные, количество которых больше.
*/