#include "Game.h"
#include <iostream>
#include <random>

// helper function
std::string drawCard(std::vector<std::string>& deck) {
    if (deck.empty()) {
        return "No more cards in the deck!";
    }

    // Set up random number generation for index selection
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, deck.size() - 1);

    // Select a random index
    int randomIndex = dist(gen);
    std::string drawnCard = deck[randomIndex];

    // Remove the card from the deck
    deck.erase(deck.begin() + randomIndex);

    return drawnCard;
}

// constructor
Game::Game(int n_player, int hp): n_player{n_player}, cur_n_players{n_player}{
    for (int i = 0; i < n_player; i++){
        players.push_back(Player(hp));
    }

    deck = {"J", "J", "J", "J", "J", "J",
            "Q", "Q", "Q", "Q", "Q", "Q",
            "K", "K", "K", "K", "K", "K",
            "A", "A", "A", "A", "A", "A",
            "Joker", "Joker"};

    // generage game of x
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, deck.size() - 3);
    int randomIndex = dist(gen);
    game_of = deck[randomIndex];

    // assign hand
    for (int i = 0; i < n_player; i++){
        for (int j = 0; j < 6; j++){
            players[i].addCard(drawCard(deck));
        }
    }

    cur_player = &players[0];
    next_player = &players[1];
}

void Game::placeCard(std::string c){
    if (cur_player->placeCard(c)){
        card_stack.push_back(c);
    } 
}

void Game::clearStack(){
    card_stack.clear();
}

void Game::donePlacing(){
    for (int i = 0; i < card_stack.size(); i++){
        if (card_stack[i] != game_of){
            cur_player->lied();
        }
    }
}

void Game::callCheat(){
    if (cur_player->didLie()){
        cur_player->shoot();
        if (cur_player->isDead()){
            cur_n_players--;
        }
    } else{
        next_player->shoot();
        if (next_player->isDead()){
            cur_n_players--;
        }
    }
    
}

void Game::switch_turn() {
    // Find the index of cur_player in the players vector
    int cur_index = -1;
    for (int i = 0; i < n_player; ++i) {
        if (&players[i] == cur_player) {  
            cur_index = i;
            break;
        }
    }

    if (cur_index == -1) {
        std::cout << "Error: Current player not found in the players vector.\n";
        return;
    }

    // Loop to find the next alive player for cur_player
    int next_index = (cur_index + 1) % n_player;
    while (players[next_index].isDead()) {
        next_index = (next_index + 1) % n_player;
        if (next_index == cur_index) {  // Avoid infinite loop if all players are dead
            foundWinner();
            return;
        }
    }

    // Loop to find the next alive player for next_player, starting from next_index + 1
    int after_next_index = (next_index + 1) % n_player;
    while (players[after_next_index].isDead()) {
        after_next_index = (after_next_index + 1) % n_player;
        if (after_next_index == next_index) {  
            std::cout << "Only one alive player remaining.\n";
            next_player = &players[next_index];
            return;
        }
    }

    // Update cur_player and next_player
    cur_player = &players[next_index];
    next_player = &players[after_next_index];
}

void Game::update(){
    for (int i = 0; i < n_player; i++){
        if (players[i].isDead()){
            std::cout << "ANNOUCEMENT: player " << i << " died" << std::endl; 
        }
    }

    for (int i = 0; i < n_player; i++){
        if (!players[i].isDead()){
            std::cout << "Player " << i << ": " << std::endl   
                    << "bullets: " << players[i].getBullets() << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "Player " << i << " is dead" << std::endl;
            std::cout << std::endl;
        }

    }
}

void Game::displayCurrentTurn() {
    int cur_index = -1;  // Variable to store the index of cur_player

    // Find the index of cur_player in the players vector
    for (int i = 0; i < n_player; ++i) {
        if (&players[i] == cur_player) {  // Check by address to match cur_player
            cur_index = i;
            break;
        }
    }

    if (cur_index != -1) {
        std::cout << "player " << cur_index << "'s turn: "<< "\n";
    }
}

bool Game::foundWinner() {
    // Check if only one player remains
    if (cur_n_players == 1) {
        // Find the index of the player who is not dead
        for (int i = 0; i < n_player; ++i) {
            if (!players[i].isDead()) {  
                std::cout << "Player " << i << " won!\n";
                return true;
            }
        }
    }
    // No winner yet
    return false;
}

void Game::displayCurHand(){
    cur_player->displayHand();
}

std::string Game::getGameOf(){
    return game_of;
}
