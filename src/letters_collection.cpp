#include "lettersCollection.hpp"

#include <iostream>

#include <random>
#include <chrono>

using namespace std;

LettersCollection::LettersCollection() 
{
    unsigned int occurencesArray[NUMBER_OF_LETTERS] = {
        9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2
    };

    unsigned int pointsArray[NUMBER_OF_LETTERS] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2,
        1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10
    };

    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) 
    {
        char character = 65 + i;
        lettersCollection[i].character = character;
        lettersCollection[i].points = pointsArray[i]
        lettersCollection[i].occurences = occurencesArray[i];
    }
}

Letter LettersCollection::getLetter(unsigned int i) 
{
    return lettersCollection.at(i);
}

Letter LettersCollection::pickRandomLetter() 
{
    if (isCollectionEmpty()) 
    {
        return Letter('0', 0, 0);
    }

    auto now = chrono::high_resolution_clock::now().time_since_epoch();
    auto seed = chrono::duration_cast<chrono::nanoseconds>(now).count();
    
    mt19937 generator(seed);

    uniform_int_distribution<int> distribution(0, 25);

    int random_number = distribution(generator);

    while (lettersCollection.at(random_number).get_occurences() == 0) 
    {
        random_number = distribution(generator);
    }

    lettersCollection.at(random_number).decrease_occurences();
    return lettersCollection.at(random_number);
}

bool LettersCollection::isCollectionEmpty() {
    for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) 
    {
        if (lettersCollection.at(i).get_occurences() != 0) 
        {
            return false;
        }
    }

    return true;
}

void LettersCollection::print() {
    for (Letter letter : lettersCollection) 
    {
        letter.print();
    }
}