#pragma once

#include "letter.hpp"

#include <vector>

const int NUMBER_OF_LETTERS = 26;

class LettersCollection {
    private:
        std::vector<Letter> letters_collection;
    public:
        LettersCollection(); 
        Letter get_letter(unsigned int i);
        Letter pick_random_letter();
};