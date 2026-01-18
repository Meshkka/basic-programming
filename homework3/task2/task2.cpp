#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>

class Address {
private:
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;

public:
    void setAddress(const std::string& city, const std::string& street,
        const std::string& house, const std::string& apartment) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string getFormattedAddress() const {
        return city + ", " + street + ", " + house + ", " + apartment;
    }

    std::string getCity() const {
        return city;
    }
};

bool compareByCity(const Address& a, const Address& b) {
    return a.getCity() < b.getCity();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    if (!inFile.is_open()) {
        std::cout << "Не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    if (!outFile.is_open()) {
        std::cout << "Не удалось открыть файл out.txt" << std::endl;
        return 1;
    }

    int N;
    inFile >> N;
    inFile.ignore();

    Address* addresses = new Address[N];

    for (int i = 0; i < N; ++i) {
        std::string city, street, house, apartment;

        std::getline(inFile, city);
        std::getline(inFile, street);
        std::getline(inFile, house);
        std::getline(inFile, apartment);

        addresses[i].setAddress(city, street, house, apartment);
    }

    std::sort(addresses, addresses + N, compareByCity);

    outFile << N << std::endl;
    for (int i = 0; i < N; ++i) {
        outFile << addresses[i].getFormattedAddress();

        if (i < N - 1) {
            outFile << std::endl;
        }
    }

    delete[] addresses;

    inFile.close();
    outFile.close();

    std::cout << "Программа успешно завершена, результат записан в out.txt" << std::endl;

    return 0;
}