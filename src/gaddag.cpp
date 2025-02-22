#include "gaddag.hpp"

#include <iostream>

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
    Gaddag* currentGaddag = this;

    for (int i = 0; i < decomposition.size(); i++) 
    {
        char currentLetter = decomposition[i];

        // Si on trouve une arête correspondant a la lettre,
        // on continue sur le gaddag suivant
        if (currentGaddag->gaddags.find(currentLetter)
            != currentGaddag->gaddags.end())
        {
            currentGaddag = currentGaddag->gaddags[currentLetter].get();
        }

        // Sinon on crée un nouveau gaddag qu'on relie par l'arête à
        // la lettre correspondante
        else
        {
            unique_ptr<Gaddag> newGaddag(new Gaddag());
            currentGaddag->gaddags[currentLetter] = move(newGaddag);
            currentGaddag = currentGaddag->gaddags[currentLetter].get();
        }
    }

    currentGaddag->isFinal = true;
}

void Gaddag::insertWord(const string& word)
{
    for (const string& decomposition : decompose(word))
    {
        insertDecomposition(decomposition);
    }
}


// bool Gaddag::checkIfInGaddag(const string& word)
// {
//     //si le mot est vide on renvoie le bIsFinal car si il n'est pas final on renvoie false sinon si le mot est fini et final on renvoie true
//     if (word.empty())
//     {   
//         return (bIsFinal);
//     }

//     //parcours les gaddags enfant
//     for (int i = 0; i < nextGaddags.size(); i++)
//     {
//         //si la lettre est trouvé alors on fait un appel rec sur le gaddag enfant avec le reste du mot
//         if (word[0] == get<1>(nextGaddags[i]))
//         {
//             string subword = word.substr(1, word.size() - 1);
//             nextGaddags[i].research(subword);
//         }
//     }
//     return (false);
// }

bool Gaddag::checkIfDecompositionInGaddag(const string& decomposition)
{
    Gaddag* currentGaddag = this;

    for (int i = 0; i < decomposition.size(); i++) 
    {
        char currentLetter = decomposition[i];

        // Si on ne trouve pas d'arête correspondant à la lettre,
        // on ne peut pas aller plus loin
        // on regarde donc si on est sur un noeud terminal
        if (!(currentGaddag->gaddags.find(currentLetter)
            != currentGaddag->gaddags.end()))
        {
            return currentGaddag->isFinal;
        }

        // Sinon on continue avec le prochain Gaddag
        currentGaddag = currentGaddag->gaddags[currentLetter].get();
    }

    return currentGaddag->isFinal;
}

bool Gaddag::checkIfWordInGaddag(const string& word)
{
    for (const string& decomposition : decompose(word))
    {
        if (!checkIfDecompositionInGaddag(decomposition)) 
        {
            return false;
        }
    }    
    return true;
}

// void Gaddag::print()
// {
//     if (nextGaddags.empty())
//     {
//         cout << endl;
//     }

//     for (int i = 0; i < nextGaddags.size(); i++)
//     {
//         cout << get<1>(nextGaddags[i]) << "  ";
//         nextGaddags[i].print();
//     }
// }

void Gaddag::print()
{
    if (gaddags.size() == 0)
    {
        cout << endl;
        return;
    }

    for (const auto& [key, value] : gaddags)
    {
        cout << endl;
        cout << key;
        if (value != nullptr)
        {
            cout << "(";
            value->print();
            cout << ")";
        }
    }
}