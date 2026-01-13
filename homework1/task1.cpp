#include <iostream>
#include <string>
#include <Windows.h>

enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

std::string getMonth(Month month) {
    switch (month) {
    case JANUARY:
        return "Январь";
    case FEBRUARY:
        return "Февраль";
    case MARCH:
        return "Март";
    case APRIL:
        return "Апрель";
    case MAY:
        return "Май";
    case JUNE:
        return "Июнь";
    case JULY:
        return "Июль";
    case AUGUST:
        return "Август";
    case SEPTEMBER:
        return "Сентябрь";
    case OCTOBER:
        return "Октябрь";
    case NOVEMBER:
        return "Ноябрь";
    case DECEMBER:
        return "Декабрь";
    default:
        return "";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int monthNumber;

    while (true) {
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;

        if (monthNumber == 0) {
            std::cout << "До свидания" << std::endl;
            break;
        }

        if (monthNumber < 1 || monthNumber > 12) {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        Month month = static_cast<Month>(monthNumber);
        std::cout << getMonth(month) << std::endl;
    }

    return 0;

}

