#pragma once
// 7 lettre dans son inventaire
#include <iostream>
#include <vector>

#include "letter.hpp"
#include "letters_collection.hpp"

const int LIMIT_INVENTORY = 7;

class Player
{
private:
    unsigned int points;
    std::vector<Letter> inventory;

public:
    /**
     * @brief Player class constructor
     */
    Player() : points(0) {}

    /**
     * @brief Copy constructor
     */
    Player(const Player &other)
        : points(other.points), inventory(other.inventory) {}

    /**
     * @brief Add points to the current score of the player
     * @param points : Number of points to add to the score
     */
    void addPoints(unsigned int points);

    /**
     * @brief Draw letters until the player has 7.
     * @param bag : The letters's bag to pick letters from
     */
    void drawLetters(LettersCollection &bag);

    /**
     * @brief Get player's score
     * @return Player's score
     */
    unsigned int getPoints();

    /**
     * @brief Display player's inventory
     */
    void printInventory();

    /**
     * @brief Returns player's current inventory
     * @return Player's current inventory
     */
    std::vector<Letter> getInventory();

    /**
     * @brief
     * @param
     * @return
     */
    Letter getLetter(unsigned int i);

    /**
     * @brief Remove the letter in argument of the player's inventory
     * @param letter : Letter to remove
     */
    void removeLetter(const Letter &letter);

    Player &operator=(const Player &other);

    void createInventory(LettersCollection bag);
};