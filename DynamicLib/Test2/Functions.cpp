#include <iostream>

int main();

void cont() {
	setlocale(LC_ALL, "Russian");
	char choice;
	while (true) {
		std::cout << "Хотите продолжить? (Y/N): ";
		std::cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			main();
			break;
		}
		else if (choice == 'N' || choice == 'n') {
			std::cout << "Завершение программы." << std::endl;
			break;
		}
		else {
			std::cout << "Некорректный ввод. Пожалуйста, введите 'Y' для продолжения или 'N' для завершения.\n";
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
		std::cout << "Ошибка! Введите целое число: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

void DisplayTask() {
	setlocale(LC_ALL, "Russian");
		std::cout << "Для заданного одномерного массива C из N элементов:\n";
		std::cout << "Найти произведение множителей, вычисляемых по формуле:\n";
		std::cout << "    sin(Ci) - cos(Ci)\n";
		std::cout << "Рекурсивную функцию применять:\n";
		std::cout << "1. Для первой трети массива отдельно.\n";
		std::cout << "2. Для оставшейся части массива (2/3).\n";
		std::cout << "Рекурсивные вызовы заканчивать, когда останется один или два элемента.\n";
		std::cout << "Например, для N = 12:\n";
		std::cout << "         П (sin(Ci) - cos(Ci)) = (П (Ci^2 + cos(Ci)) x П (sin(Ci) - cos(Ci)))\n";
		std::cout << "         i=1                i=1                       i=5\n";
		std::cout << "Для первой трети массива используем формулу:\n";
		std::cout << "    Bi^2 + cos(Bi)\n";
		std::cout << "Для оставшейся части массива используем формулу:\n";
		std::cout << "    sin(Ci) - cos(Ci)\n";

}