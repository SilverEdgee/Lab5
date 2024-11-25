#pragma once

void displayTask();
void cont();
void menu(short number, short var);
int ifInt();
int** allocate2DArray(int rows, int cols);
void free2DArray(int** array, int rows);
void input2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
void Change_elements_task_1(int** array, int cols);
void Transform_matrix(int** array1, int** array2, int cols);
int Sum_of_A(int** array, int cols);
int Sum_of_B(int** array, int cols);
