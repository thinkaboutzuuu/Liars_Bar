#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"  
#include <string>


class Game {
    std::vector<Player> players;  
    const int n_player;
    std::vector<std::string> deck;
    std::string game_of;
    Player *cur_player; // place card
    Player *next_player; // calls cheat
    std::vector<std::string> card_stack;
    int cur_n_players;

public:
    // Constructor
    Game(int n_player, int hp);

    void placeCard(std::string c);
    bool foundWinner();
    void clearStack();
    std::string getGameOf();
    void displayCurrentTurn();
    void displayCurHand();
    void donePlacing();
    void callCheat();
    void switch_turn();
    void update();

};

#endif