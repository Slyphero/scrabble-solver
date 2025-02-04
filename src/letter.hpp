#pragma once

//ASCII 65 = A, 90 = Z
class Letter {
    private:
        char letter; // in [A, B, C, ..., X, Y, Z]
        unsigned int occurences;
        unsigned int points;
    public:
        Letter(char letter, unsigned int occurences, unsigned int points);
        unsigned int get_occurences();
        unsigned int get_points();
        void decrease_occurences();
        void print();
};