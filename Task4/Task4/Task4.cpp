#include <iostream>
#include "Functions.h";

int main() {
    menu(4, -1);
    DisplayTask();
    std::cout << "������� ������ �������� N x K ";
    int N = ifInt();
    int K = ifInt();
    double** array;
    array = allocate2DArray(N, K);
    input2DArray(array, N, K);
    std::cout << "�� ����� ������ - " << std::endl;
    print2DArray(array, N, K);
    int count = countZeroElements(array, N, K);
    std::cout << "����������� ������ - " << std::endl;
    reverse2DArray(array, N, K);
    print2DArray(array, N, K);
    std::cout << "���������� ����� ��������� - " << count << std::endl;
    free2DArray(array, N);
    cont();
}