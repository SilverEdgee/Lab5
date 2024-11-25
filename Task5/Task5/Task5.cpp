#include <iostream>
#include "Functions.h"

int main() {
	menu(3, -1);
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите массив размерностью N x K = ";
	int N = ifInt();
	int K = ifInt();

	int** array1 = allocate2DArray(N, K);
	input2DArray(array1, N, K);

	std::cout << "Вы ввели массив:\n";
	print2DArray(array1, N, K);

	int* array2 = allocateArray(N * K);
	int sum = 0;
	int count = OddNumbersEvenQuality(array1, N, K, array2, sum);
	if (count == 0) {
		std::cout << "Нет нечётных элементов на чётных столбцах.\n";
	}
	else {
		std::cout << "Массив из нечётных элементов, расположенных на чётных столбцах:\n";
		printArray(array2, count);
		std::cout << "\nСреднее арифметическое таких элементов = " << static_cast<double>(sum) / count << "\n";
	}

	free2DArray(array1, N);
	delete[] array2;

	return 0;
}