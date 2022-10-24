#include <iostream>
#include <vector>
#include <string>
class Player {
    private:
        std::string name;
        int score;
    public:
        Player(std::string name, int score) : name(name), score(score) {}
        std::string getName() {
            return name;
        }
        int getScore() {
            return score;
        }
        void setScore(int score) {
            this->score = score;
        }
};
class Game {
    private:
        std::vector<Player*> players;
    public:
        Player* getPlayer(std::string name) {
            for (auto player : players) 
                if (player->getName() == name) 
                    return player;
                
            return NULL;
        }
        void addPlayer(Player* player) {
            players.push_back(player);
        }
};