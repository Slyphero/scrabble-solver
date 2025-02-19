#include "gaddag.hpp"

Gaddag::Gaddag() 
{
    bIsFinal = false;
}

vector<string> Gaddag::decomp(string word) 
{
    vector<string> res;
    for (int i = 0; i < word.size(); i++)
    {
        string substring1 = word.substr(0, i + 1);
        string substring2 = word.substr(
            i + 1, 
            word.size() - i - 1
        );
        reverse(substring1.begin(), substring1.end());
        res.push_back(
            substring1 + 
            "+" + 
            substring2
        );
    }

    return (res);
}

tuple<bool, unsigned int> isLetterInSubGaddag(char letter) 
{
    for (int i = 0; i < nextSubGaddag.size(); i++) 
    {
        if (get<1>(nextSubGaddag.at(i)) == letter) 
        {
            return new_tuple(true, i);
        }
    }
    return new_tuple(false, 0);
}

void Gaddag::addGaddag(const Gaddag& newGaddag, char letter) 
{
    tuple<Gaddag, char> new_tuple = make_tuple(newGaddag, letter);
    nextGaddags.push_back(new_tuple);
}

void Gaddag::insert(string word)
{
    /*while (word == ""){
        //Vérif si lettre pas déjà dans gaddag suivant
        //Si c'est le cas on fait un appel de insert sur le gaddag existant avaec le reste du mot
        //Sinon créer le gaddag et faire un insert sur le gaddag avec le reste du mot
        //insert(word.substr( 1, word.size() ))
    }
    insert("reste du mot");*/

    if (word == "") 
    {
        bIsFinal = true;
        return;
    }

    string subword = word.substr(1, word.size() - 1);
    Gaddag newGaddag;

    if (nextGaddags.size() == 0) 
    {
        newGaddag.insert(subword);
        addGaddag(newGaddag, word[0]);
        return;
    }

    tuple<bool, unsigned int> bIsLetterInSubGaddagAndIndex = isLetterInSubGaddag(word[0]);
    
    if (get<0>(bIsLetterInSubGaddagAndIndex)) 
    {
        nextGaddags.at(get<1>(bIsLetterInSubGaddagAndIndex)).insert(subword);
        return;
    } 
    
    newGaddag.insert(subword);
    addGaddag(newGaddag, word[0]);
}

void Gaddag::insertWord(string word)
{
    for (string str : decomp(word))
    {
        insert(str);
    }
}

void Gaddag::research(string word)
{
    //si le mot est vide on renvoie le bIsFinal car si il n'est pas final on renvoie false sinon si le mot est fini et final on renvoie true
    if (word.empty())
    {   
        return (bIsFinal);
    }

    //parcours les gaddags enfant
    for (int i = 0; i < nextGaddags.size(); i++)
    {
        //si la lettre est trouvé alors on fait un appel rec sur le gaddag enfant avec le reste du mot
        if (word[0] == get<1>(nextGaddags[i]))
        {
            string subword = word.substr(1, word.size() - 1);
            nextGaddags[i].research(subword);
        }
    }
    return (false);
}

Gaddag Gaddag::operator=(const Gaddag& gaddag) 
{
    bIsFinal = gaddag.bIsFinal;
    nextGaddags.clear();

    for (tuple<Gaddag, char> nextGaddag : gaddag.nextGaddags) 
    {
        nextGaddags.push_back(nextGaddag);
    }
}

void Gaddag::print()
{
    if (nextGaddags.empty())
    {
        cout << endl;
    }

    for (int i = 0; i < nextGaddags.size(); i++)
    {
        cout << get<1>(nextGaddags[i]) << "  ";
        nextGaddags[i].print();
    }
}