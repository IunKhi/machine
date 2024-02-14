#include <iostream>

class cashRegister {

private:
    int cashOnHand;

public:
    cashRegister() 
    {
        cashOnHand = 500;
    }

    cashRegister(int cash) 
    {
        cashOnHand = cash;
    }
    int getCurrentBalance() 
    {
        return cashOnHand;
    }

    void acceptAmount(int amount) 
    {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() 
    {
        numberOfItems = 50;
        cost = 50;
    }
    dispenserType(int prise, int items)
    {
        numberOfItems = items;
        cost = prise;
    }
    int getNoOfItems() 
    {
        return numberOfItems;
    }

    int getCost() 
    {
        return cost;
    }
    int getNoOfItems() 
    {
        return numberOfItems;
    }

    void makeSale() 
    {
        numberOfItems -= 1;
    }
};

void showSelection() 
{
    std::cout << "Выберите продукт: " << std::endl;
    std::cout << "1. Конфеты" << std::endl;
    std::cout << "2. Чипсы" << std::endl;
    std::cout << "3. Жевательная резинка" << std::endl;
    std::cout << "4. Печенье" << std::endl;
}
void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int choice;
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;