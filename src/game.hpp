#pragma once

#include <stack>
#include <vector>

#include "board.hpp"
#include "direction.hpp"
#include "gaddag.hpp"
#include "letters_collection.hpp"
#include "player.hpp"
#include "position.hpp"
#include "state.hpp"

class Game {
 private:
  State currentState;
  State bestNextState;

 public:
  Game(const Player &player, Gaddag *gaddag, const Board &board,
       const Position &initialPosition)
      : currentState(player, gaddag, board, initialPosition, false),
        bestNextState(player, gaddag, board, initialPosition, false) {}

  std::string buildMot(Board board, Direction direction, Position pos);

  bool isPossible(Board board, Direction direction, Position pos,
                  Gaddag *gaddag);

  int calculSubWord(Board board, Direction direction, Position pos);

  int scoreAll(Board board, Direction direction, Position pos);

  /**
   * @brief
   * @param position : Initial position
   * @param direction : A direction, vertical or horizontal
   */
  std::pair<State, int> getBestPlayFromPosition(Position position,
                                                Direction direction);

  std::pair<State, int> getBestPlayOnEmptyBoard();

  void getAllPossibleNextStates();
};