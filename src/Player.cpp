#include "Player.hpp"

Player::Player(){
    point = 0;
}

void Player::add_point(unsigned int point){
    this->point += point;
}

void Player::draw(LettersCollection bag){
    if (bag.FUNCTIONOFRAPH() && inventory.size() == 7){
        //tant que le sac n'est pas vide ou que l'inventaire du joueur est inf à 7 piocher en enlevant les lettre du sac
    }

}

unsigned int Player::get_point(){
    return(point);
}