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
        void addGaddag(char letter);
    public:
        Gaddag();
        void insert(string word);
        vector<string> decomp(string word);
        //decom a word and call insert with the decomposition of the word
        void insertWord(string word);
        bool research(string word);
        Gaddag operator=(Gaddag gaddag);
        tuple<bool, unsigned int> isLetterInSubGaddag(char letter);
        void print();
};
