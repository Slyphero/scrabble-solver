#include <board.hpp>
#include <gaddag.hpp>
#include <player.hpp>
#include <position.hpp>

struct State {
  Player player;
  Gaddag* currentGaddag;
  Board board;
  Position currentPosition;
  State(const Player& _player, Gaddag* _currentGaddag, const Board& _board,
        const Position& _currentPosition)
      : player(_player),
        currentGaddag(_currentGaddag),
        board(_board),
        currentPosition(_currentPosition) {}
};
