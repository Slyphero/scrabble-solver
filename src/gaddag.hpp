#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

class Gaddag
{
    private:
        bool bIsFinal;
        vector<tuple<Gaddag, char>> nextGaddags;

        /**
         * @brief Add a gaddag to nextGaddags vector
         * @param newGaddag : newGaddag to add
         * @param letter : Letter of the vertex connecting current Gaddag
         *     to the new one
         */
        void addGaddag(const Gaddag& newGaddag, char letter);
    public:
        /**
         * @brief Gaddag's class constructor
         */
        Gaddag();

        /**
         * @brief Auxilary function to insert one decomposition of a word in
         *     the gaddag
         * @param word : the decomposition to insert
         */
        void insert(string word);

        /**
         * @brief Get all decomposition of a word
         * @param word : The word to decompose
         * @return The vector of all the decompositions 
         */
        vector<string> decompose(string word);

        /**
         * @brief Main function to insert a word in the gaddag
         * @param word : The word to insert
         */
        void insertWord(string word);

        /**
         * @brief Look if a word is in the gaddag
         * @param word : The word to look for
         * @return True if the word is found
         */
        bool research(string word);

        /**
         * @brief Overloading of the = operator for Gaddag
         * @return A Gaddag
         */
        Gaddag operator=(const Gaddag& gaddag);

        /**
         * @brief Check if the letter exists in the gaddag
         * @param letter : The letter to look for
         * @return A tuple<bool, unsigned int> : 
         *     bool : If the letter has been found
         *     unsigned int : The index of the subgaddag the letter has been 
         *                    found in
         */
        tuple<bool, unsigned int> isLetterInSubGaddag(char letter);

        /**
         * @brief Display the gaddag
         */
        void print();
};
