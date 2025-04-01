/*
function renvoie une liste de mots à partir d'un inventaire (inventaire)
function qui renvoie la liste de mots à partir du tableau #(case de départ, direction, inventaire) -> tester sur toute les lettre poisitionner function(case de la new case, direction bis,inventaire vide)
function qui fait appel à la fonction du dessus pour chaque case non vide

parcours gauche ou haut avant + on essaie de placer les lettres
parcours droite ou bas après + on teste de placer les lettre du joueur
*/

/*
coup(Board currentBoard, Spot currentLocation, Direction currentDirection, Player player, struct save){
    if (Board(currentLocation) == 0){
        while((0 <= l || l >= 14) && (0<= c || c >= 14)){
            for(int i = 0; i < player.inv.size(); i++){
                verifier si gaddag[lettreJouer] existe{
                    save.letter += score lettre * coef case
                    save.multiple *= multiple mot
                    if (gaddag est terminal){
                        save état courant
                        save.score *= save.multiple;
                    }
                    coup(Boardmodif, currentLocation + direction, currentDirection, player.inv - lettre jouer, save);
                }
            }
        }  
    }
    else {
        save.letter += score lettre * coef case
        save.multiple *= multiple mot
        coup(currentBoard, currentLocation + direction, currentDirection, player, save);
    }
    if (Gaddag["+"] existe){
        coup (currentBoard, save.location, !direction, player, save);
    }
}

autrefonction(){
    parcours le tab de (8,8) en allant sur les voisin non vide{
        coup(Board,spotActuelle,LEFT, joueur, save);
        coup(Board,spotActuelle,TOP, joueur, save);
    }
}
*/

#include "game.hpp"