#include "Player.hpp"

Player::Player()
{
    points = 0;
}

void Player::addPoints(unsigned int points)
{
    this->points += points;
}

void Player::drawLetters(LettersCollection& bag)
{
    while (!bag.isCollectionEmpty() && inventory.size() < LIMIT_INVENTORY)
    {
        inventory.push_back(bag.pickRandomLetter());
    }

}

unsigned int Player::getPoints()
{
    return points;
}

void Player::printInventory()
{
    cout <<"Player Inventory" << endl;
    for (unsigned int i = 0; i < (unsigned int)inventory.size(); i++)
    {
        inventory[i].print();
    }
}

vector<Letter> Player::getInventory() 
{
    return inventory;
}

Letter Player::getLetter(unsigned int i)
{
    return inventory[i];
}

void Player::removeLetter(const Letter& letter)
{
    for (unsigned int i = 0; i < (unsigned int)inventory.size(); i++) 
    {
        if (inventory[i] == letter)
        {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

