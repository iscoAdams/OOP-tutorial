#include <iostream>
#include <vector>
#include <string>
enum CheeseType {
    FRESH,
    OLD
};
enum FruitType {
    APPLE,
    BANANA
};
class Product {
protected:
    float pricePerKg;
    float weight;
public:
    float getPrice() {
        return pricePerKg;
    }
    float getWeight() {
        return weight;
    }
};

class Cheese : public Product {
    CheeseType type;
public:
    Cheese(CheeseType type, float pricePerKg, float weight) {
        this->type = type;
        this->pricePerKg = pricePerKg;
        this->weight = weight;
    }
};

class Fruit : public Product {
    FruitType type;
public:
    Fruit(FruitType type,float pricePerKg, float weight) {
        this->type = type;
        this->pricePerKg = pricePerKg;
        this->weight = weight;
    }
};

class Chef {
private:
    std::string name;
public:
    Chef(std::string name) : name(name) {}
    float getTotalPrice(Product product) {
        return product.getPrice() * product.getWeight();
    }
    static Chef* askChif() {
        return new Chef("some chef");
    }
};

class ShoppingCart {
public:
    std::vector<Product*> products;
    void addProduct(Product* product) {
        products.push_back(product);
    }
    void removeProduct(Product* searchProduct) {
        for (auto product = products.begin(); product != products.end(); product++) {
            if (*product == searchProduct) {
                products.erase(product);
                break;
            }
        }
    }
    float getNetPrice(ShoppingCart cart) {
        float totalPrice = 0;
        for (auto product : cart.products) {
            totalPrice += Chef::askChif()->getTotalPrice(*product); //first delegation
        }
        return  totalPrice;
    }
};
class Kashier {
private://even it's default value is private it's better to write it
    std::string name;
public:
    Kashier(std::string name) : name(name) {}
    float checkout(ShoppingCart cart) {
        return cart.getNetPrice(cart); //second delegation
    }
    static Kashier* askKashier() {
        return new Kashier("some kashier");
    }
};

//make sure every clas does it's job and nothing more
// let's type it wrong and then let's fix anything





// first start with all private and pubic 
// ad create fruit and chess seperated classes 
// and then create a product class and make it abstract
// then create a shopping cart class
// u can create more than one Chef but at the end of the day u found that
// they all do the same thing so they can be just objects
// then ask the chef with static function to make everyThing easy
// then create a Kashier class and ask him to checkout
// then ask him with static function to make everyThing easy
// then try instead of create an object with the name of the chessse or fruit
// create an enum and add type to the constructor to make everyThing isolated
// change what is in main to corresponds to that and that's it