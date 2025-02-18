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

std::tuple<bool, unsigned int> is_letter_in_subgaddag(char letter) {
    for (int i = 0; i < next_subgaddag.size(); i++) {
        if (std::get<1>(next_subgaddag.at(i)) == letter) {
            return new_tuple(true, i);
        }
    }
    return new_tuple(false, 0);
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
        // On cree une nouvelle branche si le gaddag n'a que la racine
        if (next_gaddags.size() == 0) {
            Gaddag new_gaddag();
            std::tuple<Gaddag, char> new_tuple(new_gaddag, word[0]);
            next_gaddags.push_back(new_tuple);
            std::string sub_word = word.substr(1, word.size() - 1);
            new_gaddag.insert(sub_word);
        } else {
            // Verifier si la lettre existe dans un des sous-gaddags
            std::tuple<bool, unsigned int> is_letter_in_sub_gaddag_and_index = is_letter_in_subgaddag(word[0]);
            if (std::get<0>(is_letter_in_sub_gaddag_and_index)) {
                std::string sub_word = word.substr(1, word.size() - 1);
                next_gaddag.at(std::get<1>(is_letter_in_sub_gaddag_and_index)).insert(sub_word);
            } else {
                Gaddag new_gaddag();
                std::tuple<Gaddag, char> new_tuple(new_gaddag, word[0]);
                next_gaddags.push_back(new_tuple);
                std::string sub_word = word.substr(1, word.size() - 1);
                new_gaddag.insert(sub_word);
            }
        }        
    } else {
        is_final = true;
    }
}

void Gaddag::insert_word(std::string word){
    for (std::string str : decomp(word)){
      insert(str);
    }
}

void Gaddag::research(std::string word){
    //si le mot est vide on renvoie le is_final car si il n'est pas final on renvoie false sinon si le mot est fini et final on renvoie true
    if (word.empty())
        return (is_final);
    //parcours les gaddags enfant
    for (int i = 0; i < next_gaddags.size(); i++){
        //si la lettre est trouvé alors on fait un appel rec sur le gaddag enfant avec le reste du mot
        if (word[0] == std::get<1>(next_gaddags[i])){
            std::string sub_word = word.substr(1, word.size() - 1);
            next_gaddags[i].research(sub_word);
        }
    }
    return (false);
}

Gaddag Gaddag::operator=(Gaddag gaddag) {
    is_final = gaddag.is_final;
    next_gaddags.clear();

    for (std::tuple<Gaddag, char> next_gaddag : gaddag.next_gaddags) {
        next_gaddags.push_back(next_gaddag);
    }
}

void Gaddag::print(){

    if (next_gaddags.empty())
        std::cout<<std::endl;

    for (int i = 0; i < next_gaddags.size(); i++){
        std::cout<<std::get<1>(next_gaddags[i])<<"  ";
        next_gaddags[i].print();
    }
}