#include <iostream>
#include <string>
#include <Windows.h>

struct Address {
private:
    std::string city = "";
    std::string street = "";
    int houseNumber = 0;
    int flatNumber = 0;
    int index = 0;

public:
    void SetInfo(std::string c, std::string s, int h, int f, int i) {
        city = c;
        street = s;
        houseNumber = h;
        flatNumber = f;
        index = i;
    }

    void GetInfo() {
        std::cout << "Город: " << city << std::endl;
        std::cout << "Улица: " << street << std::endl;
        std::cout << "Номер дома: " << houseNumber << std::endl;
        std::cout << "Номер квартиры: " << flatNumber << std::endl;
        std::cout << "Индекс: " << index << std::endl << std::endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Address address1;
    address1.SetInfo("Москва", "Арбат", 12, 8, 123456);

    Address address2;
    address2.SetInfo("Ижевск", "Пушкина", 59, 143, 953769);

    address1.GetInfo();
    address2.GetInfo();

    Address address3;
    address3.SetInfo("Санкт-Петербург", "Невский проспект", 25, 42, 190000);

    address3.GetInfo();

    return 0;
}