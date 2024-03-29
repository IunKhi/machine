#include  <iostream>

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() {
        cashOnHand = 500;
    }
    cashRegister(int cashIn) {
        cashOnHand = cashIn;
    }

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() {
        numberOfItems = 50;
        cost = 50;
    }
    dispenserType(int items, int itemCost) {
        numberOfItems = items;
        cost = itemCost;
    }

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return cost;
    }

    void makeSale() {
        numberOfItems -= 1;
    }
};

void showSelection() {
    std::cout << "Выберите продукт: " << std::endl;
    std::cout << "1. Конфеты" << std::endl;
    std::cout << "2. Чипсы" << std::endl;
    std::cout << "3. Жевательная резинка" << std::endl;
    std::cout << "4. Печенье" << std::endl;
}

void sellProduct(dispenserType& productDisp, cashRegister& cash) {
    int cost = productDisp.getCost();
    int balance = cash.getCurrentBalance();
    int cashIn;
    if (productDisp.getNoOfItems() > 0) {
        std::cout << "Стоимость товара: " << cost << "руб. ";
        std::cin >> cashIn;
        if (cashIn >= cost) {
            if (balance >= cashIn - cost) {
                productDisp.makeSale();
                cash.acceptAmount(cost);
                std::cout << "Ваш товар!\n";
                std::cout << "Ваша сдача: " << cashIn - cost << "руб.\n";
            }
            else {
                std::cout << "В автомате нет сдачи :(\nВнесите меньшую сумму.\n";
            }
        }
        else {
            std::cout << "Недостаточно средств.\n";
        }
    }
    else {
        std::cout << "Товара нет в наличии:(\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cashRegister cash(1000);
    dispenserType sweets(150, 45), chips(84, 90), gum(50, 52), cookies(80, 60);

    int choice;
    showSelection();
    std::cin >> choice;

    switch (choice) {
    case 1:
        sellProduct(sweets, cash);
        break;
    case 2:
        sellProduct(chips, cash);
        break;
    case 3:
        sellProduct(gum, cash);
        break;
    case 4:
        sellProduct(cookies, cash);
        break;
    default:
        std::cout << "Неправильный выбор.\n";
        break;
    }

    return 0;
}
