#include "Player.hpp"

Player::Player(){
    points = 0;
}

void Player::addPoint(unsigned int points){
    this->points += points;
}

void Player::drawLetters(LettersCollection& bag)
{
    while (!bag.isCollectionEmpty() && inventory.size() < LIMIT_INVENTORY)
    {
        inventory.push_back(bag.pickRandomLetter());
    }

}

unsigned int Player::getPoint()
{
    return(point);
}

void Player::printInventory()
{
    std::cout <<"Player Inventory" << std::endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        inventory[i].print();
    }
}