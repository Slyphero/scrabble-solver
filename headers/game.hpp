#include <queue>
#include <stack>
#include <vector>

#include "Player.hpp"
#include "board.hpp"
#include "direction.hpp"
#include "gaddag.hpp"
#include "position.hpp"
#include "spot.hpp"
#include "state.hpp"

class Game {
 private:
  State currentState;
  std::queue<State> nextPossibleStates;
  State bestNextState;

 public:
  Game(const Player& player, const Gaddag& gaddag, const Board& board,
       const Position& initialPosition, const Direction& direction)
      : currentState(player, gaddag, board, initialPosition, direction) {}
  std::string buildMot(Board board, Direction direction, Position pos);
  bool isPossible(Board board, Direction direction, Position pos,
                  Gaddag gaddag);
  int calculSubWord(Board board, Direction direction, Position pos);
  int scoreAll(Board board, Direction direction, Position pos);
  void getPossibleNextStates(Position position);
  State getBestNextState(const std::vector<State>& nextStates);
};