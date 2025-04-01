/*
function renvoie une liste de mots à partir d'un inventaire (inventaire)
function qui renvoie la liste de mots à partir du tableau #(case de départ, direction, inventaire) -> tester sur toute les lettre poisitionner function(case de la new case, direction bis,inventaire vide)
function qui fait appel à la fonction du dessus pour chaque case non vide

parcours gauche ou haut avant + on essaie de placer les lettres
parcours droite ou bas après + on teste de placer les lettre du joueur
*/

/*


coup(Board currentBoard, Spot currentLocation, Direction currentDirection, Player player,gaddag, struct save){
    if (Board(currentLocation) == 0//la case ne contient pas de lettre){
        if((0 <= l || l >= 14) && (0<= c || c >= 14)){
            for(int i = 0; i < player.inv.size(); i++){
                verifier si gaddag[lettreJouer] existe{
                    joue lettre
                    if (gaddag est terminal puis case suivante vide){
                        save état courant
                    }
                    coup(Boardmodif, currentLocation + direction, currentDirection, player.inv - lettre jouer,gaddag, save);
                }
            }
            if (Gaddag["+"] existe est case suivante vide){
                coup (currentBoard, save.location, !direction, player, save);
            }
        }  
    }
    else {

        coup(currentBoard, currentLocation + direction, currentDirection, player, gaddag, save);
    }
    
}

autrefonction(){
    parcours le tab de (8,8) en allant sur les voisin non vide{
        coup(Board,spotActuelle,LEFT, joueur,gaddag, save);
        coup(Board,spotActuelle,TOP, joueur,gaddag,  save);
    }
}

bool is_possible(Board, direction, point, Gaddag){
    // autre_direction = direction + 1 % 4
    return (
        Gadda.checkIfWordInGaddag(buildMot(Board,autre_direction,point)) && 
        Gaddag.Checkdecomp(buildMot(Board, direction, point))
    );
}


string buildMot(Board, direction, point){
    string res = ""; 
    while (Board(point - direction) =! vide){ // TOP et LEFT
        res = lettre_actuelle + res;
    }
    while (Board(point + direction + 2 % 4) != vide){// BOTOM et RIHGT
            res = res + lettre_actuelle;
    }
    return res;
}
*/

#include "game.hpp"