#pragma once

#include <iostream>

#include "bonus.hpp"

/* A spot on the board to place a letter */

struct Spot 
{
    // default initialization, no letter, no bonus
    // <=> letter = 0 autoconstructor
    Spot() : letter(0) {}

    Spot(const Spot &other) : letter(other.letter), bonus(other.bonus) {}

    Spot &operator=(const Spot &spot);

    // bonus spot initialization
    //  * lf is the bonus letter factor
    //  * wf is the bonus word factor
    Spot(unsigned char lf, unsigned char wf) : letter(0), bonus(lf, wf) {}

    // the letter placed on the spot, 0 if none
    char letter;

    // the bonus present on the spot
    Bonus bonus;
};

// display of the spot contents
std::ostream &operator<<(std::ostream &out, Spot s);
