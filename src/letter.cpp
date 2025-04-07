#include "letter.hpp"

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

Letter& Letter::operator=(const Letter& newLetter) {
  if (this != &newLetter) {
    letter = newLetter.letter;
    occurences = newLetter.occurences;
    points = newLetter.points;
  }
  return *this;
}

bool Letter::operator==(const Letter& newLetter) {
  return (letter == newLetter.letter) && (points == newLetter.points);
}

bool Letter::operator!=(const Letter& newLetter) {
  return (letter != newLetter.letter) || (points != newLetter.points);
}

char Letter::getLetter() const { return letter; }