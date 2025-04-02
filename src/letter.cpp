#include "letter.hpp"

#include <iostream>

using namespace std;

Letter::Letter() {
  letter = '0';
  occurences = 0;
  points = 0;
}

Letter::Letter(char letter, unsigned int occurences, unsigned int points) {
  this->letter = letter;
  this->occurences = occurences;
  this->points = points;
}

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