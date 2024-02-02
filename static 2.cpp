#include <iostream>
using namespace std;

class shop {
    static int itemIdCounter;  // Separate counter for incrementing item IDs
    int itemId;
    float itemPrice;
    string itemName;

public:
    shop() {
        itemId = itemIdCounter++;  // Initialize itemId with the current counter value and then increment
    }

    int getId() {
        return itemId;
    }

    void setName(string name) {
        itemName = name;
    }

    string getName() {
        return itemName;
    }

    void setPrice(float price) {
        itemPrice = price;
    }

    float getPrice() {
        return itemPrice;
    }

    void display() {
        cout << "Item ID: " << itemId << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Item Price: " << itemPrice << endl;
    }
};

int shop::itemIdCounter = 101;  // Initialize the counter with the starting value

int main() {
    shop i1, i2;

    i1.setName("Shampoo");
    i1.setPrice(500);
    i1.display();

    i2.setName("Soap");
    i2.setPrice(200);
    i2.display();
}
