#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>

#include "Player.hpp"
#include "board.hpp"
#include "gaddag.hpp"
// #include "game.hpp"
#include "letters_collection.hpp"

int main() {
  Board board;

  std::cout << board << std::endl;

  /*

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

  b.load(ss);

  */
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
  Gaddag gaddag;

  gaddag.insertWord("TAS");
  gaddag.insertWord("BATEAU");

  gaddag.print();

  return 0;
}
