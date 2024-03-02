/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
#define MAX_ITEMS 100
using namespace std;
class Shop {
private:
    string items[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int count = 0;
public:
    void addItem(string item, float price) {
        items[count] = item;
        prices[count++] = price;
        cout << count << endl;
    }

    string getItem(int item) {
        return items[item-1];
    }
    float getPrice(int item) {
        return prices[item-1];
    }
    int getCount() {
        return count;
    }
    void modifyPrice(int price, int item_num) {
        prices[item_num-1] = price;
    }
    void Display() {
        for (int i = 0; i < count; i++) cout << items[i] << ": " << prices[i] << endl;
    }
};
void menu() {
    cout << "Stationary Shop Menu:" << endl
         << "\t1. Enter shop item" << endl
         << "\t2. Modify item price" << endl
         << "\t3. Show items" << endl
         << "\t4. Buy item" << endl
         << "\t5. Generate receipt" << endl
         << "\t6. Exit" << endl
         << ">> ";
}

void enterItem(Shop &shop) {
    string item;
    float price;
    cout << "Enter item name: ";
    cin >> item;
    cout << "Enter item price: ";
    cin >> price;

    shop.addItem(item, price);
}
void changePrice(Shop &shop) {
    int item_num;
    float price;

    cout << "Enter item number: ";
    cin >> item_num;
    cout << "Enter new item price: ";
    cin >> price;

    shop.modifyPrice(price, item_num);
}

void buyItem(string items[MAX_ITEMS], float prices[MAX_ITEMS], int &c,Shop &shop) {
    int item;
    cout << "Enter item to buy: ";
    cin >> item;
    items[c] = shop.getItem(item);
    prices[c] = shop.getPrice(item);
    c++;
}

float find_sum(float arr[MAX_ITEMS], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

void generate_receipt(string items[MAX_ITEMS], float prices[MAX_ITEMS], int c) {
    for (int i = 0; i < c; i++) cout << items[i] << ": " << prices[i] << endl;
    cout << "Total: " << find_sum(prices, c);
}

int main()
{
    Shop shop;
    string receipt_items[MAX_ITEMS];
    float receipt_prices[MAX_ITEMS];
    int receipt_count = 0;

    bool flag = true;
    while(flag) {
        menu();
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                enterItem(shop);
                break;
            case 2:
                changePrice(shop);
                break;
            case 3:
                shop.Display();
                break;
            case 4:
                if (!shop.getCount()) {
                    cout << "No items entered by the shop keeper yet" << endl;
                    break;
                }
                buyItem(receipt_items, receipt_prices, receipt_count, shop);
                break;
            case 5:
                generate_receipt(receipt_items, receipt_prices, receipt_count);
            default:
                flag = false;
        }
    }

    return 0;
}