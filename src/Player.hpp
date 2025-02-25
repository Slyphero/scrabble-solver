#pragma once
//7 lettre dans son inventaire
#include "letter.hpp"
#include "letters_collection.hpp"
#include <vector>
#include <iostream>

using namespace std;

const int LIMIT_INVENTORY = 7;

class Player
{
    private:
        unsigned int points;
        vector<Letter> inventory;
    public:
        /**
         * @brief Player class constructor
         */
        Player();

        /**
         * @brief Add points to the current score of the player
         * @param points : Number of points to add to the score
         */
        void addPoints(unsigned int points);

        /**
         * @brief Draw letters until the player has 7.
         * @param bag : The letters's bag to pick letters from
         */
        void drawLetters(LettersCollection& bag);

        /**
         * @brief Get player's score
         * @return Player's score
         */
        unsigned int getPoints();

        /**
         * @brief Display player's inventory 
         */
        void printInventory();
};