#include <iostream>
#include "../staticlib/staticlib.h"

int main() {
	menu(1, 9);
	displayTask();
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размер массива N x N: ";
	int n = ifInt();
	int** a = allocate2DArray(n, n);
	Change_elements_task_1(a, n);
	int** b = allocate2DArray(n, n);
	Transform_matrix(a, b, n);
	std::cout << "Первоначальная матрица: " << std::endl;
	print2DArray(a, n, n);
	std::cout << "Транспонированная матрица: " << std::endl;
	print2DArray(b, n, n);
	int sum_A = Sum_of_A(a, n);
	int sum_B = Sum_of_B(b, n);
	std::cout << "Сумма первой матрицы: " << sum_A << std::endl;
	std::cout << "Сумма второй матрицы: " << sum_B << std::endl;
	free2DArray(a, n);
	free2DArray(b, n);
	cont();
}