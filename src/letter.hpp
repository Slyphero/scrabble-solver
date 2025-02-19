#pragma once

//ASCII 65 = A, 90 = Z
class Letter 
{
    private:
        char letter; // in [A, B, C, ..., X, Y, Z, !]
        unsigned int occurences;
        unsigned int points;
    public:
        /**
         * @brief : Letter constructor
         * @param letter : the character of the letter ex : A, B, C...
         * @param occurences : The number of occurences of this letter in the game
         * @param points : The score given by this letter
         */
        Letter(char letter, unsigned int occurences, unsigned int points);

        /**
         * @brief : Returns the number of occurences
         * @return : The number of occurences
         */
        unsigned int getOccurences();

        /**
         * @brief : Returns the number of points of the letter
         * @return : The number of points of the letter
         */
        unsigned int getPoints();

        /**
         * @brief : When a letter is picked, decrease its remaining occurences in the bag
         */
        void decreaseOccurences();

        /**
         * @brief : Display letter attributes
         */
        void print();

        /**
         * @brief Overloading of the = operator for letters
         * @return : A letter
         */
        Letter operator=(const Letter& newLetter); 
};