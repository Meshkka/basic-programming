#include <iostream>
#include <string>
#include <Windows.h>

struct Address {
    std::string city = "";
    std::string street = "";
    int houseNumber = 0;
    int flatNumber = 0;
    int index = 0;
};

void dataOutput(Address& address) {
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.houseNumber << std::endl;
    std::cout << "Номер квартиры: " << address.flatNumber << std::endl;
    std::cout << "Индекс: " << address.index << std::endl << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Address address1 = { "Москва", "Арбат", 12, 8, 123456 };
    Address address2 = { "Ижевск", "Пушкина", 59, 143, 953769 };

    dataOutput(address1);
    dataOutput(address2);

    Address address3 = { "Санкт-Петербург", "Невский проспект", 25, 42, 190000 };
    

    dataOutput(address3);

    return 0;
}
