#include "Player.hpp"

Player::Player(){
    point = 0;
}

void Player::add_point(unsigned int point){
    this->point += point;
}

void Player::draw(LettersCollection bag){
    while (bag.FUNCTION_EST_VIDE() && inventory.size() < LIMIT_INVENTORY){
        inventory.push_back(bag.FUNCTION_PIOCHER());
    }

}

unsigned int Player::get_point(){
    return(point);
}