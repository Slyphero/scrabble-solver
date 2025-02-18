#include "letter.hpp"

#include <iostream>

Letter::Letter(char letter, unsigned int occurences, unsigned int points) {
    this->letter = letter;
    this->occurences = occurences;
    this->points = points;
}

unsigned int Letter::get_occurences() {
    return occurences;
}

unsigned int Letter::get_points() {
    return points;
}

void Letter::decrease_occurences() {
    if (occurences > 0) {
        occurences--;
    }
}

void Letter::print() {
    std::cout << "Letter : " << letter 
              << " / Occurences : " << occurences
              << " / Points : " << points 
              << std::endl;
}

Letter Letter::operator=(Letter my_letter) {
    letter = my_letter.letter;
    occurences = my_letter.occurences;
    points = my_letter.points;
}