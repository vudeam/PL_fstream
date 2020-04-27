#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cctype>

#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char currChar;

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

	while (!fin.eof()) {
		fin >> currChar;
		if (0 <= currChar && currChar <= 0x7A)
			if (isdigit(currChar)) {
				cout << "Записываем в файл цифру: '" << currChar << '\'' << endl;
				fout << currChar;
			}
	}

	fin.clear();
	fin.seekg(0);
	fin.unsetf(ios::skipws);
	fout.clear();
	fout.close();
	fout.open("dest.txt", ios::app);

	while (!fin.eof()) {
		fin >> currChar;
		if (0x2F >= currChar || currChar >= 0x3A) {
			cout << "Записываем в файл символ: '" << currChar << '\'' << endl;
			fout << currChar;
		}
	}

	fout.close();
	fin.close();

	cout << endl << "[Enter]";
	cin.get();

	return 0;
}

/*
Вариант №9.
Записать в выходной файл данные из исходного.
Данные выходного файла должны располагаться в следующем порядке:
сначала все цифры, а потом все остальные символы.
*/
