#include <iostream>
#include "Functions.h"

int main() {
	menu(3, -1);
	setlocale(LC_ALL, "Russian");
	DisplayTask();
	std::cout << "Введите массив размерностью N x K = ";
	int N = ifInt();
	int K = ifInt();
	if (N != K) {
		std::cout << "Матрица должна быть квадратной для работы с диагональю.\n";
		cont();
		return 0;
	}

	int** array1 = allocate2DArray(N, K);
	input2DArray(array1, N, K);

	std::cout << "Вы ввели массив:\n";
	print2DArray(array1, N, K);

	int* array2 = allocateArray(N);
	int count = 0;
	array2 = extractEvenDiagonalElements(array1, N, count);
	unsigned long long multiply = calculate(array2, count);

	if (count == 0) {
		std::cout << "Нет чётных элементов на главной диагонали.\n";
	}
	else {
		std::cout << "Массив из элементов главной диагонали, являющихся чётными:\n";
		printArray(array2, count);
		std::cout << "\nПроизведение чётных элементов главной диагонали = " << multiply << "\n";
	}

	free2DArray(array1, N);
	delete[] array2;
	cont();
	return 0;
}