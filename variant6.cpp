#include <iostream>
#include <fstream>
#include <Windows.h>

#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int charsPerLine = -1;
	char singleLine[256] = { 0 };

	ifstream fin;				// объект fin, в котором будет открыт файл
	ofstream fout;

	fin.open("source.txt", ios::in);
	if (!fin) {
		cout << "Ошибка открытия файла source.txt" << endl << "Возможно, он отсутствует? Если это так, создайте и заполните его." << endl << "[Enter]";
		cin.get();
		return 1;
	}

	fout.open("dest.txt", ios::out | ios::trunc);
	if (!fout) {
		cout << "Ошибка создания выходного файла dest.txt" << endl << "Проверьте права записи в каталог с программой и наличие свободного места." << endl << "[Enter]";
		cin.get();
		return 1;
	}

	do {
		cout << "Введите количество символов, которое должно содержаться в одной строке: ";
		cin >> charsPerLine;
		if (!cin) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (!charsPerLine);

	cout << "Запись в файл dest.txt строк:" << endl;
	while (!fin.eof()) {
		fin.get(singleLine, charsPerLine + 1);
		cout << singleLine << endl;
		fout << singleLine << endl;
	}

	fout.close();
	fin.close();
	
	cout << endl << "[Enter]";
	cin.get();

	return 0;
}

/*
Вариант №6.
Разбить входной файл (состоящий из одной строки не более 256 символов) на файл,
содержащий информацию из входного, разбитого на строки,
каждая размером соответствующая числу, вводимому с клавиатуры
*/
