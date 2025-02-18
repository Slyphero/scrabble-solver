#include "board.hpp"

#include "letters_collection.hpp"
#include "Player.hpp"
#include "gaddag.hpp"

#include <iostream>
#include <sstream>

int main() {
  Board b ;

  std::cout << b << std::endl ;

  std::stringstream ss ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "....PROJET....." << std::endl ;
  ss << ".......O......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".......E......." << std::endl ;
  ss << ".......U......." << std::endl ;
  ss << ".....SCRABBLE.." << std::endl ;
  ss << "..............." << std::endl ;
  ss << "..............." << std::endl ;

  b.load(ss) ;

  std::cout << b << std::endl ;

  /*
  LettersCollection my_collection;
  my_collection.print();

  std::cout << "###################" << std::endl;

  Letter letter = my_collection.pick_random_letter();

  letter.print();

  std::cout << "#####################" << std::endl;

  my_collection.print();

  Player player;

  std::cout << "######################" << std::endl;

  player.draw(my_collection);
  player.print_inv();

  std::cout << " ########################### " << std::endl;

  my_collection.print();
  */

  Gaddag my_gaddag;

  std::vector<std::string> decomposition;

  for (std::string str : my_gaddag.decomp("BATEAU")) {
    std::cout << str << std::endl;
    decomposition.push_back(str);
  }

  return 0 ;
}
