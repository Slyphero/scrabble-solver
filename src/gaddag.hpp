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
  std::unordered_map<char, Gaddag *> gaddags;

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
  void insertDecomposition(const std::string &decomposition);

  /**
   * @brief Get all decomposition of a word
   * @param word : The word to decompose
   * @return The vector of all the decompositions
   */
  std::vector<std::string> decompose(const std::string &word);

  /**
   * @brief Main function to insert a word in the gaddag
   * @param word : The word to insert (all decompositions)
   */
  void insertWord(const std::string &word);

  /**
   * @brief Look if a decomposition is in the gaddag
   * @param decomposition : The decomposition to look for
   * @return true if the decomposition is found
   */
  bool checkIfDecompositionInGaddag(const std::string &decomposition);

  /**
   * @brief Look if a word is in the gaddag
   * @param word : The word to look for
   * @return true if the word is found
   */
  bool checkIfWordInGaddag(const std::string &word);

  /**
   * @brief Display the gaddag
   */
  void print(int depth = 0);

  bool checkIfFinal() const;

  /**
   * @brief Return the pointed gaddag if the key (letter) exists in
   *   the dictionary
   * @param letter : The key to look for
   * @return nullptr if the key is not found
   */
  Gaddag *getGaddagByLetter(char letter);

  /**
   * @brief Return if the path exists in the gaddag (whether the last node is
   *   final or not) for a subpattern like T+AS
   * @param pattern : The substring to look the path for
   * @return true if the path exists, false otherwise
   */
  bool checkIfSubpatternInGaddag(const std::string &pattern);

  /**
   * @brief Return if the path exists in the gaddag for a subword (for example
   *   AS in TAS)
   * @param subword : The subword to look the path for
   * @return true if the path exists, false otherwise
   */
  bool checkIfSubwordInGaddag(const std::string &subword);

  bool checkIfGaddagsEmpty() const;

  ~Gaddag();
};
