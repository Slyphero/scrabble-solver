#include "gaddag.hpp"

Gaddag::Gaddag() 
{
    isFinal = false;
}

vector<string> Gaddag::decompose(const string& word) 
{
    vector<string> decompositions;
    for (int i = 0; i < word.size(); i++)
    {
        string substring1 = word.substr(0, i + 1);
        string substring2 = word.substr(i + 1, word.size() - i - 1);
        reverse(substring1.begin(), substring1.end());
        decompositions.push_back(substring1 + "+" + substring2);
    }

    return (decompositions);
}

void Gaddag::insertDecomposition(const string& decomposition) 
{
    
}

void Gaddag::insertWord(const string& word)
{
    for (string str : decompose(word))
    {
        insert(str);
    }
}

void Gaddag::checkIfInGaddag(const string& word)
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