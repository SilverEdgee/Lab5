#include <iostream>

extern "C" double __declspec(dllexport)  __stdcall Recursion(int* array, int start, int end, bool isFirstThird) {
	int length = end - start + 1;
	if (length == 1) {
		if (isFirstThird) {
			return array[start] * array[start] + cos(array[start]);
		}
		else return sin(array[start]) - cos(array[start]);
	}
	if (length == 2) {
		if (isFirstThird) {
			return (array[start] * array[start] + cos(array[start])) * (array[start + 1] * array[start + 1] + cos(array[start + 1]));
		}
		else return (sin(array[start]) - cos(array[start])) * (sin(array[start + 1]) - cos(array[start + 1]));
	}
	int oneThird = length / 3;
	int secondPartStart = oneThird + start;
	double FirstPart = Recursion(array, start, start + oneThird - 1, isFirstThird);
	double SecondPart = Recursion(array, secondPartStart, end, isFirstThird);
	return FirstPart * SecondPart;
}

