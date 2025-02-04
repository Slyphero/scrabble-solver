#include "letter.hpp"

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

