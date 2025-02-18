#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

class Gaddag
{
private:
    bool is_final;
    std::vector<std::tuple<Gaddag, char>> next_gaddags;
public:
    Gaddag();
    void insert(std::string word);
    std::vector<std::string> decomp(std::string word);
    //decom a word and call insert with the decomposition of the word
    void insert_word(std::string word);
    bool research(std::string word);
};
