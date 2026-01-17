#include <iostream>
#include <Windows.h>

class Calculator {
private:
	double num1{}, num2{};

public:
	double add() {
		return num1 + num2;
	}

	double multiply() {
		return num1 * num2;
	}

	double subtract_1_2() {
		return num1 - num2;
	}

	double subtract_2_1() {
		return num2 - num1;
	}

	double divide_1_2() {
		return num1 / num2;
	}

	double divide_2_1() {
		return num2 / num1;
	}

	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else {
			return false;
		}
	}

	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Calculator example;

	double value;
	bool flag = false;

	std::cout << "Введите num1: ";
	while (!flag) {
		std::cin >> value;
		flag = example.set_num1(value);
		if (!flag) {
			std::cout << "Неверный ввод!\n";
		}
	}

	std::cout << "Введите num2: ";
	flag = false;
	while (!flag) {
		std::cin >> value;
		flag = example.set_num2(value);
		if (!flag) {
			std::cout << "Неверный ввод!\n";
		}
	}

	std::cout << "num1 + num2 = " << example.add() << std::endl;
	std::cout << "num1 - num2 = " << example.subtract_1_2() << std::endl;
	std::cout << "num2 - num1 = " << example.subtract_2_1() << std::endl;
	std::cout << "num1 * num2 = " << example.multiply() << std::endl;
	std::cout << "num1 / num2 = " << example.divide_1_2() << std::endl;
	std::cout << "num2 / num1 = " << example.divide_2_1();
}  