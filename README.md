# Liar's Bar on Terminal

## Description
Welcome to **Liar's Bar on Terminal** – a captivating, terminal-based simulation of the classic bluffing game "Liar’s Dice" reimagined in the world of card bars! Written in modern C++ with object-oriented programming principles, this game brings the excitement, strategy, and high stakes of Liar's Bars directly to your terminal. Get ready to outwit, outplay, and call out your opponents as you navigate through layers of bluff and intuition, all from the comfort of your command line.

## Installation
Follow these steps to set up and run **Liar's Bar on Terminal**:

1. **clone the repository**:
   ```bash
   git clone https://github.com/thinkaboutzuuu/Liars_Bar.git
2. **navigate**:
   ```bash
   cd Liars_bar
1. **dependencies**:
   ```bash
   make
1. **grant permission**:
   ```bash
   chmod +x game
1. **run**:
   ```bash
   ./game


# Gameplay Guide for Liar's Bar on Terminal

This guide explains the flow of **Liar's Bar on Terminal** and how each part of the game works. It describes the steps players follow and how the game proceeds based on player actions.

## Table of Contents
- [Game Initialization](#game-initialization)
- [Game Flow](#game-flow)
  - [Displaying Current Turn and Hand](#displaying-current-turn-and-hand)
  - [Placing Cards](#placing-cards)
  - [Guessing a Bluff](#guessing-a-bluff)
  - [Updating Game State](#updating-game-state)
- [End Condition](#end-condition)

---

## Game Initialization

1. **Player Count and Bullet Count**:
   - The game begins by prompting the user to enter the number of players (`n_p`), which must be 4 or fewer.
   - Then, the number of bullets (`game_hp`) is entered for each player's health.

   Example:\
    Please enter # players (≤ 4):\
    3\
    Please enter # bullets:\
    5

2. **Start the Game**:
- With these inputs, the `Game` object is created with the specified number of players and bullets.

## Game Flow

The game proceeds in rounds until there is only one player left. Each round consists of the following steps:

### Displaying Current Turn and Hand

- **Game Announcement**:
- The game announces the "Game of" card type (e.g., `"J"`, `"Q"`, `"K"`, `"A"`, `"Joker"`) selected at random from the deck.

- **Display Player's Turn and Hand**:
- The game shows the current player's turn and their hand.

### Placing Cards

1. **Prompt for Card Selection**:
- Players are asked to select the cards they wish to place. Each card selection is masked to keep the gameplay discreet.

2. **Placing Cards**:
- After entering their selection, the game tallies and processes each card placed by the player.

Example: Player placed 3 J

### Guessing a Bluff

1. **Guess Prompt**:
- The next player is asked if they believe the current player is lying about their card placement. The player can choose either `"y"` (yes) or `"n"` (no).

2. **Bluff Call (`game.callCheat()`)**:
- If a player believes a bluff was made (`"y"`), the game will check the player's honesty.
- Consequences of a correct or incorrect bluff call will be handled by the `callCheat()` method.

### Updating Game State

1. **Update Round (`game.update()`)**:
- The game updates relevant states such as current player status and health, checking for any new conditions created by the recent moves.

2. **Switch Turn (`game.switch_turn()`)**:
- The turn passes to the next player in a circular order, ensuring all players get their turns.

3. **Clear Placed Cards (`game.clearStack()`)**:
- The stack of placed cards is cleared to prepare for the next round.

## End Condition

- **Winner Determination**:
- The game continues until only one player is left. Once a single player remains (`game.foundWinner()`), that player is declared the winner, and the game ends with a congratulatory message.


   
