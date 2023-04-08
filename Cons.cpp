#include "Cons.h"

Cons::Cons(std::string n, bool t, bool s) {
    name = n;
    copies = 0;
    overCopies = 0;
    // allWishes = 0;
    type = t; //0 is weapon, 1 is character
    stars = s; //0 is a 4 star, 1 is a 5 star
}

Cons::Cons() {
    name = "unknown";
    copies = 0;
    overCopies = 0;
    // allWishes = 0;
    type = 0; //0 is weapon, 1 is character
    stars = 0; //0 is a 4 star, 1 is a 5 star
}

void Cons::addCons() {
    if(type){
        if (copies < 6) {
            copies++;
        } else {
            overCopies++;
        }
    } else {
        if (copies < 4) {
            copies++;
        } else {
            overCopies++;
        }
    }
}

int Cons::getCons() {
    return copies;
}

int Cons::getOverCons() {
    return overCopies;
}

// void Cons::addWishes(int wishToAdd) {
//     allWishes += wishToAdd;
// }

// int Cons::getAllWishes() {
//     return allWishes;
// }

std::string Cons::getName() {
    return name;
}

bool Cons::getStars() {
    return stars;
}

bool Cons::getType() {
    return type;
}