#include "gaddag.hpp"

#include <iostream>

Gaddag::Gaddag() { isFinal = false; }

std::vector<std::string> Gaddag::decompose(const std::string& word) {
  std::vector<std::string> decompositions;
  for (unsigned int i = 0; i < (unsigned int)word.size(); i++) {
    std::string substring1 = word.substr(0, i + 1);
    std::string substring2 = word.substr(i + 1, word.size() - i - 1);
    reverse(substring1.begin(), substring1.end());
    decompositions.push_back(substring1 + "+" + substring2);
  }

  return decompositions;
}

void Gaddag::insertDecomposition(const std::string& decomposition) {
  Gaddag* currentGaddag = this;
  for (unsigned int i = 0; i < (unsigned int)decomposition.size(); i++) {
    char currentLetter = decomposition[i];
    // Si on trouve une arête correspondant a la lettre,
    // on continue sur le gaddag suivant
    if (currentGaddag->gaddags.find(currentLetter) !=
        currentGaddag->gaddags.end()) {
      currentGaddag = currentGaddag->gaddags[currentLetter].get();
    } else {
      // Sinon on crée un nouveau gaddag qu'on relie par l'arête à
      // la lettre correspondante
      std::unique_ptr<Gaddag> newGaddag(new Gaddag());
      currentGaddag->gaddags[currentLetter] = move(newGaddag);
      currentGaddag = currentGaddag->gaddags[currentLetter].get();
    }
  }

  currentGaddag->isFinal = true;
}

void Gaddag::insertWord(const std::string& word) {
  for (const std::string& decomposition : decompose(word)) {
    insertDecomposition(decomposition);
  }
}

void Gaddag::insertDictionnary() {
  std::ifstream file("../data/dico.txt");
  std::string currentLine = "";
  while (file >> currentLine) {
    if (currentLine.size() <= 15) {
      insertWord(currentLine);
    }
  }
  file.close();
}

bool Gaddag::checkIfDecompositionInGaddag(const std::string& decomposition) {
  Gaddag* currentGaddag = this;
  for (unsigned int i = 0; i < (unsigned int)decomposition.size(); i++) {
    char currentLetter = decomposition[i];
    // Si on ne trouve pas d'arête correspondant à la lettre,
    // on ne peut pas aller plus loin
    // on regarde donc si on est sur un noeud terminal
    if (currentGaddag->gaddags.find(currentLetter) ==
        currentGaddag->gaddags.end()) {
      return currentGaddag->isFinal;
    }
    // Sinon on continue avec le prochain Gaddag
    currentGaddag = currentGaddag->gaddags[currentLetter].get();
  }
  return currentGaddag->isFinal;
}

bool Gaddag::checkIfWordInGaddag(const std::string& word) {
  for (const std::string& decomposition : decompose(word)) {
    if (!checkIfDecompositionInGaddag(decomposition)) {
      return false;
    }
  }
  return true;
}

void Gaddag::print() {
  if (gaddags.size() == 0) {
    std::cout << std::endl;
    return;
  }

  for (const auto& [key, value] : gaddags) {
    std::cout << std::endl;
    std::cout << key;
    if (value != nullptr) {
      std::cout << "(";
      value->print();
      std::cout << ")";
    }
  }
}

Gaddag Gaddag::getGaddagByLetter(char letter) { return *gaddags[letter]; }

bool Gaddag::checkIfSubwordInGaddag(const std::string& subword) {
  Gaddag* currentGaddag = this;
  for (unsigned int i = 0; i < (unsigned int)subword.size(); i++) {
    char currentLetter = subword[i];
    if (currentGaddag->gaddags.find(currentLetter) ==
        currentGaddag->gaddags.end()) {
      return false;
    }
    currentGaddag = currentGaddag->gaddags[currentLetter].get();
  }
  return true;
}