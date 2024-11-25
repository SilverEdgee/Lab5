#include "pch.h"
#include "Functions.h"


TEST(Task3, EvenElementsOnDiagonal) {
    int** array = allocate2DArray(3, 3);
    array[0][0] = 2; array[0][1] = 3; array[0][2] = 4;
    array[1][0] = 5; array[1][1] = 8; array[1][2] = 6;
    array[2][0] = 7; array[2][1] = 5; array[2][2] = 10;

    int count = 0;
    int* resultArray = extractEvenDiagonalElements(array, 3, count);
    unsigned long long multiply = calculate(resultArray, count);

    ASSERT_EQ(count, 3);
    EXPECT_EQ(resultArray[0], 2);
    EXPECT_EQ(resultArray[1], 8);
    EXPECT_EQ(resultArray[2], 10);
    EXPECT_EQ(multiply, 160);

    free2DArray(array, 3);
    delete[] resultArray;
}

TEST(Task3, NoEvenElementsOnDiagonal) {
    int** array = allocate2DArray(3, 3);
    array[0][0] = 1; array[0][1] = 3; array[0][2] = 5;
    array[1][0] = 7; array[1][1] = 9; array[1][2] = 11;
    array[2][0] = 13; array[2][1] = 15; array[2][2] = 17;

    int count = 0;
    int* resultArray = extractEvenDiagonalElements(array, 3, count);
    unsigned long long multiply = calculate(resultArray, count);

    ASSERT_EQ(count, 0);
    EXPECT_EQ(multiply, 1); 

    free2DArray(array, 3);
    delete[] resultArray;
}

TEST(Task3, MinMatrixSize) {
    int** array = allocate2DArray(1, 1);
    array[0][0] = 4;

    int count = 0;
    int* resultArray = extractEvenDiagonalElements(array, 1, count);
    unsigned long long multiply = calculate(resultArray, count);

    EXPECT_EQ(count, 1);
    EXPECT_EQ(resultArray[0], 4);
    EXPECT_EQ(multiply, 4);

    free2DArray(array, 1);
    delete[] resultArray;

    array = allocate2DArray(1, 1);
    array[0][0] = 3;

    resultArray = extractEvenDiagonalElements(array, 1, count);
    multiply = calculate(resultArray, count);

    EXPECT_EQ(count, 0);
    EXPECT_EQ(multiply, 1);

    free2DArray(array, 1);
    delete[] resultArray;
}

TEST(Task3, LargeMatrixSize) {
    int N = 10;
    int** array = allocate2DArray(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = (i == j) ? (2 * (i + 1)) : 0;
        }
    }

    int count = 0;
    int* resultArray = extractEvenDiagonalElements(array, N, count);
    unsigned long long multiply = calculate(resultArray, count);

    ASSERT_EQ(count, N);
    for (int i = 0; i < N; i++) {
        EXPECT_EQ(resultArray[i], 2 * (i + 1));
    }
    EXPECT_EQ(multiply, 2ULL * 4 * 6 * 8 * 10 * 12 * 14 * 16 * 18 * 20);

    free2DArray(array, N);
    delete[] resultArray;
}
