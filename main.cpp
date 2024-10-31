#include<vector>
#include <iostream>
#include<string>
#include<sstream>
#include "Player.h"
#include "Game.h"
#include <termios.h>
#include <unistd.h>
using namespace std;

string getMaskedInput() {
    string input;
    termios oldt, newt;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable echo
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read input
    getline(cin, input);

    // Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    cout << "\n";  // Move to the next line after input
    return input;
}

int main(int argc, char* argv[]){
    // game init
    int game_hp, n_p = 0;
    cout << "please enter # players (≤ 4): " << endl;
    cin >> n_p;
    cout << "please enter # bullets: " << endl;
    cin >> game_hp;
    Game game{n_p, game_hp};
    
    // game processing
    bool in_game = true;
    while (in_game){
        if (game.foundWinner()){
            in_game = false;
            break;
        }
        std::cout << "This is a game of: " << game.getGameOf() << std::endl;
        game.displayCurrentTurn();
        game.displayCurHand();

        // placing card
        cout << "select cards to place (seperated by space): " << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        string cards_to_place = getMaskedInput();
        // string cards_to_place;
        // getline(cin, cards_to_place);
        stringstream ss(cards_to_place);
        string c;
        int c_count = 0;
        while (ss >> c){
           game.placeCard(c); 
           c_count++;
        }
        game.donePlacing();
        cout << "player placed " << c_count << " " << game.getGameOf() << endl;

        // guessing card
        string guess; 
        cout << "take a guess whether he lied [y/n]: " << endl;
        cin >> guess;
        if (guess == "y"){
            game.callCheat();
        } 
        game.update();
        game.switch_turn();
        game.clearStack();
    }
}
