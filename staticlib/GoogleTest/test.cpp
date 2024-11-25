#include "pch.h"
#include "../staticlib/staticlib.h"

TEST(Task1, Dota1to9min) {
    int n = 3;
    int** array = allocate2DArray(n, n);
    // Устанавливаем фиксированные значения
    array[0][0] = 1;  array[1][0] = 4;  array[0][1] = 2; array[0][2] = 3;
    array[1][1] = 5; array[1][2] = 6;
    array[2][1] = 8; array[2][2] = 9;
    int sumA = Sum_of_A(array, n);
    int** array2 = allocate2DArray(n, n);
    Transform_matrix(array, array2, n);
    int sumB = Sum_of_B(array2, n);
    EXPECT_EQ(sumA, 10);
    EXPECT_EQ(sumB, 10);
    free2DArray(array, n);
}

TEST(Task1, Dota42min) {
    int n = 1;
    int** array = allocate2DArray(n, n);
    array[0][0] = 42;
    int sumA = Sum_of_A(array, n);
    int sumB = Sum_of_B(array, n);
    EXPECT_EQ(sumA, 0); // Нет нечётных элементов в чётных столбцах
    EXPECT_EQ(sumB, 0); // Нет нечётных элементов в нечётных строках
    free2DArray(array, n);
}

TEST(Task1, Dota100min) {
    int n = 100;
    int** array = allocate2DArray(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[i][j] = (i + j) % 10; // Заполняем числами от 0 до 9
        }
    }
    int sumA = Sum_of_A(array, n);
    int sumB = Sum_of_B(array, n);
    EXPECT_GT(sumA, 0);
    EXPECT_GT(sumB, 0);
    free2DArray(array, n);
}
