#include <iostream>
#include <string>

struct BankAccount {
    int accountNumber = 0;
    std::string name = "";
    double balance = 0;
};

void changeBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    setlocale(LC_ALL, "RU");

    BankAccount account;

    std::cout << "¬ведите номер счЄта: ";
    std::cin >> account.accountNumber;

    std::cout << "\n¬ведите им€ владельца: ";
    std::cin >> account.name;

    std::cout << "\n¬ведите баланс: ";
    std::cin >> account.balance;

    double newBalance;
    std::cout << "\n¬ведите новый баланс: ";
    std::cin >> newBalance;

    changeBalance(account, newBalance);

    std::cout << "\n¬аш счЄт: " << account.name << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;
}