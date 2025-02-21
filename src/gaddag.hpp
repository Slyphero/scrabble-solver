#pragma once

#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Gaddag
{
    private:
        bool isFinal = false;
        unordered_map<char, Gaddag> gaddags;

    public:
        /**
         * @brief Gaddag's class constructor
         */
        Gaddag();

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
         * @brief Look if a word is in the gaddag
         * @param word : The word to look for
         * @return True if the word is found
         */
        bool checkIfInGaddag(const string& word);

        /**
         * @brief Overloading of the = operator for Gaddag
         * @return A Gaddag
         */
        Gaddag operator=(const Gaddag& gaddag);

        /**
         * @brief Display the gaddag
         */
        void print();
};
