#pragma once
//7 lettre dans son inventaire
#include "letter.hpp"
#include "letters_collection.hpp"
#include <vector>
#include <iostream>

using namespace std;

const int LIMIT_INVENTORY = 7;

class Player{
    private:
        unsigned int points;
        vector<Letter> inventory;
    public:
        Player();
        //add point to the current score of the player
        void addPoints(unsigned int points);
        //add lettre up to 7 at the inventory of the player
        void drawLetters(LettersCollection& bag);
        unsigned int getPoint();
        void printInventory();
};