/*
function renvoie une liste de mots à partir d'un inventaire (inventaire)
function qui renvoie la liste de mots à partir du tableau #(case de départ, direction, inventaire) -> tester sur toute les lettre poisitionner function(case de la new case, direction bis,inventaire vide)
function qui fait appel à la fonction du dessus pour chaque case non vide

parcours gauche ou haut avant + on essaie de placer les lettres
parcours droite ou bas après + on teste de placer les lettre du joueur
*/
#include "game.hpp"
/*coup(Board currentBoard, Spot currentLocation, Direction currentDirection, Player player,gaddag, struct save){
    if (Board(currentLocation) == 0//la case ne contient pas de lettre){
        if((0 <= l || l >= 14) && (0<= c || c >= 14)){
            for(int i = 0; i < player.inv.size(); i++){
                verifier si gaddag[lettreJouer] existe{
                   
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
    
}*/

Position Position::getNextPosition(Direction direction) {
    switch (direction) {
        case TOP:
            return Position(line, column - 1);
            break;
        case RIGHT:
            return Position(line + 1, column);
            break;
        case BOTTOM:
            return Position(line, column + 1);
            break;
        default:
            return Position(line - 1, column);
            break;
    }
}

void Position::operator=(const Position& newPosition) {
    line = newPosition.line;
    column = newPosition.column;
}

void Game::getPossibleNextStates(const State& state, std::vector<State>& possibleNextStates) {
    unsigned int l = state.currentPosition.line;
    unsigned int c = state.currentPosition.column;
    unsigned int inventorySize = state.player.getInventory().size();
    Position nextPosition = state.currentPosition.getNextPosition(state.direction);
    
    if (state.board(l, c).letter == 0) {
        if (l >= 0 && l <= 14 && c >= 0 && c <= 14) {
            for (unsigned int = 0; i < inventorySize; i++) {
                Letter playerLetter = state.player.getLetter(i);
                if (
                    state.gaddag.gaddags.find(playerLetter) != 
                    state.gaddag.gaddags.end()
                ) {
                    if (
                        state.gaddag.gaddags.getGaddagByLetter(playerLetter).isFinal &&
                        state.board(nextPosition.line, nextPosition.column).letter == 0
                    ) {
                        possibleNextStates.push_back(state);
                    }
                    /*
                    Appel récursif avec les paramètres
                    - player après retrait de la lettre jouée
                    - gaddag de la lettre jouée 
                    - board après ajout de la lettre
                    - nextPosition
                    - direction
                    - initialPosition
                    */
                }
            }
            if (
                state.gaddag.gaddags.find("+") != state.gaddag.gaddags.end() && 
                state.board(nextPosition.line, nextPosition.column).letter == 0
            ) {
                State newState(
                    state.player, 
                    state.gaddag.gaddags.getGaddagByLetter("+"), 
                    state.board, 
                    state.initialPosition, 
                    (state.direction + 2) % 4, 
                    state.initialPosition
                );
                getPossibleNextStates(newState, possibleNextStates);
            }
        }
    } else {
        State newState(
            state.player,
            state.gaddag.gaddags.getGaddagByLetter(
                state.board(
                    state.currentPosition.line, 
                    state.currentPosition.column
                ).letter
            ),
            state.board,
            nextPosition,
            state.direction,
            state.initialPosition
        );
        getPossibleNextStates(newState, possibleNextStates);
    }
} 

/*
autrefonction(){
    parcours le tab de (8,8) en allant sur les voisin non vide{
        coup(Board,spotActuelle,LEFT, joueur,gaddag, save);
        coup(Board,spotActuelle,TOP, joueur,gaddag,  save);
    }
}
*/


