#include "gaddag.hpp"

Gaddag::Gaddag(){
    is_final = false;
}

std::vector<std::string> Gaddag::decomp(std::string word){
    std::vector<std::string> res;
    for (int i = 0; i < word.size(); i++){
        std::string substring1 = word.substr(0, i + 1);
        std::string substring2 = word.substr(
            i + 1, 
            word.size() - i - 1
        );
        std::reverse(substring1.begin(), substring1.end());
        res.push_back(
            substring1 + 
            "+" + 
            substring2
        );
    }

    return (res);
}

void Gaddag::insert(std::string word){
    /*while (word == ""){
        //Vérif si lettre pas déjà dans gaddag suivant
        //Si c'est le cas on fait un appel de insert sur le gaddag existant avaec le reste du mot
        //Sinon créer le gaddag et faire un insert sur le gaddag avec le reste du mot
        //insert(word.substr( 1, word.size() ))
    }
    insert("reste du mot");*/

    if (word != "") {
        bool is_letter_in_gaddag = false;
        int i;

        if (next_gaddags.size() == 0) {
            Gaddag new_gaddag();
            std::tuple<Gaddag, char> new_tuple(new_gaddag, word[0]);
            next_gaddags.push_back(new_tuple);
            std::string sub_word = word.substr(1, word.size() - 1);
            new_gaddag.insert(sub_word);
        } else {
            // Verifier si la lettre existe dans un des sous-gaddags
            

            // Sinon

        }
        
        // Sinon push_back nouveau tuple 
    } else {
        is_final = true;
    }
}