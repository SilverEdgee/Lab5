#pragma once
double** allocate2DArray(int rows, int cols);
void free2DArray(double** array, int rows);
void input2DArray(double** array, int rows, int cols);
void print2DArray(double** array, int rows, int cols);
void cont();
void menu(short number, short var);
int ifInt();
long double ifDouble();
void DisplayTask();
int countZeroElements(double** array, int rows, int cols);
void reverse2DArray(double** array, int rows, int cols);
void printZeroPosition(int row, int col);