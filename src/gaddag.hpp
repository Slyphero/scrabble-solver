#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

class Gaddag
{
private:
    bool is_final;
    vector<tuple<Gaddag, char>> next_gaddags;
public:
    Gaddag();
    void insert(std::string word);
    std::vector<std::string> decomp(std::string word);
};
