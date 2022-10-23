#include <string>
class Guitar {
private:
    float price;
    std::string serialNumber, builder, model, type, backWood, topWood;

public:
    Guitar(std::string serialNumber, float price, std::string builder, std::string model, std::string type, std::string backWood, std::string topWood) {
        this->serialNumber = serialNumber;
        this->price = price;
        this->builder = builder;
        this->model = model;
        this->type = type;
        this->backWood = backWood;
        this->topWood = topWood;
    }
    //we only change the price of the guitar but other things are not changed
    //they came out of the factory like that
    std::string getSerialNumber() {
        return serialNumber;
    }
    double getPrice() {
        return price;
    }
    void setPrice(float newPrice) {
        this->price = newPrice;
    }
    std::string getBuilder() {
        return builder;
    }
    std::string getModel() {
        return model;
    }
    std::string getType() {
        return type;
    }
    std::string getBackWood() {
        return backWood;
    }
    std::string getTopWood() {
        return topWood;
    }

};
