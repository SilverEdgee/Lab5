#pragma once
#include <iostream>

// Функции для работы с массивами
int** allocate2DArray(int rows, int cols);
void free2DArray(int** array, int rows);
int* allocateArray(int length);
void input2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
void printArray(int* array, int length);
int OddNumbersEvenQuality(int** array, int rows, int cols, int* resultArray, int& sum);

// Вспомогательные функции
int ifInt();
void cont();
void menu(short number, short var);
