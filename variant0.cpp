#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cctype>

#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

#define ALPHABET_LENGTH 26		// длина английского алфавита

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fin;				// объект fin, в котором будет открыт файл

	unsigned int lettersCount[ALPHABET_LENGTH] = { 0 }, // массив, каждый элемент которого представляет собой количество определённой буквы
	             mfreqLetterIndex = 0;                  // индекс самого частого элемента массива
	char currChar;										// буфер для посимвольного чтения из файла

	fin.open("source.txt", ios::in);          // открываем файл source.txt в режиме чтения

	if (!fin) {
		cout << "Ошибка открытия файла source.txt" << endl << "Возможно, он отсутствует? Если это так, создайте и заполните его." << endl << "[Enter]";
		cin.get();
		return 1;
	}

	while(!fin.eof()) {
		currChar = fin.get();

		if (0 <= currChar && currChar <= 0x7F)           // если символ — ASCII-буква английского алфавита, то считаем её
			if (isalpha(currChar))
				switch (tolower(currChar)) {
					case 0x61: lettersCount[0]++; break;
					case 0x62: lettersCount[1]++; break;
					case 0x63: lettersCount[2]++; break;
					case 0x64: lettersCount[3]++; break;
					case 0x65: lettersCount[4]++; break;
					case 0x66: lettersCount[5]++; break;
					case 0x67: lettersCount[6]++; break;
					case 0x68: lettersCount[7]++; break;
					case 0x69: lettersCount[8]++; break;
					case 0x6A: lettersCount[9]++; break;
					case 0x6B: lettersCount[10]++; break;
					case 0x6C: lettersCount[11]++; break;
					case 0x6D: lettersCount[12]++; break;
					case 0x6E: lettersCount[13]++; break;
					case 0x6F: lettersCount[14]++; break;
					case 0x70: lettersCount[15]++; break;
					case 0x71: lettersCount[16]++; break;
					case 0x72: lettersCount[17]++; break;
					case 0x73: lettersCount[18]++; break;
					case 0x74: lettersCount[19]++; break;
					case 0x75: lettersCount[20]++; break;
					case 0x76: lettersCount[21]++; break;
					case 0x77: lettersCount[22]++; break;
					case 0x78: lettersCount[23]++; break;
					case 0x79: lettersCount[24]++; break;
					case 0x7A: lettersCount[25]++; break;

					default: cout << "неизвестный символ. как вы сюда попали?\nаварийное завершение работы." << endl; return 1; break;
				}
	}

	fin.close();

	cout << "В тексте:" << endl;
	for (int i = 0; i < ALPHABET_LENGTH; i++) cout << lettersCount[i] << " букв " << (char)(i + 0x61) << endl;

	for (unsigned int i = 0, maxCount = lettersCount[0]; i < ALPHABET_LENGTH; i++) { // находим индекс самой частой буквы
		if (lettersCount[i] > maxCount) {
			maxCount = lettersCount[i];
			mfreqLetterIndex = i;
		}
	}

	cout << endl << "Самая частая — '" << (char)(mfreqLetterIndex + 0x61) << '\'' << endl;

	cout << endl << "[Enter]";
	cin.get();

	return 0;
}

/*
Вариант №0.
Определить чаще всего встречающуюся в заданном файле букву.
*/
