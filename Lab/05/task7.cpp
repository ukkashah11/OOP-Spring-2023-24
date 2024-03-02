/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// MenuItem class
class MenuItem {
public:
    string foodName;
    float foodPrice;

    MenuItem(string name, float price) : foodName(name), foodPrice(price) {}
};

// Menu class
class Menu {
private:
    vector<MenuItem> items;
public:
    void addItem(const MenuItem& item) {
        items.push_back(item);
    }
    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }
    void displayMenu() const {
        for (int i = 0; i < items.size(); ++i) {
            cout << i+1 << ". " << items[i].foodName << " - $" << items[i].foodPrice << endl;
        }
    }
    const vector<MenuItem>& getItems() const {
        return items;
    }
};

// Payment class
class Payment {
public:
    float amount;

    Payment(float amount) : amount(amount) {}

    void displayPayment() const {
        cout << "Total Payment: $" << amount << endl;
    }
};

// Order class
class Order {
private:
    vector<MenuItem> orderedItems;
    Payment* payment;

public:
    Order() : payment(nullptr) {}

    void addMenuItem(const MenuItem& item) {
        orderedItems.push_back(item);
    }

    void finalizeOrder() {
        float total = 0.0f;
        for (auto& item : orderedItems) {
            total += item.foodPrice;
        }
        payment = new Payment(total);
    }

    void displayOrder() const {
        for (auto& item : orderedItems) {
            cout << item.foodName << " - $" << item.foodPrice << endl;
        }
        if (payment != nullptr) {
            payment->displayPayment();
        }
    }

    ~Order() {
        delete payment;
    }
};

// RestaurantOrderingSystem class
class RestaurantOrderingSystem {
private:
    Menu menu;

public:
    void setupMenu() {
        // Setup menu items
        menu.addItem(MenuItem("Burger", 5.99f));
        menu.addItem(MenuItem("Pizza", 7.99f));
        menu.addItem(MenuItem("Salad", 4.99f));
    }

    void displayMenu() {
        menu.displayMenu();
    }

    Menu& getMenu() {
        return menu;
    }
};

int main() {
    RestaurantOrderingSystem system;
    system.setupMenu();
    // Display the menu
    system.displayMenu();
    // Create an order
    Order order;
    Menu& menu = system.getMenu();
    order.addMenuItem(menu.getItems()[0]); // Add Burger to the order
    order.addMenuItem(menu.getItems()[1]); // Add Pizza to the order
    order.finalizeOrder();
    order.displayOrder();
    return 0;
}
