#pragma once

#include <algorithm>
#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Gaddag {
 private:
  bool isFinal;
  std::unordered_map<char, std::unique_ptr<Gaddag>> gaddags;

 public:
  /**
   * @brief Gaddag's class constructor
   */
  Gaddag() : isFinal(false) {}

  /**
   * @brief Insert the whole dictionary (data/dico.txt) in the Gaddag
   */
  void insertDictionnary();

  /**
   * @brief Auxilary function to insert one decomposition of a word in
   *     the gaddag
   * @param decomposition : the decomposition to insert
   */
  void insertDecomposition(const std::string& decomposition);

  /**
   * @brief Get all decomposition of a word
   * @param word : The word to decompose
   * @return The vector of all the decompositions
   */
  std::vector<std::string> decompose(const std::string& word);

  /**
   * @brief Main function to insert a word in the gaddag
   * @param word : The word to insert (all decompositions)
   */
  void insertWord(const std::string& word);

  /**
   * @brief Look if a decomposition is in the gaddag
   * @param decomposition : The decomposition to look for
   * @return true if the decomposition is found
   */
  bool checkIfDecompositionInGaddag(const std::string& decomposition);

  /**
   * @brief Look if a word is in the gaddag
   * @param word : The word to look for
   * @return true if the word is found
   */
  bool checkIfWordInGaddag(const std::string& word);

  /**
   * @brief Display the gaddag
   */
  // void print();

  void print(int depth);

  Gaddag* getGaddagByLetter(char letter);

  bool checkIfSubwordInGaddag(const std::string& subword);
};
