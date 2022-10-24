#include <iostream>
#include <vector>
#include <string>
class BoyFriend {
private:
    int age;
    std::string name;
public:
    BoyFriend(std::string name, int age) : name(name), age(age) {}
    std::string getName() {
        return name;
    }
    void walk() {
        std::cout << "I can walk without my girlfriend idiot!" << std::endl;
    }
    void talk() {
        std::cout << name << "I can talk without my girlfriend idiot!" << std::endl;
    }

};
class GirlFriend {
private:
    int age;
    std::string name;
    BoyFriend* boyFriend;
public:
    GirlFriend(std::string name, int age, BoyFriend* boyFriend) : name(name), age(age), boyFriend(boyFriend) {}
    std::string getName() {
        return name;
    }
    void walk() {
        std::cout << "I can walk without my boyfriend idiot!" << std::endl;
    }
    void talk() {
        std::cout << name << "I can talk without my boyfriend idiot!" << std::endl;
    }
    void showSomeLove() {
        std::cout << name << "says that she is in love with" << boyFriend->getName() << std::endl;
    }
};