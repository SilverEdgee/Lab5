#pragma once
#include <iostream>

// ������� ��� ������ � ���������
int** allocate2DArray(int rows, int cols);
void free2DArray(int** array, int rows);
int* allocateArray(int length);
void input2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
void printArray(int* array, int length);
int OddNumbersEvenQuality(int** array, int rows, int cols, int* resultArray, int& sum);

// ��������������� �������
int ifInt();
void cont();
void menu(short number, short var);
