#pragma once

#include "letter.hpp"

const int NUMBER_OF_LETTERS = 27;

class LettersCollection
{
private:
    Letter lettersCollection[NUMBER_OF_LETTERS];

public:
    /**
     * @brief Constructor of LettersCollection
     */
    LettersCollection();

    /**
     * @brief Get the letter at i index in the collection
     * @return The i-th letter
     */
    Letter getLetter(unsigned int i);

    /**
     * @brief Draw a random letter from the collection
     * @return A random letter
     */
    Letter pickRandomLetter();

    /**
     * @brief Check if the collection is empty
     * @return : True if the collection is empty
     */
    bool checkIfCollectionEmpty();

    /**
     * @brief Display info about collection
     */
    void print();
    unsigned int getPoint(char letter);
};