#pragma once

#include <unordered_map>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;

class Gaddag
{
    private:
        bool isFinal;
        unordered_map<char, unique_ptr<Gaddag>> gaddags;

    public:
        /**
         * @brief Gaddag's class constructor
         */
        Gaddag();

        void dico();

        /**
         * @brief Auxilary function to insert one decomposition of a word in
         *     the gaddag
         * @param decomposition : the decomposition to insert
         */
        void insertDecomposition(const string& decomposition);

        /**
         * @brief Get all decomposition of a word
         * @param word : The word to decompose
         * @return The vector of all the decompositions 
         */
        vector<string> decompose(const string& word);

        /**
         * @brief Main function to insert a word in the gaddag
         * @param word : The word to insert (all decompositions)
         */
        void insertWord(const string& word);

        /**
         * @brief Look if a decomposition is in the gaddag
         * @param decomposition : The decomposition to look for
         * @return true if the decomposition is found
         */
        bool checkIfDecompositionInGaddag(const string& decomposition);

        /**
         * @brief Look if a word is in the gaddag
         * @param word : The word to look for
         * @return true if the word is found
         */
        bool checkIfWordInGaddag(const string& word);

        /**
         * @brief Display the gaddag
         */
        void print();
};
