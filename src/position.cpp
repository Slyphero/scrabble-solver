#include <../headers/position.hpp>

Position Position::operator+(Position p1, Position p2) {
  return Position(p1.line + p2.line, p1.column + p2.column);
}

Position Position::operator=(Position p) { return Position(p.line, p.column); }

Position Position::findNextPosition(Direction direction,
                                    bool isPlusHasBeenFound) {
  Position newPosition;

  if (isPlusHasBeenFound && direction == HORIZONTAL) {
    return Position(line + 1, column);
  } else if (isPlusHasBeenFound && direction == VERTICAL) {
    return Position(line, column + 1);
  } else if (!isPlusHasBeenFound && direction == HORIZONTAL) {
    return Position(line - 1, column);
  } else {
    return Position(line, column - 1);
  }
}