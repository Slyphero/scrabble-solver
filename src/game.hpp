#include "Player.hpp"
#include "gaddag.hpp"
#include "board.hpp"
#include "spot.hpp"
#include "direction.hpp"

#include <vector>

struct State {
    Player player;
    Gaddag gaddag;
    Board board;
    Spot spot;
}

class Game {
private:
    State state;

public:
    string buildMot(Board board, Direction direction, Position pos);
    bool is_possible(Board board, Direction direction, Position pos, Gaddag gaddag);
    int calculSubWord(Board board, Direction direction, Position pos);
    int scoreAll(Board board, Direction direction, Position pos);
}; 