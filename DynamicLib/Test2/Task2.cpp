#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	menu(2, 9);
	DisplayTask();
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib.dll");
	typedef double (__stdcall *RecursionFunc) (int* array, int start, int end, bool isFirstThird);
	RecursionFunc Recursion = (RecursionFunc)GetProcAddress(load, "Recursion");
	std::cout << "¬ведите размер массива - ";
	int N = ifInt();
	int* a = new int[N];
	std::cout << "¬ведите элементы массива: " << std::endl;
	for (int i = 0; i < N; i++) {
		a[i] = ifInt();
	}
	double result1 = Recursion(a, 0, N / 3 - 1, true);
	double result2 = Recursion(a, N / 3, N - 1, false);
	std::cout << "–езультат - " << result1 * result2 << std::endl;
	delete[] a;
	FreeLibrary(load);
	cont();
}