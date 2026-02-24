#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>

#include "game.hpp"
#include "letters_collection.hpp"

void testScore(Game game, Board board) 
{
    Position pos(7, 7);
    std::cout << "le score total du coup est : "
              << game.scoreAll(board, VERTICAL, pos) << std::endl;
}

void testPossible(Player player, Gaddag *gaddag, Position pos) 
{
    Board board;

    std::stringstream ss;
    ss << "....LOVA......." << std::endl;
    ss << ".......R......." << std::endl;
    ss << ".......B......." << std::endl;
    ss << ".......R......." << std::endl;
    ss << ".......E......." << std::endl;
    ss << "........O......" << std::endl;
    ss << "........U.U...." << std::endl;
    ss << "....PROJETS...." << std::endl;
    ss << ".......OD.U...." << std::endl;
    ss << ".......U..R...." << std::endl;
    ss << ".......E......." << std::endl;
    ss << ".......UW......" << std::endl;
    ss << ".....SCRABBLE.." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;

    // XLine7 nom de la lettre placer ainsi que ça ligne
    board.load(ss);
    Game game(player, gaddag, board, pos);
    Position TLine7(8, 8);
    std::cout << "test sur le coup Vertical non valide : "
              << game.isPossible(board, VERTICAL, TLine7, gaddag) << std::endl;
    Position WLine11(11, 8);
    std::cout << "test sur le coup horrizontale non valide : "
              << game.isPossible(board, HORIZONTAL, WLine11, gaddag) << std::endl;
    Position SLine7(7, 10);
    std::cout << "test sur le coup Vertical valide : "
              << game.isPossible(board, VERTICAL, SLine7, gaddag) << std::endl;
    Position ALine0(0, 7);
    std::cout << "test sur le coup horrizontale valide : "
              << game.isPossible(board, HORIZONTAL, ALine0, gaddag) << std::endl;
}

int main() 
{
    Board board;

    std::stringstream ss;
    /*
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
    */
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;
    ss << "..............." << std::endl;

    board.load(ss);

    Gaddag gaddag;
    gaddag.insertDictionnary();

    LettersCollection bag;

    Player player;
    player.drawLetters(bag);

    std::cout << board << std::endl;

    player.printInventory();

    Position initialPosition(7, 7);

    Game game(player, &gaddag, board, initialPosition);

    std::pair<State, int> firstPlay = game.getBestPlayOnEmptyBoard();

    game.applyBestPlay(firstPlay, &gaddag, bag);

    std::pair<State, int> bestPlay = game.getBestOverallPlay(&gaddag);
    while (bestPlay.second != 0) 
    {
        game.applyBestPlay(bestPlay, &gaddag, bag);
        bestPlay = game.getBestOverallPlay(&gaddag);
    }

    return 0;
}
