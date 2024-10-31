#include "Player.h"


Player::Player() : bullets(4), dead(false) {}  // Default constructor sets bullets to 4

Player::Player(int b) : bullets{b}, dead{false} {}

bool Player::shoot() {
    if (bullets <= 0) {
        return false;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, bullets);

    int result = dist(gen);

    bullets--;  // Decrement bullets after each shot

    if (result == 1) {
        dead = true;
        return true;
    } else {
        return false;
    }
}

int Player::getBullets() {
    return bullets;
}

bool Player::isDead() {
    return dead;
}

void Player::addCard(std::string c){
    hand.push_back(c);
}

bool Player::placeCard(std::string c){
    auto it = std::find(hand.begin(), hand.end(), c);
    if (it != hand.end()){
        hand.erase(it);
        return true;
    } else {
        std::cout << "invalid move: card not found" << std::endl;
        return false;
    }

}

void Player::lied(){lie = true;}
bool Player::didLie(){return lie;}

void Player::displayHand(){
    for (int i = 0; i < hand.size(); i++){
        std::cout << hand[i]  << " ";
    }
    std::cout << std::endl;
}