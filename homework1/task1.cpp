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
        return "ßíâàðü";
    case FEBRUARY:
        return "Ôåâðàëü";
    case MARCH:
        return "Ìàðò";
    case APRIL:
        return "Àïðåëü";
    case MAY:
        return "Ìàé";
    case JUNE:
        return "Èþíü";
    case JULY:
        return "Èþëü";
    case AUGUST:
        return "Àâãóñò";
    case SEPTEMBER:
        return "Ñåíòÿáðü";
    case OCTOBER:
        return "Îêòÿáðü";
    case NOVEMBER:
        return "Íîÿáðü";
    case DECEMBER:
        return "Äåêàáðü";
    default:
        return "";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int monthNumber;

    while (true) {
        std::cout << "Ââåäèòå íîìåð ìåñÿöà: ";
        std::cin >> monthNumber;

        if (monthNumber == 0) {
            std::cout << "Äî ñâèäàíèÿ" << std::endl;
            break;
        }

        if (monthNumber < 1 || monthNumber > 12) {
            std::cout << "Íåïðàâèëüíûé íîìåð!" << std::endl;
            continue;
        }

        Month month = static_cast<Month>(monthNumber);
        std::cout << getMonth(month) << std::endl;
    }

    return 0;

}
