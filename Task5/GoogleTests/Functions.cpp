#include <iostream>
#include "pch.h"

int main();

int ifInt() {
	setlocale(LC_ALL, "Russian");
	int num;
	char after;
	while (true) {
		if (std::cin >> num && ((after = std::cin.peek()) == ' ' || after == '\n')) {
			std::cin.get(after);
			return num;
		}
		std::cout << "Ошибка! Введите целое число: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

void input2DArray(int** array, int rows, int cols) {
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите элементы массива размером " << rows << " x " << cols << ":\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			array[i][j] = ifInt();
		}
	}
}

void print2DArray(int** array, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void printArray(int* array, int length) {
	for (int i = 0; i < length; i++)
		std::cout << array[i] << " ";
}

int** allocate2DArray(int rows, int cols) {
	int** array = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		array[i] = new int[cols];
	}
	return array;
}

int* allocateArray(int length) {
	int* array = new int[length];
	return array;
}

void free2DArray(int** array, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;
}

void cont() {
	setlocale(LC_ALL, "Russian");
	char choice;
	while (true) {
		std::cout << "Хотите продолжить? (Y/N): ";
		std::cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			main();
			break;
		}
		else if (choice == 'N' || choice == 'n') {
			std::cout << "Завершение программы." << std::endl;
			break;
		}
		else {
			std::cout << "Некорректный ввод. Пожалуйста, введите 'Y' для продолжения или 'N' для завершения.\n";
			std::cin.ignore(10000, '\n');
		}
	}
}

void menu(short number, short var) {
	setlocale(LC_ALL, "Russian");
	std::cout << "Task " << number << " by Denis Pometko\n";
	for (int i = 0; i < 20; i++) std::cout << "x";
	std::cout << "\n";

	if (var != -1) {
		std::cout << "Variant " << var << std::endl;
		for (int i = 0; i < 20; i++) std::cout << "x";
		std::cout << "\n";
		std::cout << "Problem: ";
	}
}

int OddNumbersEvenQuality(int** array, int rows, int cols, int* resultArray, int& sum) {
	int count = 0;
	sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j += 2) {
			if (j >= cols) break;
			if (array[i][j] % 2 != 0) {
				resultArray[count++] = array[i][j];
				sum += array[i][j];
			}
		}
	}
	return count;
}
