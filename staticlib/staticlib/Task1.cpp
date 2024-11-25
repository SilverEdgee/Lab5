#include <iostream>

int main();

void displayTask() {
    std::cout << "������������ ��������� ������������ ������-������� A\n";
    std::cout << "������������ n x n, ������ �������� a[i][j] ���������� �������� ���������:\n\n";
    std::cout << "a[i][j] = { 2 * i * j^2 - 2 * j, ���� i <= 5\n";
    std::cout << "          { 3 * i * j - 3, ���� i > 5\n";
    std::cout << "��� i = 1, 2, ..., n, j = 1, 2, ..., n.\n\n";
    std::cout << "������������ ����������������� ������� B = A^T.\n";
    std::cout << "���������� �����:\n";
    std::cout << "- ��������� ������ ����� � �������� �������� ��� �������-������� A;\n";
    std::cout << "- ��������� ������ �������� � �������� ����� ��� �������-������� B.\n";
    std::cout << "�� ����� ������� ������� A � B ��������� � �������� ����.\n\n";
}

void cont() {
    setlocale(LC_ALL, "Russian");
    char choice;
    while (true) {
        std::cout << "������ ����������? (Y/N): ";
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            main();
            break;
        }
        else if (choice == 'N' || choice == 'n') {
            std::cout << "���������� ���������." << std::endl;
            break;
        }
        else {
            std::cout << "������������ ����. ����������, ������� 'Y' ��� ����������� ��� 'N' ��� ����������.\n";
            std::cin.ignore(10000, '\n');
        }
    }
}

void menu(short number, short var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Task " << number << " by Denis Pometko\n";
    for (int i = 0; i < 20; i++) std::cout << "x";
    std::cout << "\n";

    if (var != -1) {
        std::cout << "Variant " << var << std::endl;
        for (int i = 0; i < 20; i++) std::cout << "x";
        std::cout << "\n";
        std::cout << "Problem: ";
    }
}

int ifInt() {
    setlocale(LC_ALL, "Russian");
    int num;
    char after;
    while (true) {
        if (std::cin >> num && ((after = std::cin.peek()) == ' ' || after == '\n')) {
            std::cin.get(after); // ������ ������ ��� \n
            return num;
        }
        std::cout << "������! ������� ����� �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int** allocate2DArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

void Change_elements_task_1(int** array, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols; j++) {
            if (i <= 5)
                array[i][j] = 2 * i * j * j - 2 * j;
            else
                array[i][j] = 3 * i * j - 3;
        }
    }
}

void Transform_matrix(int** array1, int** array2, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols; j++) {
            array2[i][j] = array1[j][i];
        }
    }
}

int Sum_of_A(int** array, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 == 0 && j % 2 != 0) {
                sum += array[i][j];
            }
        }
    }
    return sum;
}

int Sum_of_B(int** array, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 != 0 && j % 2 == 0)
                sum += array[i][j];
        }
    }
    return sum;
}
    
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void input2DArray(int** array, int rows, int cols) {
    setlocale(LC_ALL, "Russian");
    std::cout << "������� �������� ������� �������� " << rows << " x " << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = ifInt();
        }
    }
}

void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}
