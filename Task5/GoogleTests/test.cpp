#include "pch.h"
#include "Functions.h"

// Тест: Матрица без нечётных чисел на чётных столбцах
TEST(Task5, NoOddNumbers) {
    int N = 3, K = 3;
    int** array = allocate2DArray(N, K);

    array[0][0] = 2; array[0][1] = 4; array[0][2] = 6;
    array[1][0] = 8; array[1][1] = 10; array[1][2] = 12;
    array[2][0] = 14; array[2][1] = 16; array[2][2] = 18;

    int sum = 0;
    int* resultArray = new int[N * K];
    int count = OddNumbersEvenQuality(array, N, K, resultArray, sum);

    EXPECT_EQ(count, 0);
    EXPECT_EQ(sum, 0);

    free2DArray(array, N);
    delete[] resultArray;
}

// Тест: Матрица, полностью заполненная нечётными числами
TEST(Task5, AllOddNumbers) {
    int N = 3, K = 3;
    int** array = allocate2DArray(N, K);

    array[0][0] = 1; array[0][1] = 3; array[0][2] = 5;
    array[1][0] = 7; array[1][1] = 9; array[1][2] = 11;
    array[2][0] = 13; array[2][1] = 15; array[2][2] = 17;

    int sum = 0;
    int* resultArray = new int[N * K];
    int count = OddNumbersEvenQuality(array, N, K, resultArray, sum);

    EXPECT_EQ(count, 6);
    EXPECT_EQ(sum, 1 + 7 + 13 + 5 + 11 + 17);

    free2DArray(array, N);
    delete[] resultArray;
}

// Тест: Нечётные числа в некоторых местах
TEST(Task5, RandomOddNumbers) {
    int N = 2, K = 4;
    int** array = allocate2DArray(N, K);

    array[0][0] = 1; array[0][1] = 2; array[0][2] = 3; array[0][3] = 4;
    array[1][0] = 5; array[1][1] = 6; array[1][2] = 7; array[1][3] = 8;

    int sum = 0;
    int* resultArray = new int[N * K];
    int count = OddNumbersEvenQuality(array, N, K, resultArray, sum);

    EXPECT_EQ(count, 4);
    EXPECT_EQ(sum, 1 + 5 + 3 + 7);

    free2DArray(array, N);
    delete[] resultArray;
}

TEST(Task5, EmptyMatrix) {
    int N = 0, K = 0;
    int** array = allocate2DArray(N, K);

    int sum = 0;
    int* resultArray = new int[1];
    int count = OddNumbersEvenQuality(array, N, K, resultArray, sum);

    EXPECT_EQ(count, 0);
    EXPECT_EQ(sum, 0);

    free2DArray(array, N);
    delete[] resultArray;
}

// Тест: Матрица 1x1 с нечётным числом
TEST(Task5, SingleOddNumber) {
    int N = 1, K = 1;
    int** array = allocate2DArray(N, K);

    array[0][0] = 7;

    int sum = 0;
    int* resultArray = new int[N * K];
    int count = OddNumbersEvenQuality(array, N, K, resultArray, sum);

    EXPECT_EQ(count, 1); 
    EXPECT_EQ(sum, 7); 

    free2DArray(array, N);
    delete[] resultArray;
}
