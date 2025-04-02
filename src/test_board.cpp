#include <cassert>
#include <chrono>
#include <iostream>
#include <sstream>

#include "Player.hpp"
#include "board.hpp"
#include "gaddag.hpp"
#include "game.hpp"
#include "letters_collection.hpp"

int main() {
  Board b;

  std::cout << b << std::endl;

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

  Gaddag gaddag;
  auto start = std::chrono::high_resolution_clock::now();
  gaddag.insertDictionnary();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << duration.count() << std::endl;

  State state;

  state.direction = TOP;

  std::cout << state.direction << std::endl;

  return 0;
}
