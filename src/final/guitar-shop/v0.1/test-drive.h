#include <bits/stdc++.h>
#include "guitar.h"
#include "inventory.h"
using namespace std;
void findGuitar() {
    //I used this synntax to create a function inside a function
    // to make all my vars local to this function
    // i'm using function scope to make my code more separated
    // and to make sure that i'm making the inventory object i just created
    // to search for a guitar i just added to it.
    Inventory inventory = Inventory();
    function<void()> initiallizeInventory = [&]() {
        inventory.addGuitar(
            "V95693",
            1499.95,
            "fender",
            "Stratocastor",
            "electric",
            "Alder",
            "Alder"
        );
    };
    initiallizeInventory(); //initiallize inventory with the object inventory created above
    Guitar whatErinLikes = Guitar("", 0, "fender", "Stratocastor", "electric", "Alder", "Alder");
    Guitar guitar = inventory.search(whatErinLikes);
    if (guitar.getSerialNumber() != "")
        cout << "Erin, you might like this " << guitar.getBuilder() << " " <<
        guitar.getModel() << " " << guitar.getType() << " guitar:\n" <<
        guitar.getBackWood() << " back and sides,\n" << guitar.getTopWood() <<
        " top.\nYou can have it for only $" << guitar.getPrice() << "!\n";

    else cout << "Sorry, Erin, we have nothing for you.\n";
}