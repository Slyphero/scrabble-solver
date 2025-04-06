#include "../headers/letter.hpp"

#include <iostream>

unsigned int Letter::getOccurences() { return occurences; }

unsigned int Letter::getPoints() { return points; }

void Letter::decreaseOccurences() {
  if (occurences > 0) {
    occurences--;
  }
}

void Letter::print() {
  std::cout << "Letter : " << letter << " / Occurences : " << occurences
            << " / Points : " << points << std::endl;
}

void Letter::operator=(const Letter& newLetter) {
  letter = newLetter.letter;
  points = newLetter.points;
  occurences = newLetter.occurences;
}

bool Letter::operator==(const Letter& newLetter) {
  return (letter == newLetter.letter) && (points == newLetter.points);
}

bool Letter::operator!=(const Letter& newLetter) {
  return (letter != newLetter.letter) || (points != newLetter.points);
}