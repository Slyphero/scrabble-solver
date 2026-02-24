#pragma once

#include "direction.hpp"

struct Position 
{
    unsigned int line;
    unsigned int column;
    Position() : line(0), column(0) {}
    Position(unsigned int l, unsigned int c) : line(l), column(c) {}
    Position(const Position &other) : line(other.line), column(other.column) {}
    Position &operator=(Position p);
    Position findNextPosition(Direction direction, bool isPlusHasBeenFound);
    bool checkIfTopOrLeft();
    bool checkIfBottomOrRight();
    bool checkIfValid();
};

Position operator+(Position p1, Position p2);