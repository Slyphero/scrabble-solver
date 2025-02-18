#include "letters_collection.hpp"

#include <iostream>

#include <random>
#include <chrono>

LettersCollection::LettersCollection() {
    unsigned int occurences_array[NUMBER_OF_LETTERS] = {
        9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2
    };

    unsigned int points_array[NUMBER_OF_LETTERS] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2,
        1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10
    };

    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) {
        char character = 65 + i;
        Letter letter(character, occurences_array[i], points_array[i]);
        letters_collection.push_back(letter);
    }
}

Letter LettersCollection::get_letter(unsigned int i) {
    return letters_collection.at(i);
}

Letter LettersCollection::pick_random_letter() {
    if (is_collection_empty()) {
        char zero = '0';
        Letter empty_letter(zero, 0, 0);
        return empty_letter;
    }

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto seed = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
    
    std::mt19937 generator(seed);

    std::uniform_int_distribution<int> distribution(0, 25);

    int random_number = distribution(generator);

    while (letters_collection.at(random_number).get_occurences() == 0) {
        random_number = distribution(generator);
    }

    letters_collection.at(random_number).decrease_occurences();
    return letters_collection.at(random_number);
}

bool LettersCollection::is_collection_empty() {
    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) {
        if (letters_collection.at(i).get_occurences() != 0) {
            return false;
        }
    }

    return true;
}

void LettersCollection::print() {
    for (Letter letter : letters_collection) {
        letter.print();
    }
}