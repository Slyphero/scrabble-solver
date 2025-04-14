#pragma once

#include <queue>
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
  std::queue<State> nextPossibleStates;
  State bestNextState;
  void clearNextStates();

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
   * @brief Fill the possibles next states from current game state,
   * starting of a specific position and a direction
   * @param position : Initial position
   * @param direction : A direction, vertical or horizontal
   */
  void getPossibleNextStates(Position position, Direction direction);

  void getAllPossibleNextStates();

  State getBestNextState();

  void showPossibleNextStates();
};