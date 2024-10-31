#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>

class Player {
    int bullets;
    bool dead;
    std::vector<std::string> hand;
    bool lie = false;


public:
    Player(int b);
    Player();
    bool shoot();
    int getBullets();
    void displayHand();
    bool isDead();
    void addCard(std::string c);
    bool placeCard(std::string c);
    void lied();
    bool didLie();
};

#endif