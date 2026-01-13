#include <iostream>
#include <string>
#include <Windows.h>

struct BankAccount {
    int accountNumber = 0;
    std::string name = "";
    double balance = 0;
};

void changeBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankAccount account;

    std::cout << "Введите номер счёта: ";
    std::cin >> account.accountNumber;

    std::cout << "\nВведите имя владельца: ";
    std::cin >> account.name;

    std::cout << "\nВведите баланс: ";
    std::cin >> account.balance;

    double newBalance;
    std::cout << "\nВведите новый баланс: ";
    std::cin >> newBalance;

    changeBalance(account, newBalance);

    std::cout << "\nВаш счёт: " << account.name << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;

}
