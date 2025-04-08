#pragma once

#include "board.hpp"
#include "gaddag.hpp"
#include "player.hpp"
#include "position.hpp"

struct State
{
    Player player;
    Gaddag *currentGaddag;
    Board board;
    Position currentPosition;
    bool isPlusHasBeenFound;

    State(const Player &_player, Gaddag *_currentGaddag, const Board &_board,
          const Position &_currentPosition, bool _isPlusHasBeenFound)
        : player(_player),
          currentGaddag(_currentGaddag),
          board(_board),
          currentPosition(_currentPosition),
          isPlusHasBeenFound(_isPlusHasBeenFound) {}

    State(const State &other)
        : player(other.player),
          currentGaddag(other.currentGaddag),
          board(other.board),
          currentPosition(other.currentPosition),
          isPlusHasBeenFound(other.isPlusHasBeenFound) {}

    State &operator=(const State &state);
};
