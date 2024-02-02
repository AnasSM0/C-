#include <iostream>

// Abstract base class for vending machine items
class Item {
public:
    virtual void displayDetails() const = 0;  // Pure virtual function for displaying item details
    virtual double calculateCost() const = 0;  // Pure virtual function for calculating item cost
    virtual ~Item() {}  // Virtual destructor to ensure proper cleanup
};

// Derived class for Soda
class Soda : public Item {
private:
    std::string name;
    double price;

public:
    Soda(const std::string& n, double p) : name(n), price(p) {}

    void displayDetails() const override {
        std::cout << "Soda: " << name << ", Price: $" << price << std::endl;
    }

    double calculateCost() const override {
        return price;
    }
};

// Derived class for Chips
class Chips : public Item {
private:
    std::string name;
    double price;

public:
    Chips(const std::string& n, double p) : name(n), price(p) {}

    void displayDetails() const override {
        std::cout << "Chips: " << name << ", Price: $" << price << std::endl;
    }

    double calculateCost() const override {
        return price;
    }
};

// Derived class for Candy
class Candy : public Item {
private:
    std::string name;
    double price;

public:
    Candy(const std::string& n, double p) : name(n), price(p) {}

    void displayDetails() const override {
        std::cout << "Candy: " << name << ", Price: $" << price << std::endl;
    }

    double calculateCost() const override {
        return price;
    }
};

int main() {
   

    // Create instances of different items
    Soda s1("Cola", 1.50);
    Chips c1("Potato Chips", 1.20);
    Candy c2("Chocolate Bar", 0.75);

 s1.displayDetails();
 s1.calculateCost();
 

    
    return 0;
}

