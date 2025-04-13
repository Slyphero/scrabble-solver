#include "letters_collection.hpp"

#include <chrono>
#include <iostream>
#include <random>

using namespace std;

unsigned int occurencesArray[NUMBER_OF_LETTERS] = {9, 2, 2, 3, 15, 2,  2, 2, 8,
                                                   1, 1, 5, 3, 1,  3,  3, 2, 1,
                                                   4, 2, 4, 1, 8,  10, 1, 2, 1};

unsigned int pointsArray[NUMBER_OF_LETTERS] = {1, 3,  3, 2, 1,  4,  2,  4,  1,
                                               8, 10, 1, 2, 1,  1,  3,  8,  1,
                                               1, 1,  1, 4, 10, 10, 10, 10, 0};

LettersCollection::LettersCollection() {
  for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) {
    char character = 65 + i;
    Letter letter(character, occurencesArray[i], pointsArray[i]);
    lettersCollection[i] = letter;
  }

  Letter letter('!', 1, 0);
  lettersCollection[26] = letter;
}

Letter LettersCollection::getLetter(unsigned int i) {
  return lettersCollection[i];
}

Letter LettersCollection::pickRandomLetter() {
  if (checkIfCollectionEmpty()) {
    return Letter('0', 0, 0);
  }
  auto now = chrono::high_resolution_clock::now().time_since_epoch();
  auto seed = chrono::duration_cast<chrono::nanoseconds>(now).count();

  mt19937 generator(seed);

  uniform_int_distribution<int> distribution(0, 25);

  int randomNumber = distribution(generator);

  while (lettersCollection[randomNumber].getOccurences() == 0) {
    randomNumber = distribution(generator);
  }
  lettersCollection[randomNumber].decreaseOccurences();
  return lettersCollection[randomNumber];
}

bool LettersCollection::checkIfCollectionEmpty() {
  for (unsigned int i = 0; i < NUMBER_OF_LETTERS; i++) {
    if (lettersCollection[i].getOccurences() != 0) {
      return false;
    }
  }
  return true;
}

void LettersCollection::print() {
  for (Letter letter : lettersCollection) {
    letter.print();
  }
}

unsigned int LettersCollection::getPoint(char letter) {
  return pointsArray[letter - 65];
}