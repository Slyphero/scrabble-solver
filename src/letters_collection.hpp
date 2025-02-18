#pragma once

#include "letter.hpp"

#include <vector>

const int NUMBER_OF_LETTERS = 26;

class LettersCollection {
    private:
        std::vector<Letter> letters_collection;
    public:
        /**
         * @brief Constructor of LettersCollection
         */
        LettersCollection(); 

        /**
         * @brief Get the letter at i index in the collection
         * @return The i-th letter
         */
        Letter get_letter(unsigned int i);

        /**
         * @brief Draw a random letter from the collection
         * @return A random letter
         */
        Letter pick_random_letter();
        
        /**
         * @brief Check if the collection is empty
         * @return : True if the collection is empty
         */
        bool is_collection_empty();

        /**
         * @brief Display info about collection
         */
        void print();
};