#include "position.hpp"

Position operator+(Position p1, Position p2)
{
    return Position(p1.line + p2.line, p1.column + p2.column);
}

Position &Position::operator=(Position p)
{
    if (this != &p)
    {
        line = p.line;
        column = p.column;
    }
    return *this;
}

Position Position::findNextPosition(Direction direction,
                                    bool isPlusHasBeenFound)
{
    Position newPosition;

    if (isPlusHasBeenFound && direction == VERTICAL)
    {
        return Position(line + 1, column);
    }
    else if (isPlusHasBeenFound && direction == HORIZONTAL)
    {
        return Position(line, column + 1);
    }
    else if (!isPlusHasBeenFound && direction == VERTICAL)
    {
        return Position(line - 1, column);
    }
    else
    {
        return Position(line, column - 1);
    }
}

bool Position::checkIfTopOrLeft() { return (column == 0 || line == 0); }

bool Position::checkIfBottomOrRight() { return (column == 14 || line == 14); }