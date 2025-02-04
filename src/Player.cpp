#include "Player.hpp"

Player::Player(){
    point = 0;
    inventory = {};
}

void Player::add_point(unsigned int point){
    this->point += point;
}

void Player::draw(LettersCollection bag){
    if (bag == {} && inventory.size == 7)

}