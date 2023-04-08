#ifndef CONS_H
#define CONS_H

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

class Cons {
    public:
    Cons();
    Cons(std::string n, bool t, bool s);
    void addCons();
    // void addWishes(int wishToAdd);
    std::string getName();
    int getCons();
    int getOverCons();
    bool getType();
    bool getStars();
    int getAllWishes();
    
    
    private:
    std::string name;
    int copies;
    int overCopies;
    bool stars;
    bool type;
    float money;
    // int allWishes;
    
};

#endif
