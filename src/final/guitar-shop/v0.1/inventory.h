#include <vector>
#include <string>
class Inventory {
private:
    std::vector<Guitar> guitars;
public:
    void addGuitar(std::string serialNumber, float price, std::string builder, std::string model, std::string type, std::string backWood, std::string topWood) {
        Guitar guitar = Guitar(serialNumber, price, builder, model, type, backWood, topWood);
        guitars.push_back(guitar);
    }
    Guitar getGuitar(std::string serialNumber) {
        for (Guitar guitar : guitars) {
            if (guitar.getSerialNumber() == serialNumber) {
                return guitar;
            }
        }
        return Guitar("", 0, "", "", "", "", "");
    }
    Guitar search(Guitar searchGuitar) {
        for (Guitar guitar : guitars) {
            // Ignore serial number since that's unique
            // Ignore price since that's unique
            std::string builder = searchGuitar.getBuilder();
            if ((builder != "") && (builder != guitar.getBuilder()))
                continue;
            std::string model = searchGuitar.getModel();
            if ((model != "") && (model != guitar.getModel()))
                continue;
            std::string type = searchGuitar.getType();
            if ((type != "") && (type != guitar.getType()))
                continue;
            std::string backWood = searchGuitar.getBackWood();
            if ((backWood != "") && (backWood != guitar.getBackWood()))
                continue;
            std::string topWood = searchGuitar.getTopWood();
            if ((topWood != "") && (topWood != guitar.getTopWood()))
                continue;
            return guitar;
        }
        return Guitar("", 0, "", "", "", "", ""); // return null;
    }
};