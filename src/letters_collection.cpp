#include "letters_collection.hpp"

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

unsigned int occurencesArray[NUMBER_OF_LETTERS] = { 9, 2, 2, 3, 15, 2, 2, 2, 8,
                                                    1, 1, 5, 3, 6, 6, 2, 1, 6,
                                                    6, 6, 6, 2, 1, 1, 1, 1 };

unsigned int pointsArray[NUMBER_OF_LETTERS] = { 1, 3, 3, 2, 1, 4, 2, 4, 1,
                                                8, 10, 1, 2, 1, 1, 3, 8, 1,
                                                1, 1, 1, 4, 10, 10, 10, 10 };

LettersCollection::LettersCollection() 
{
    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) 
    {
        char character = 65 + i;
        Letter letter(character, occurencesArray[i], pointsArray[i]);
        lettersCollection[i] = letter;
    }
}

Letter LettersCollection::getLetter(unsigned int i) 
{
    return lettersCollection[i];
}

Letter LettersCollection::pickRandomLetter() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::vector<int> weights;

    for (Letter letter : lettersCollection) 
    {
        weights.push_back(letter.getOccurences());
    }

    std::discrete_distribution<int> dist(weights.begin(), weights.end());
    int randomNumber = dist(gen);

    lettersCollection[randomNumber].decreaseOccurences();
    return lettersCollection[randomNumber];
}

bool LettersCollection::checkIfCollectionEmpty() 
{
    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) 
    {
        if (lettersCollection[i].getOccurences() != 0) 
        {
            return false;
        }
    }
    return true;
}

void LettersCollection::print() 
{
    for (Letter letter : lettersCollection) 
    {
        letter.print();
    }
}

unsigned int LettersCollection::getPoint(char letter) 
{
    return pointsArray[letter - 65];
}