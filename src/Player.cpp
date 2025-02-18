#include "Player.hpp"

Player::Player(){
    point = 0;
}

void Player::add_point(unsigned int point){
    this->point += point;
}

void Player::draw(LettersCollection bag){
    while (!bag.is_collection_empty() && inventory.size() < LIMIT_INVENTORY){
        inventory.push_back(bag.pick_random_letter());
    }

}

unsigned int Player::get_point(){
    return(point);
}

void Player::print_inv(){
    std::cout<<"Player Inventory"<< srd::endl;
    for (int i = 0; i < inventory.size(); i++){
        if (i = LIMIT_INVENTORY - 1)
            std::cout<<inventory[i]<<std::endl;
        std::cout<<inventory[i]<< " ; ";
    }
}