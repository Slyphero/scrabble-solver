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
}; 