/*
function renvoie une liste de mots à partir d'un inventaire (inventaire)
function qui renvoie la liste de mots à partir du tableau #(case de départ,
direction, inventaire) -> tester sur toute les lettre poisitionner
function(case de la new case, direction bis,inventaire vide) function qui fait
appel à la fonction du dessus pour chaque case non vide

parcours gauche ou haut avant + on essaie de placer les lettres
parcours droite ou bas après + on teste de placer les lettre du joueur
*/
#include "../headers/game.hpp"

/*

coup(Board currentBoard, Spot currentLocation, Direction currentDirection,
Player player,gaddag, struct save){ if (Board(currentLocation) == 0//la case ne
contient pas de lettre){ if((0 <= l || l >= 14) && (0<= c || c >= 14)){ for(int
i = 0; i < player.inv.size(); i++){ verifier si gaddag[lettreJouer] existe{

                    if (gaddag est terminal puis case suivante vide){
                        save état courant
                    }
                    coup(Boardmodif, currentLocation + direction,
currentDirection, player.inv - lettre jouer,gaddag, save);
                }
            }
            if (Gaddag["+"] existe est case suivante vide){
                coup (currentBoard, save.location, !direction, player, save);
            }
        }
    }
    else {

        coup(currentBoard, currentLocation + direction, currentDirection,
player, gaddag, save);
    }

}

}*/

void Game::getPossibleNextStates(Position position) {
  std::stack<State> states;
  currentState.currentPosition = position;
  states.push(currentState);
  State analyzedState;

  while (!states.empty()) {
    analyzedState = states.top();
    states.pop();
    // Si bord haut ou gauche
    if (analyzedState.currentPosition.column == 0 ||
        analyzedState.currentPosition.line == 0) {
      if (analyzedState.currentGaddag->checkIfFinal()) {
        nextPossibleStates.push(analyzedState);
      }

      if (analyzedState.currentGaddag->getGaddagByLetter("+") != nullptr) {
        State newState();
        states.push(newState);
      }
    }
    // Si bord bas ou droite
    else if (analyzedState.currentPosition.column == 14 ||
             analyzedState.currentPosition.line == 14) {
      if (analyzedState.currentGaddag->checkIfFinal()) {
        nextPossibleStates.push(analyzedState);
      }
    } else {
      char letter = analyzedState
                        .board(analyzedState.currentPosition.line,
                               analyzedState.currentPosition.column)
                        .letter;
      // Si case vide
      if (letter == 0) {
        // Si aucune arête et noeud terminal
        if (analyzedState.currentGaddag->checkIfFinal() &&
            analyzedState.currentGaddag.checkIfGaddagsEmpty()) {
          nextPossibleStates.push(analyzedState);
          continue;
        }

        // Si noeud terminal
        if (analyzedState.currentGaddag->checkIfFinal()) {
          nextPossibleStates.push(analyzedState);
        }

        // On empile les états possibles
        // Pour chaque lettre du joueur
        // On vérifie si l'arête existe et on empile si c'est le cas
        for (const Letter& tile : analyzedState.player.getInventory()) {
          if (analyzedState.currentGaddag->getGaddagByLetter(tile.letter) !=
              nullptr) {
            State newState();
            states.push(newState);
          }
        }

        // Si on a une arête +
        if (analyzedState.currentGaddag->getGaddagByLetter("+") != nullptr) {
          // On retourne à la position initiale et on empile le nouvel etat
          // On pense bien à changer de sens
          State newState();
          states.push(newState);
        }
      } else {
        if (analyzedState.currentGaddag->getGaddagByLetter(letter) != nullptr) {
          State newState();
          states.push(newState);
        }
      }
    }
  }
}
/*
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

int scoreAll(Board, Position, direction){
    int score = 0;
    int coefword = 1;
    while (Board(point - direction) =! vide){ // TOP et LEFT
        res += scoreLettre * coefLettre;
        coefword *= coefLettre;
        if (Board(point + direction + 1 % 4) != vide || Board(point + direction
+ 3 % 4) != vide){ res += calculSubWord(Board,Direction, Position);
        }
    }
    while (Board(point + direction + 2 % 4) != vide){// BOTOM et RIHGT
            res += scoreLettre * coefLettre;
            coefword *= coefLettre;
            if (Board(point + direction + 1 % 4) != vide || Board(point +
direction + 3 % 4) != vide){ res += calculSubWord(Board,Direction, Position);
        }
    }
}

int calculSubWord(Board, Position, direction){
    int score = 0;
    int coefword = 1;
    while (Board(point - direction) =! vide){ // TOP et LEFT
        res += scoreLettre * coefLettre;
        coefword *= coefMot;
    }
    while (Board(point + direction + 2 % 4) != vide){// BOTOM et RIHGT
        res += scoreLettre * coefLettre;
        coefwword *= coefMot;
    }
    return (score * coefword);
}
*/

std::string Game::buildMot(Board board, Direction direction, Position pos) {
  Position postemp = pos;
  string res = "";
  while (board(pos.line, pos.column).letter != 0) {
    res = Board(pos.line, pos.column).letter + res;
    pos = pos.getNextPosition(direction);
  }
  pos = postemp;
  while (board(pos.line, pos.column).letter != 0) {
    res = res + Board(pos.line, pos.column).letter;
    pos = pos.getNextPosition((direction + 2) % 4);
  }
  return res;
}

bool Game::isPossible(Board board, direction direction, Position pos,
                      Gaddag gadd) {
  return (gadd.checkIfWordInGaddag(buildMot(board, (direction + 1) % 4, pos)) &&
          gadd.checkSubWord(buildMot(board, direction, pos)));
}

int Game::calculSubWord(Board board, Direction direction, Position pos) {
  Position postemp = pos;
  int res = 0;
  int score = 0;
  int coefword = 1;
  while (board(pos.line, pos.column).letter != 0) {
    score += board(pos.line, pos.column).letter.points *
             board(pos.line, pos.column).bonus.letter_factor;
    coefword *= board(pos.line, pos.column).bonus.word_factor;
    pos = pos.getNextPosition(direction);
  }
  pos = postemp;
  while (board(pos.line, pos.column).letter != 0) {
    score += board(pos.line, pos.column).letter.points *
             board(pos.line, pos.column).bonus.letter_factor;
    coefword *= board(pos.line, pos.column).bonus.word_factor;
    pos = pos.getNextPosition((direction + 2) % 4);
  }
  return (score * coefword);
}

int Game::scoreAll(Board board, Direction direction, Position pos) {
  Position postemp = pos;
  int res = 0;
  int score = 0;
  int scorethis = 0;
  int coefword = 1;
  while (board(pos.line, pos.column).letter != 0) {
    scorethis += board(pos.line, pos.column).letter.points *
                 board(pos.line, pos.column).bonus.letter_factor;
    coefword *= board(pos.line, pos.column).bonus.word_factor;
    Position postemp1 = pos.getNextPosition((direction + 1) % 4);
    Position postemp2 = pos.getNextPosition((direction + 3) % 4);
    if (board(postemp1.line, postemp1.column).letter != 0 ||
        board(postemp2.line, postemp2.column).letter != 0) {
      res += calculSubWord(board, (direction + 1) % 4, pos);
    }
    pos = pos.getNextPosition(direction);
  }
  pos = postemp;
  while (board(pos.line, pos.column).letter != 0) {
    scorethis += board(pos.line, pos.column).letter.points *
                 board(pos.line, pos.column).bonus.letter_factor;
    coefword *= board(pos.line, pos.column).bonus.word_factor;
    Position postemp1 = pos.getNextPosition((direction + 1) % 4);
    Position postemp2 = pos.getNextPosition((direction + 3) % 4);
    if (board(postemp1.line, postemp1.column).letter != 0 ||
        board(postemp2.line, postemp2.column).letter != 0) {
      res += calculSubWord(board, (direction + 1) % 4, pos);
    }
    pos = pos.getNextPosition((direction + 2) % 4);
    return (scorethis * coefword + res);
  }
}