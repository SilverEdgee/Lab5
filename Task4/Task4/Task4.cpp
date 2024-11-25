#include <iostream>
#include "Functions.h";

int main() {
    menu(4, -1);
    DisplayTask();
    std::cout << "Введите массив размером N x K ";
    int N = ifInt();
    int K = ifInt();
    double** array;
    array = allocate2DArray(N, K);
    input2DArray(array, N, K);
    std::cout << "Вы ввели массив - " << std::endl;
    print2DArray(array, N, K);
    int count = countZeroElements(array, N, K);
    std::cout << "Перевёрнутый массив - " << std::endl;
    reverse2DArray(array, N, K);
    print2DArray(array, N, K);
    std::cout << "Количество таких элементов - " << count << std::endl;
    free2DArray(array, N);
    cont();
}