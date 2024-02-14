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
switch(choice) {
case 1:
            std::cout << "Стоимость конфет: " << dispenser.getCost() << " рублей\n";
            break;
        case 2:
            std::cout << "Стоимость чипсов: " << dispenser.getCost() << " рублей\n";
            break;
        case 3:
            std::cout << "Стоимость жевательной резинки: " << dispenser.getCost() << " рублей\n";
            break;
        case 4:
            std::cout << "Стоимость печенья: " << dispenser.getCost() << " рублей\n";
            break;
        default:
            std::cout << "Некорректный выбор.\n";
            return;
    }

    int amount;
    std::cout << "Внесите деньги: ";
    std::cin >> amount;

    if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        register.acceptAmount(dispenser.getCost());

        std::cout << "Спасибо за покупку!\n";
    } else {
        std::cout << "Недостаточно средств.\n";
    }
}

int main() {
    CashRegister register;
    DispenserType dispenser;

    showSelection();
    sellProduct(dispenser, register);

    return 0;
}
