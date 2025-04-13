#include "player.hpp"

void Player::addPoints(unsigned int points) { this->points += points; }

void Player::drawLetters(LettersCollection &bag) {
  while (!bag.checkIfCollectionEmpty() && inventory.size() < LIMIT_INVENTORY) {
    inventory.push_back(bag.pickRandomLetter());
  }
}

unsigned int Player::getPoints() { return points; }

void Player::printInventory() {
  std::cout << "Player Inventory" << std::endl;
  for (unsigned int i = 0; i < (unsigned int)inventory.size(); i++) {
    inventory[i].print();
  }
}

std::vector<Letter> Player::getInventory() { return inventory; }

Letter Player::getLetter(unsigned int i) { return inventory[i]; }

void Player::removeLetter(const Letter &letter) {
  for (unsigned int i = 0; i < (unsigned int)inventory.size(); i++) {
    if (inventory[i] == letter) {
      inventory.erase(inventory.begin() + i);
      break;
    }
  }
}

Player &Player::operator=(const Player &other) {
  if (this != &other) {
    points = other.points;
    inventory = other.inventory;
  }
  return *this;
}

void Player::createInventory(LettersCollection bag) {
  inventory.push_back(bag.getLetter(14));
  inventory.push_back(bag.getLetter(8));
  inventory.push_back(bag.getLetter(20));
  for (int i = 0; i < 4; i++) {
    inventory.push_back(bag.getLetter(i));
  }
}