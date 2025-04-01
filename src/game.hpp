#include "Player.hpp"
#include "gaddag.hpp"
#include "board.hpp"
#include "spot.hpp"
#include "direction.hpp"

#include <vector>

struct Position {
    unsigned int line;
    unsigned int column;
    Position getNextPosition(Direction direction);
    void operator=(const Position& newPosition);
}

struct State {
    Player player;
    Gaddag gaddag;
    Board board;
    Position currentPosition;
    Direction direction;
    Position initialPosition;
};

class Game {
private:
    State currentState;    

public:
    string buildMot(Board board, Direction direction, Position pos);
    bool is_possible(Board board, Direction direction, Position pos, Gaddag gaddag);
    int calculSubWord(Board board, Direction direction, Position pos);
    int scoreAll(Board board, Direction direction, Position pos);
    void getPossibleNextStates(const State& state, std::vector<State>& possibleNextStates);    
    State getBestNextState(const std::vector<State>& nextStates);
}; 