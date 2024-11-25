#pragma once
int* extractEvenDiagonalElements(int** array, int size, int& count);
unsigned long long calculate(const int* array, int count);
void DisplayTask();
void input2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
int** allocate2DArray(int rows, int cols);
void free2DArray(int** array, int rows);
int* allocateArray(int length);
void printArray(int* array, int length);
int ifInt();
void cont();
void menu(short number, short var);