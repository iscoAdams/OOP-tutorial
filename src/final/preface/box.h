#include <string>
#include <vector>
#include <chrono>
#include <thread>
struct ball {
    //  Question:
    //  can I make it class?
    std::string color;
    void printBall() { //delegation (we will know more about it the next time)
        std::cout << "\t" << color << " ball";
    }
};
class Box {
    //i can take a color from the user and then i create a boll here & add it to my vector
    // but which is better? 
    // can any one answer me?
    std::vector<ball> balls; //private (can't see the balls)
    bool isOpen;
public:
    Box() : isOpen{ false } {} //by default the box is closed
    void open() {
        isOpen = true;
        std::cout << "------opened" << std::endl;
    }
    void close() {
        isOpen = false;
        std::cout << "------closed" << std::endl;
    }
    void addBall(ball b) {
        balls.push_back(b);
    }
    void showBalls() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        if (isOpen) {
            if (balls.empty()) cout << "There are no balls yet here\n";
            else {
                cout << "there are " << balls.size() << " balls here:\n";
                for (auto& ball : balls) {
                    ball.printBall();
                    cout << endl;
                }
            }
        }
        else  std::cout << "sorry buddy, The box is closed" << std::endl;
        //after seeing what is inside, 3 seconds waited and the box is closed again (if it's not already closed)
        if (isOpen) {
            std::this_thread::sleep_for(std::chrono::milliseconds(2200));
            close();
        }
    }
};

// int t =1; if we try to globally define it again it will complain  
// (in namespace all variables are accessed and that's exactly the opposite of encapsulation)