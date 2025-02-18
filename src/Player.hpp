#pragma once
//7 lettre dans son inventaire
#include "letter.hpp"
#include "letters_collection.hpp"
#include <vector>
#include <iostream>

const int LIMIT_INVENTORY = 7;

class Player{
    private:
        unsigned int point;
        std::vector<Letter> inventory;
    public:
        Player();
        //add point to the current score of the player
        void add_point(unsigned int point);
        //add lettre up to 7 at the inventory of the player
        void draw(LettersCollection& bag);
        unsigned int get_point();
        void print_inv();
};