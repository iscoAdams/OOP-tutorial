#include <string>
#include <vector>
#include <iostream>
#include <map>








/*
    i use string to create strings with property name called value
    any string created has only the value of the string and the name of the var of course.
    the same works with int and other types.
    can u remember why we created an array? we created an array to create a list of
    the same thing to deal with all of this data at the same time and not one by one.
    we are programmers hate something called duplication of code and we try to avoid it as we can.
    consider we have grades for 6 students! I think 6 is fine, i can afford that. but what about 100 student??
    instead of hard coding all of this variables we create
    an array and any index of that array carry the  grades of each student.
    what if we need also other stuff?? like name and age and address and phone number and etc for every one.
    instead of creating all of these for every student with number and that's not a clean code of course
    it's a waste of time and effort, the solution here is to create a template (inventory) we can use
    to create other stuff as we prefer based on that template .
    u acn consider a template as exam paper with name,exam-id,exam-date and each student has it's own data
    any may they share some of them like exam-id and exam-date.
 */



















 // this is called a graph and it shows the roads of the city, each place contain a from-to places 
 // with a hyphen betwwen them to indecate that there is a direction between them. 
 // start-end
std::string roads[] = {
    "Alice's House-Bob's House", "Alice's House-Cabin",
    "Alice's House-Post Office", "Bob's House-Town Hall",
    "Daria's House-Ernie's House", "Daria's House-Town Hall",
    "Ernie's House-Grete's House", "Grete's House-Farm",
    "Grete's House-Shop", "Marketplace-Farm",
    "Marketplace-Post Office", "Marketplace-Shop",
    "Marketplace-Town Hall", "Shop-Town Hall"
};

struct Place {
    std::string name;
    std::vector<std::string> roads;
};
struct Road {
    std::string from, to;
};
struct City {
    std::vector<Place> places;
    std::vector<Road> roads;
};

void addRoad(City& city, std::string from, std::string to) {
    city.roads.push_back({ from, to });
    city.roads.push_back({ to, from });
}
void addRoads(City& city) {
    for (auto& road : roads) {
        std::string from = road.substr(0, road.find('-'));
        std::string to = road.substr(road.find('-') + 1, road.size());
        addRoad(city, from, to);
    }
}
void addPlace(City& city, std::string name) {
    city.places.push_back({ name, {} });
}
void addPlaces(City& city) {
    for (auto& road : city.roads) {
        bool found = false;
        for (auto& place : city.places) {
            if (place.name == road.from) {
                found = true;
                break;
            }
        }
        if (!found) addPlace(city, road.from);
    }
}
void connectRoadsToPlaces(City& city) {
    for (auto& place : city.places) {
        for (auto& road : city.roads) {
            if (road.from == place.name) {
                place.roads.push_back(road.to);
            }
        }
    }
}
void printCity(City city) {
    for (auto& place : city.places) {
        std::cout << place.name << " is connected to ";
        int cnt{};
        for (auto& road : place.roads) {
            std::cout << road;
            if (cnt++ < place.roads.size() - 1)  std::cout << " and ";
        }
        std::cout << std::endl;
    }
}
City createCity() { //constructor for the city
    City city;
    addRoads(city);
    addPlaces(city);
    connectRoadsToPlaces(city);
    return city;
}
// ..............................
/* unordered_map<std::string, int>places;
void indexing() {
    int k = 0;
    for (auto& road : roads) {
        std::string from = road.substr(0, road.find('-'));
        std::string to = road.substr(road.find('-') + 1, road.size());
        if (!places.count(from)) places[from] = k++;
        if (!places.count(to)) places[to] = k++;
    }
}
vector<vector<int>>roads2;
void createCity2() {
    indexing();
    roads2 = vector<vector<int>>(places.size(), vector<int>(places.size(), 0));
    for (auto& road : roads) {
        std::string from = road.substr(0, road.find('-'));
        std::string to = road.substr(road.find('-') + 1, road.size());
        roads2[places[from]].push_back(places[to]);
        roads2[places[to]].push_back(places[from]);
    }
}
void printCity2() {
    createCity2();
    for (auto& place : places) {
        std::cout << place.first << " is connected to ";
        int cnt{};
        for (auto& road : roads2[place.second]) {
            for (auto& place2 : places) {
                if (place2.second == road) {
                    std::cout << place2.first;
                    break;
                }
            }
            if (cnt++ < roads2[place.second].size() - 1) std::cout << " and ";
        }
        std::cout << std::endl;
    }
} */