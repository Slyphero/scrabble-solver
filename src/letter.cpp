#include "letter.hpp"

#include <iostream>

using namespace std;

Letter::Letter(char letter, unsigned int occurences, unsigned int points) 
{
    this->letter = letter;
    this->occurences = occurences;
    this->points = points;
}

unsigned int Letter::getOccurences() 
{
    return occurences;
}

unsigned int Letter::getPoints() 
{
    return points;
}

void Letter::decreaseOccurences() 
{
    if (occurences > 0) 
    {
        occurences--;
    }
}

void Letter::print() {
    cout << "Letter : "        << letter 
         << " / Occurences : " << occurences
         << " / Points : "     << points 
         << endl;
}

Letter Letter::operator=(const Letter& newLetter) 
{
    letter = newLetter.letter;
    occurences = newLetter.occurences;
    points = newLetter.points;
}