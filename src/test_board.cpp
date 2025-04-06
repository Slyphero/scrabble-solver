#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>

#include "../headers/board.hpp"
#include "../headers/gaddag.hpp"
#include "../headers/letters_collection.hpp"
#include "../headers/player.hpp"

int main() {
  Board board;

  std::cout << board << std::endl;

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

  std::cout << board << std::endl;

  /*
  LettersCollection lettersCollection;

  Gaddag gaddag;
  gaddag.insertDictionnary();

  Player player;
  player.drawLetters(lettersCollection);

  std::vector<State> possibleNextStates;

  Position initialPosition(8, 8);

  State state(player, gaddag, board, initialPosition, LEFT);

  Game game(state.player, state.gaddag, state.board, state.initialPosition,
            state.direction);

  player.printInventory();

  game.getPossibleNextStates(state, possibleNextStates);

  for (auto possibleNextState : possibleNextStates) {
    possibleNextState.player.printInventory();
  }
  */

  return 0;
}
