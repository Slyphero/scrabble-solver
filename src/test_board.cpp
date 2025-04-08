#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>

#include "game.hpp"
#include "letters_collection.hpp"

int main()
{
    Board board;

    // std::cout << board << std::endl;

    std::stringstream ss;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "....PROJET....." << std::endl;
    ss << ".......O......." << std::endl;
    ss << ".......U......." << std::endl;
    ss << ".......E......." << std::endl;
    ss << ".......U......." << std::endl;
    ss << ".....SCRABBLE.." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;

    board.load(ss);

    // std::cout << board << std::endl;

    Gaddag gaddag;
    gaddag.insertDictionnary();

    LettersCollection bag;

    Player player;
    player.drawLetters(bag);

    Position initialPosition(9, 7); // On commence au E central

    Game game(player, &gaddag, board, initialPosition);

    game.getPossibleNextStates(initialPosition, HORIZONTAL);

    return 0;
}
