#include  <iostream>

class cashRegister {
private:
	int cashOnHand;

public:
	cashRegister() {
		cashOnHand = 500;
	}
	cashRegister(int cash) {
		cashOnHand = cash;
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

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
	int choice;
	std::cout << "Введите ваш выбор: ";
	std::cin >> choice;
    switch (choice) {
    case 1: {
        std::cout << "Выбраны конфеты." << std::endl;
        std::cout << "Стоимость: " << dispenser.getCost() << std::endl;
        std::cout << "Введите сумму: ";
        int amount;
        std::cin >> amount;

        if (amount >= dispenser.getCost()) {
            dispenser.makeSale();
            cashReg.acceptAmount(dispenser.getCost());
            std::cout << "Продукт продан. Сдача: " << amount - dispenser.getCost() << std::endl;
        }
        else {
            std::cout << "Недостаточно средств." << std::endl;
        }
        break;
    }
    case 2: {
        std::cout << "Выбраны чипсы." << std::endl;
        std::cout << "Стоимость: " << dispenser.getCost() << std::endl;
        std::cout << "Введите сумму: ";
        int amount;
        std::cin >> amount;

        if (amount >= dispenser.getCost()) {
            dispenser.makeSale();
            cashReg.acceptAmount(dispenser.getCost());
            std::cout << "Продукт продан. Сдача: " << amount - dispenser.getCost() << std::endl;
        }
        else {
            std::cout << "Недостаточно средств." << std::endl;
        }
        break;
    }
    case 3: {
        std::cout << "Выбрана жевательная резинка." << std::endl;
        std::cout << "Стоимость: " << dispenser.getCost() << std::endl;
        std::cout << "Введите сумму: ";
        int amount;
        std::cin >> amount;

        if (amount >= dispenser.getCost()) {
            dispenser.makeSale();
            cashReg.acceptAmount(dispenser.getCost());
            std::cout << "Продукт продан. Сдача: " << amount - dispenser.getCost() << std::endl;
        }
        else {
            std::cout << "Недостаточно средств." << std::endl;
        }
        break;
    }
    case 4: {
        std::cout << "Выбрано печенье." << std::endl;
        std::cout << "Стоимость: " << dispenser.getCost() << std::endl;
        std::cout << "Введите сумму: ";
        int amount;
        std::cin >> amount;

        if (amount >= dispenser.getCost()) {
            dispenser.makeSale();
            cashReg.acceptAmount(dispenser.getCost());
            std::cout << "Продукт продан. Сдача: " << amount - dispenser.getCost() << std::endl;
        }
        else {
            std::cout << "Недостаточно средств." << std::endl;
        }
        break;
    }
    default:
        std::cout << "Неверный выбор." << std::endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    dispenserType dispenser;
    cashRegister cashReg;
    showSelection();
    sellProduct(dispenser, cashReg);
    return 0;
}
