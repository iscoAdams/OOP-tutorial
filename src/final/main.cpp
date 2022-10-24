//headers & libraries
#include <iostream>

//guitar-shop dependencies
// #include "src/guitar-shop/guitar.h"
// #include "src/guitar-shop/inventory.h"
#include "guitar-shop/v0.1/test-drive.h"

//preface dependencies
#include "preface/airplane.h"
#include "preface/box.h"
#include "preface/city.h"
#include "preface/game.h"
#include "preface/girlFriend.h"
#include "preface/mall.h"
#include "preface/matrix.h"
// #include "preface/product.h" //there are two product classes (take care)
#include "preface/rabbit.h"
#include "preface/youtubeChannel.h"

//utils dependencies
#include "../utils/out.h"
#include "../utils/io.h"
// using namespace std;

// vector<string> to_string(vector<int> a) {
//     vector<string> result;
//     for (int i{ 0 }; i < a.size(); i++)
//         result.push_back(to_string(a[i]));
//     return result;
// }

// int sumOfRange(int i) {
//      //let's consider that there is no (N*N+1)/2 low to make it get clearer
//      //even though i tried to write that formula, there will be no abstraction but if it is in 
//      //the form of a function that do what is wanted from it, it will be more abstract 
//      //and not all cases will be the abstracted slower than the non-abstracted one
//     if (!i) return 0;
//     return i + sumOfRange(i - 1);
// }
int main() {
    IO();
    out("here we go! \n");



    //abstraction 
    //  i don't consider it as a concept, but as a tool
    // it can be sued or seen any where of my program 
    //that's a less abstracted style but faster (it's iterative ) and iterative is faster than recursive
    // int sum{ 0 }, range{ 10 };
    // while (range) {sum += range--;}
    // cout << sum << endl;

    //more abstracted style but it's slower
    // cout << sumOfRange(10) << endl;


    // printCity(createCity());
    // cout <<"-----------------------"<<endl;
    // printCity2(); //less abstracted style but still abstracted


    //if u don't remember the order of values, just hover on the constructor here
    // Product shoes = Product("shoes", "large", 2, 20.22);
    // Product shirt = Product("shirt", "medium", 3, 10);
    // Product pants = Product("pants", "small", 1, 15);
    // Product bra = Product("bra", "large", 2, 20);
    // Product socks = Product("socks", "medium", 3, 10);

    // shoes.print();

    // Guitar guitar = Guitar("11277", 3999.95, "Collings", "CJ", "acoustic", "Indian Rosewood", "Sitka");
    // cout << guitar.getPrice() << endl;
    // findGuitar();

        // Matrix matrix = Matrix(2, 2);
        // matrix.setElement(0, 0, 1);
        // matrix.setElement(0, 1, 2);
        // matrix.setElement(0, 2, 3);
        // matrix.setElement(1, 0, 4);
        // matrix.setElement(1, 1, 5);
        // matrix.setElement(1, 2, 6);
    // matrix.print();

        // SymmetricMatrix symmetricMatrix = SymmetricMatrix(2);
        // symmetricMatrix.setElement(0, 0, 1);
        // symmetricMatrix.setElement(0, 1, 2);
        // symmetricMatrix.setElement(1, 1, 1);
    // symmetricMatrix.print();

        // PairMatrix pairMatrix = PairMatrix(2, 2);
    // pairMatrix.print();

        // std::this_thread::sleep_for(std::chrono::seconds(5));
        // Every C++ program has at least one thread contain main() program
        // std::thread t1(printHello);
        // since c++11, we can use lambda function to create multi threads
        // but don't care about it, it's not the point here
    // cout << "Hello, World!" << endl;



        // Box box = Box();
        // box.open();
        // box.addBall(ball{ "🔴" });
        // box.addBall(ball{ "🟢" });
        // box.addBall(ball{ "🟡" });
        // box.showBalls();
        // box.showBalls(); //try to show them again
        /*
            after simulating the box, can u see the output in the output file here?   -->
        can u see the content again even if u don't close the box manually??

            The question here...
            is there any encapsulation here?
            u said that any one can consider it's usage as a black box that does some magic,
            and u only have access to it with the interface u declared
            or in other words the only way u define to be valid!
            and if so it's encapsolation, what is used for?
            u said that it add flexability to the code, but how?
        */
        //    answer: yes, there is encapsulation here, i only allow him to show the content
        //    the way i declare.


        // Airplane airplane = Jet(20); //????
        // cout << airplane.getSpeed() << endl;
        // any subclass can stand for it's parent class
    // here i'm using jet constructor (duple speed remember?) to create an airplane object 

        //polymorphism
        // because it's the most obscure one, i made alot of examples so that we can digest it
        // oncce we finish.
        // int x =10;
        // cout <<to_string(x) << endl; //returns the string representation of the number
        // Jet jet = Jet(20); 
        // cout << to_string(jet) << endl; // I override the to_string() wich is not allowd to work with objects to get a meaningful output
        // and notice i defined it to work with Airplane, though since Jet is a child of Airplane, it works with it too
        // in other words it looks like a Airplane and it has the same interface so it works just fine
        // and i'm also able to override it again in every subclass.
    // and this is the power of polymorphism, i can use the same interface to work with different objects

        // auto jet = Airplane::create(); 
        //auto is like let or var in js make the compiler guess the type in the runTime
        // here i'm using a static method to create a jet object
    // auto a = Airplane(10);

        // Rabbit blackRabbit = Rabbit("black");
        // Rabbit whiteRabbit = Rabbit("white");
        // cout << to_string(blackRabbit) << endl;
        // at first to_string shouldn't work here because int and object don't share the same interface
    // but since i make it somehow happen, they now can share the same function but with different forms

        //     When a piece of code
        // is written to work with objects that have a certain interface—in this
        // case, a toString method—any kind of object that happens to support
    // this interface can be plugged into the code, and it will just work

        // a for/of loop can loop over several kinds of data structures (many forms)
        // they share the same interface (iteratable) we can loop over them
        // so that this loop can work with any of them
    // and since it works with any one of them so it's polymorphism

        // CookingYoutubeChannel cookingChannel("Amy's Kitchen", "Amy");
        // cookingChannel.publishVideo("Apple Pie");
        // cookingChannel.publishVideo("Chocolate Cake");
        // cookingChannel.publishVideo("Pancakes");
        // cookingChannel.getInfo();
        // cookingChannel.checkAnalytics();
        // cookingChannel.practise();
        // cout << "-----------------------" << endl;
        // SportsYoutubeChannel sportsChannel("John's Sports", "John");
        // sportsChannel.publishVideo("How to tackle");
        // sportsChannel.publishVideo("How to shoot");
        // sportsChannel.publishVideo("How to pass");
        // sportsChannel.getInfo();
        // sportsChannel.checkAnalytics();
        // sportsChannel.practise();
        // they have the same name but they behave differently how they do it??
        // i did that by overriding the methods in the child class
        // and without being able to do that i have to change this behaviour to corresponds
        // to the new subClass and that will be a mess and nothing is isolated 
        // and threre are no flixability, but by polimonrphism i can do that
    // and have different forms of the same function to work with different objects

        // vector<int> a = { 1, 2, 3, 4, 5 };
        // cout << to_string(a) << endl;
        // ....
        // vector<string> a = to_string(vector<int>{1, 2, 3});
        // for (int i{ 0 }; i < a.size(); i++)
    //     cout << a[i] << " ";



        //vector, dynamicArray, Enum, out function, and pair explain
        // array<int, 5u> a = { 1, 2, 3, 4, 5 };
        // int* arr = a.data(); //dynamic and stored in heap
        // for (int i{ 0 }; i < a.size(); i++)
        //     cout << arr[i] << " ";
        // int n; cin>>n;
        // int *a = new int[5]{ 1, 2, 3, 4, 5 };
        // int *a = new int[n];
        // vector<int>aa(n);
        // pair<int, int>a = { 1,2 };
        // cout << a.first << " " << a.second << endl;
        // pair<string, int>a[2];
        // a[0] = { "jan",1 };
        // a[1] = { "feb",2 };
        // for (int i{ 0 }; i < 2; i++)
    //     cout << a[i].first << " " << a[i].second << endl;

    // vector <int> a = { 1,2,3,4,5 };
    // for (int i{ 0 }; i < a.size(); i++)//without iterator
    //     cout << a[i] << " ";
    // for (auto i : a)//short hand (for of loop) with iterator [here i'm creating a copy of it to iterate over it not a referance]
    //     cout << i << " ";
    // for (auto it = a.begin(); it != a.end(); it++) //iterator
    //     cout << *it << " ";

    // out("Hello, World!", 2, 3);

        // enum Color {
        //     RED,
        //     GREEN,
        //     BLUE
        // };
    // Color color = BLUE;
    // i give it to the compiler insstead of any logical mess of type (typo)
    // i acn define available ranges or allowed values only to be passed and they are somehow constants 
    // so that's way they all are capital letters

    // ShoppingCart cart;
    // cart.addProduct(new Cheese (FRESH,200, 0.5));
    // cart.addProduct(new Cheese (OLD,200, 0.5));
    // cart.addProduct(new Fruit (APPLE,100, 2));
    // cart.addProduct(new Fruit (BANANA,100, 2));
    // cout << Kashier::askKashier()->checkout(cart) << endl;



    //composition (PART-OF) (one way) relationship 
    // if there no game there is no player
    // player can't exist without a game 
    // another ex: room can't exist without a house 
    // Game currentGame;
    // currentGame.addPlayer(new Player("natasha", 0));
    // currentGame.addPlayer(new Player("string", 0));
    // Player* winnerPlayer = currentGame.getPlayer("natasha");
    // winnerPlayer->setScore(10); //the winner take 10 points
    // i can't add points without winning a game 
    // or in other words without a game :)
    // cout << winnerPlayer->getScore();


    //aggregation is (HAS-A) one way relationship
    // a wallet has money, yet the money can exist without the wallet
    // employee has an address, yet the address can exist without the employee (address of my company won't change by my death or leaving the company)
    // a boy-friend has a girl-friend yet the girlfriend can exist without her boy-friend (not a big deal)
    // BoyFriend boyFriend = BoyFriend("Ahmed", 20);
    // GirlFriend* girlFriend = new GirlFriend("Sara", 19, &boyFriend);
    // girlFriend->showSomeLove();
    // girlFriend->walk();
}