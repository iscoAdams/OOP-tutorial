#include <iostream>
#include <string>

class Product {
    std::string name, size;
    int availableQuantity;
    float price;

    //interface
public:
    //u can consider it as a factory (intitallize stuff with some values)
    // example: the factory doesn't care about the price it only produce it (but as a manger I must set a commerical price)
    // i'm as a seller can change it later (setPrice) [product in the factory is not for sale]
    // may be the same product but in defferent places with different prices
    // sizz, name came from a factory (can't change) buut quantity and price can be changed
    Product(std::string name, std::string size, int availableQuantity, float price) : name(name), size(size), availableQuantity(availableQuantity), price(price) {}

    std::string getName() {
        return name;
    }
    std::string getSize() {
        return size;
    }
    int getavailableQuantity() {
        return availableQuantity;
    }
    float getPrice() {
        return price;
    }
    void set_price(float price) {
        this->price = price;
    }
    void set_availableQuantity(int availableQuantity) {
        this->availableQuantity = availableQuantity;
    }
    /*  void set_name(std::string name) {
         this->name = name;
     } */
     //the product has a name and size, once it come out of the factory (initiallized), it cannot be changed

    std::string to_string() {
        return "there are " + std::to_string(availableQuantity) + " pieces available in size " + size + "\n" + name + "for " + std::to_string(price).substr(0, std::to_string(price).find('.') + 3) + "$ for each";
    }
    void print() {
        std::cout << to_string() << std::endl;
    }

};
//can't override an existing function which defined with an existing type
/* std::string to_string(float price) {
    std::string s = std::to_string(price);
    return s.substr(0, s.find('.') + 2);
}  */