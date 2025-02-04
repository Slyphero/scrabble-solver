#pragma once

#include "letter.hpp"

#include <vector>

const int NUMBER_OF_LETTERS = 26;

class LettersCollection {
    private:
        std::vector<Letter> letters_collection;
    public:
        LettersCollection(); 
        Letter getLetter(unsigned int i);
};