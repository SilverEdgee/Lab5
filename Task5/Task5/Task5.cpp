#include <iostream>
#include "Functions.h"

int main() {
	menu(3, -1);
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������ ������������ N x K = ";
	int N = ifInt();
	int K = ifInt();

	int** array1 = allocate2DArray(N, K);
	input2DArray(array1, N, K);

	std::cout << "�� ����� ������:\n";
	print2DArray(array1, N, K);

	int* array2 = allocateArray(N * K);
	int sum = 0;
	int count = OddNumbersEvenQuality(array1, N, K, array2, sum);
	if (count == 0) {
		std::cout << "��� �������� ��������� �� ������ ��������.\n";
	}
	else {
		std::cout << "������ �� �������� ���������, ������������� �� ������ ��������:\n";
		printArray(array2, count);
		std::cout << "\n������� �������������� ����� ��������� = " << static_cast<double>(sum) / count << "\n";
	}

	free2DArray(array1, N);
	delete[] array2;

	return 0;
}