#include <iostream>

int main();

void DisplayTask() {
    std::cout << "������� ��������� ������������ ������ ������������ �����.\n"
        << "����������, ����������� �� ����� ��� �������� � ������� ���������.\n"
        << "���� ����� �������� ����, ������� �� ������� � ����� ����������.\n"
        << "����������� �������� ������� � �������� ������� � ������� �� �����.\n";
}

void printZeroPosition(int row, int col) {
    std::cout << "������� ������� ��������� �� "
        << row + 1 << "-�� ������ � "
        << col + 1 << "-�� �������" << std::endl;
}


int countZeroElements(double** array, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == 0) {
                printZeroPosition(i, j);
                count++;
            }
        }
    }
    return count;
}

void reverse2DArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols / 2; ++j) {
            std::swap(array[i][j], array[i][cols - j - 1]);
        }
    }
    for (int i = 0; i < rows / 2; ++i) {
        std::swap(array[i], array[rows - i - 1]);
    }
}


long double ifDouble() {
    long double num;
    while (true) {
        if (std::cin >> num) {
            if (std::cin.peek() == '\n' || std::cin.peek() == ' ') {
                std::cin.ignore();
                break;
            }
        }
        std::cout << "������! ������� ������������ �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return num;
}

double** allocate2DArray(int rows, int cols) {
    double** array = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new double[cols];
    }
    return array;
}

void free2DArray(double** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void input2DArray(double** array, int rows, int cols) {
    setlocale(LC_ALL, "Russian");
    std::cout << "������� �������� ������� �������� " << rows << " x " << cols << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = ifDouble();
        }
    }
}

void print2DArray(double** array, int rows, int cols) {
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
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
            std::cin.get(after);
            return num;
        }
        std::cout << "������! ������� ����� �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}