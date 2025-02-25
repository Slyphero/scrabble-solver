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

  
  LettersCollection myCollection;
  myCollection.print();

  std::cout << "###################" << std::endl;

  Letter letter = myCollection.pickRandomLetter();

  letter.print();

  std::cout << "#####################" << std::endl;

  myCollection.print();

  Player player;

  std::cout << "######################" << std::endl;

  player.drawLetters(myCollection);
  player.printInventory();

  std::cout << " ########################### " << std::endl;

  myCollection.print();
  

  Gaddag gaddag;

  gaddag.insertDictionnary();
  return 0 ;
}
