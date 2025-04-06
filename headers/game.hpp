#include <vector>

#include "Player.hpp"
#include "board.hpp"
#include "direction.hpp"
#include "gaddag.hpp"
#include "spot.hpp"

struct Position {
  unsigned int line;
  unsigned int column;
  Position(unsigned int l, unsigned int c) : line(l), column(c) {}
  Position getNextPosition(Direction direction);
  void operator=(const Position& newPosition);
};

struct State {
  Player player;
  const Gaddag& gaddag;
  Board board;
  Position currentPosition;
  Direction direction;
  Position initialPosition;
  State(const Player& _player, const Gaddag& _gaddag, const Board& _board,
        const Position& _initialPosition, const Direction& _direction)
      : player(_player),
        gaddag(_gaddag),
        board(_board),
        currentPosition(_initialPosition),
        direction(_direction),
        initialPosition(_initialPosition) {}
};

class Game {
 private:
  State currentState;

 public:
  Game(const Player& player, const Gaddag& gaddag, const Board& board,
       const Position& initialPosition, const Direction& direction)
      : currentState(player, gaddag, board, initialPosition, direction) {}
  std::string buildMot(Board board, Direction direction, Position pos);
  bool isPossible(Board board, Direction direction, Position pos,
                  Gaddag gaddag);
  int calculSubWord(Board board, Direction direction, Position pos);
  int scoreAll(Board board, Direction direction, Position pos);
  void getPossibleNextStates(const State& state,
                             std::vector<State>& possibleNextStates);
  State getBestNextState(const std::vector<State>& nextStates);
};