#include "letters_collection.hpp"

#include <iostream>

LettersCollection::LettersCollection() {
    unsigned int occurences_array[NUMBER_OF_LETTERS] = {
        9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2
    };

    unsigned int points_array[NUMBER_OF_LETTERS] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2,
        1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10
    };

    for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
        char character = 65 + i;
        Letter letter(character, occurences_array[i], points_array[i]);
        letters_collection.push_back(letter);
    }
}

Letter LettersCollection::getLetter(unsigned int i) {
    return letters_collection.at(i);
}