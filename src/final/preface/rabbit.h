#include <iostream>
#include <string>
struct Rabbit {
    std::string type;
    Rabbit(std::string type) {
        this->type = type;
    }
    void speak() {
        std::cout << "I am a " << type << " rabbit" << std::endl;
    }
    static Rabbit* create() {
        return new Rabbit(0);
    }
};
std::string to_string(Rabbit rabbit) {
    return  "a " + rabbit.type + " rabbit";
}

// std::string to_string(Rabbit* rabbit) { //reference to a rabbit object
//     return 'a' + rabbit->type + " rabbit";
// }