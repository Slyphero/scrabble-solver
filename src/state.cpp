#include "state.hpp"

State &State::operator=(const State &state)
{
    if (this != &state)
    {
        player = state.player;
        currentGaddag = state.currentGaddag;
        board = state.board;
        currentPosition = state.currentPosition;
        isPlusHasBeenFound = state.isPlusHasBeenFound;
    }
    return *this;
}