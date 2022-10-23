#include <iostream>
class Airplane {
    //there is a convention to name a class (kabab case) [first letter of everyword is capital]
public:
    int speed;
    Airplane(int speed) {
        this->speed = speed;
        //other languages use other keywords (.) to access attributes
        // and they name the constructor  (constructor)[js] or (__init__)[py]
        // here we are dealing with pointers so we use the arrow operator (->) to access the values
    }
    // Airplane(int speed) : speed(speed) {} //other way to initialize the attributes
    int getSpeed() {
        return speed; // return this->speed;
    }
    void setSpeed(int speed) {
        this->speed = speed;
        // since they have the same name, we use the this keyword to access the attribute
    }
    static Airplane* create() {
        //for airplane only
        // so now the constructor and static are not inhereted
        return new Airplane(0);
    }
};
class Jet : public Airplane {
private:
    static const int SPEED = 2;
    //must be const as it's initialized inside the class block and it can't be accessed as a property
    // there is a convention to name a constant (must all letters be capital)
public:
    Jet(int speed) : Airplane(speed* SPEED) {}
    /*  A subclass inherits all the members (fields, methods, and nested classes)
     from its superclass. Constructors are not members,
     so they are not inherited by subclasses,
     but the constructor of the superclass can be invoked from the subclass. */
    void setSpeed(int speed) {
        Airplane::setSpeed(speed * SPEED);
    }
    void accelerate() {
        Airplane::setSpeed(getSpeed() * 2);
    }
    //can any body notice what is happining here???
    // i'm overrideing the behaviour in the subclass
    // and i'm also able to access the behaviour of the Global class!
    // and i'm also able to access getSpeed() without any prefixes like (this.|Airplane::)
    // like it's defined right here in this scope!

    // std::string to_string(Jet jet) {
    //     return "Jet speed: " + to_string(jet.getSpeed());
    // }
    //static functions are functions used with the constructor itself not to any object
    // and it's usually used as a convenient way to create objects with the help of the constructor
    static Jet createJet(int speed) {
        return Jet(speed);
    }
};

std::string to_string(Airplane airplane) {
    return "hello";
    //without changing function name, i can change the behaviour of the function
    // to make it work in many forms with things that are not related to each other
    // meaning that they (doesn't have the same interface)
}

//puzzle
void flyTest() {
    Airplane biPlane = Airplane(212);
    std::cout << biPlane.getSpeed() << endl;
    Jet boeing = Jet(422);
    std::cout << boeing.getSpeed() << endl;//speed*2
    int x{ 0 }; //x=0
    while (x < 4) {
        boeing.accelerate();
        std::cout << boeing.getSpeed() << endl;
        if (boeing.getSpeed() > 5000) biPlane.setSpeed(biPlane.getSpeed() * 2);
        else boeing.accelerate();
        x++;
    }
    std::cout << biPlane.getSpeed() << endl;
}