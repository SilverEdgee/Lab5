#include "pch.h"
#include "Windows.h"

TEST(RecursionTest, TwoElementArray) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef double(__stdcall* RecursionFunc) (int* array, int start, int end, bool isFirstThird);
    RecursionFunc Recursion = (RecursionFunc)GetProcAddress(load, "Recursion");

    int array[] = { 3, 7 };

    double resultFirstThird = Recursion(array, 0, 1, true); // Два элемента в первой трети
    double resultSecondPart = Recursion(array, 0, 1, false); // Два элемента в оставшейся части

    EXPECT_NEAR(resultFirstThird, (3 * 3 + cos(3)) * (7 * 7 + cos(7)), 1e-5);
    EXPECT_NEAR(resultSecondPart, (sin(3) - cos(3)) * (sin(7) - cos(7)), 1e-5);
}

TEST(RecursionTest, BasicArray) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef double(__stdcall* RecursionFunc) (int* array, int start, int end, bool isFirstThird);
    RecursionFunc Recursion = (RecursionFunc)GetProcAddress(load, "Recursion");
    int array[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(array) / sizeof(array[0]);
    double resultFirstThird = Recursion(array, 0, size / 3 - 1, true);  // Первая треть
    double resultSecondPart = Recursion(array, size / 3, size - 1, false); // Остальная часть
    EXPECT_NEAR(resultFirstThird, (1 * 1 + cos(1)) * (2 * 2 + cos(2)), 1e-5); // Проверка первой трети
    EXPECT_NEAR(resultSecondPart, (sin(3) - cos(3)) * (sin(4) - cos(4)) * (sin(5) - cos(5)) * (sin(6) - cos(6)), 1e-5); // Проверка оставшейся части
}

TEST(RecursionTest, SingleElementArray) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef double(__stdcall* RecursionFunc) (int* array, int start, int end, bool isFirstThird);
    RecursionFunc Recursion = (RecursionFunc)GetProcAddress(load, "Recursion");
    int array[] = { 42 };
    double resultFirstThird = Recursion(array, 0, 0, true); // Одно число в первой трети
    double resultSecondPart = Recursion(array, 0, 0, false); // Одно число в остальной части
    EXPECT_NEAR(resultFirstThird, 42 * 42 + cos(42), 1e-5);
    EXPECT_NEAR(resultSecondPart, sin(42) - cos(42), 1e-5);
}

TEST(RecursionTest, UnevenDivisionArray) {
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef double(__stdcall* RecursionFunc) (int* array, int start, int end, bool isFirstThird);
    RecursionFunc Recursion = (RecursionFunc)GetProcAddress(load, "Recursion");

    int array[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);

    double resultFirstThird = Recursion(array, 0, size / 3 - 1, true);  // Первая треть (1)
    double resultSecondPart = Recursion(array, size / 3, size - 1, false); // Остальная часть (2, 3, 4, 5)

    EXPECT_NEAR(resultFirstThird, 1 * 1 + cos(1), 1e-5);
    EXPECT_NEAR(resultSecondPart, (sin(2) - cos(2)) * (sin(3) - cos(3)) * (sin(4) - cos(4)) * (sin(5) - cos(5)), 1e-5);
}


