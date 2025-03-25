#include "board.hpp"

#include "letters_collection.hpp"
#include "Player.hpp"
#include "gaddag.hpp"

#include <iostream>
#include <sstream>
#include <cassert>
#include <chrono>

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

  Player player;

  player.drawLetters(myCollection);
  Letter letter2 = player.getLetter(3);
  player.printInventory();

  player.removeLetter(letter2);
  player.printInventory();

  std::cout << " ########################### " << std::endl;

  myCollection.print();
  

  Gaddag gaddag;
  //auto start = std::chrono::high_resolution_clock::now();
  gaddag.insertDictionnary();
  //auto end = std::chrono::high_resolution_clock::now();
  //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end -start);
  //std::cout << duration.count() <<std::endl;

  return 0 ;
}
