#include <iostream>
#include <Windows.h>

class Counter {
private:
    int value;

public:
    Counter() {
        value = 1;
    }

    Counter(int value) {
        this->value = value;
    }

    void increaseValue() {
        value++;
    }

    void decreaseValue() {
        value--;
    }

    int checkValue() {
        return value;
    }
};

bool func(Counter &counter) {
    std::string str;
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> str;
    if (str == "x") {
        std::cout << "До свидания!";
        return false;
    }
    else if (str == "+") {
        counter.increaseValue();
    } 
    else if (str == "-") {
        counter.decreaseValue();
    }
    else if (str == "=") {
        std::cout << counter.checkValue() << std::endl;
    }
    else {
        std::cout << "Вы ввели что-то не то, попробуйте ещё" << std::endl;
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> str;

    Counter counter;

    if (str == "да") {
        int value;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> value;
        counter = Counter(value);
    }
    else {
        std::cout << "Начальное значение установлено по умолчанию (1)" << std::endl;
    }

    bool flag = true;
    while (flag) {
        flag = func(counter);
    }

    return 0;
}