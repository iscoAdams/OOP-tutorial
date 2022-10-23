#include <iostream>
#include <vector>
#include <string>


class YoutubeChannel {
private:
    std::string Name;
    int SubscribersCount;
    std::vector<std::string> PublishedVideos;
protected:
    std::string ContentQuality;
    std::string OwnerName;
public: //once u see public that's called interface (that's how u interact with the class)
    YoutubeChannel(std::string name, std::string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = "Normal";
    }
    void getInfo() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "OwnerName: " << OwnerName << std::endl;
        std::cout << "SubscribersCount: " << SubscribersCount << std::endl;
        std::cout << "Videos: " << std::endl;
        for (std::string videoTitle : PublishedVideos) {
            std::cout << videoTitle << std::endl;
        }
    }
    void subscribe() {
        SubscribersCount++;
    }
    void unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }
    void publishVideo(std::string title) {
        PublishedVideos.push_back(title);
    }
    void checkAnalytics() {
        if (ContentQuality == "Normal")
            std::cout << Name << " has average quality content." << std::endl;
        else if (ContentQuality == "Good")
            std::cout << Name << " has great quality content." << std::endl;
        else if (ContentQuality == "Bad")
            std::cout << Name << " has poor quality content." << std::endl;
        else
            std::cout << Name << " has unknown quality content." << std::endl;
    }
};
class CookingYoutubeChannel : public YoutubeChannel {
public:
    CookingYoutubeChannel(std::string name, std::string ownerName) : YoutubeChannel(name, ownerName) {
        ContentQuality = "Good";
    }
    //I could type this function above in the superClass and make OwnerName public
    // but to make my self clear, all what is inside is just some words
    // that describes the channel itSelf that at all cases will be overriden
    // so why i should put it in the superClass?? it's usless code there
    void practise() {
        std::cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << std::endl;
    }
};
class SportsYoutubeChannel : public YoutubeChannel {
public:
    SportsYoutubeChannel(std::string name, std::string ownerName) : YoutubeChannel(name, ownerName) {
        ContentQuality = "Bad";
    }
    void practise() {
        //without changing the method name, i can define mine but with other behaviour
        //that add flexability as i don't have to change the behaviour of the method in the other classes
        //to creespond to that object createad with other classes

        std::cout << OwnerName << " is practicing sports, learning new techniques, experimenting with different sports..." << std::endl;
    }
};