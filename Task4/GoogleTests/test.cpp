#include "pch.h"
#include "Functions.h"

// Тест: Матрица без нулей
TEST(Task4, NoZeros) {
    int N = 3, K = 3;
    double** array = allocate2DArray(N, K);

    array[0][0] = 1; array[0][1] = 2; array[0][2] = 3;
    array[1][0] = 4; array[1][1] = 5; array[1][2] = 6;
    array[2][0] = 7; array[2][1] = 8; array[2][2] = 9;

    int count = countZeroElements(array, N, K);

    EXPECT_EQ(count, 0);

    free2DArray(array, N);
}

// Тест: Матрица полностью заполнена нулями
TEST(Task4, AllZeros) {
    int N = 3, K = 3;
    double** array = allocate2DArray(N, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            array[i][j] = 0;
        }
    }

    int count = countZeroElements(array, N, K);

    EXPECT_EQ(count, N * K);

    free2DArray(array, N);
}

// Тест: Матрица с нулями в различных местах
TEST(Task4, ZerosInRandomPlaces) {
    int N = 3, K = 3;
    double** array = allocate2DArray(N, K);

    array[0][0] = 1; array[0][1] = 0; array[0][2] = 3;
    array[1][0] = 4; array[1][1] = 5; array[1][2] = 0;
    array[2][0] = 0; array[2][1] = 8; array[2][2] = 9;

    int count = countZeroElements(array, N, K);

    EXPECT_EQ(count, 3);

    free2DArray(array, N);
}

TEST(Task4, GrebanoeKazino) {
    int N = 3, K = 3;
    double** array = allocate2DArray(N, K);
    array[0][0] = 1; array[0][1] = 0; array[0][2] = 3;
    array[1][0] = 4; array[1][1] = 5; array[1][2] = 0;
    array[2][0] = 0; array[2][1] = 8; array[2][2] = 9;

    reverse2DArray(array, N, K);

    EXPECT_EQ(array[2][2], 1);
    EXPECT_EQ(array[1][2], 4);
    
    free2DArray(array, N);
}
