#include "gaddag.hpp"

Gaddag::Gaddag(){
    final = false;
}

std::vector<std::string> Gaddag::decomp(std::string word){
    std::vector<std::string> res;
    for (int i = 1; i < word.size(); i++){
        std::string substring1 = word.substr(0, i);
        std::string substring2 = word.substr(i+1, word.size() - 1);
        res.push_back(std::reverse(substring1.begin(), substring1.end()) + '+' + substring2);
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
    pass;
}