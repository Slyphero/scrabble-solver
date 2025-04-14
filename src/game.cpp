#include "game.hpp"

std::pair<State, int> Game::getBestPlayFromPosition(Position position,
                                                    Direction direction) {
  Gaddag* root = currentState.currentGaddag;
  std::stack<State> states;
  currentState.currentPosition = position;
  currentState.isPlusHasBeenFound = false;

  std::pair<State, int> bestPlay = std::make_pair(currentState, 0);

  State analyzedState(currentState.player, currentState.currentGaddag,
                      currentState.board, currentState.currentPosition,
                      currentState.isPlusHasBeenFound);

  states.push(analyzedState);

  analyzedState.player.printInventory();

  while (!states.empty()) {
    analyzedState = states.top();
    states.pop();

    if (analyzedState.currentPosition.checkIfTopOrLeft()) {
      if (analyzedState.currentGaddag->checkIfFinal()) {
        int score = scoreAll(analyzedState.board, direction, position);
        if (bestPlay.second < score) {
          bestPlay = std::make_pair(analyzedState, score);
        }
      }

      if (analyzedState.currentGaddag->getGaddagByLetter('+') != nullptr) {
        Position newPosition = position.findNextPosition(direction, true);

        State newState(analyzedState.player,
                       analyzedState.currentGaddag->getGaddagByLetter('+'),
                       analyzedState.board, newPosition, true);
        states.push(newState);
      }
    }

    else if (analyzedState.currentPosition.checkIfBottomOrRight()) {
      if (analyzedState.currentGaddag->checkIfFinal()) {
        int score = scoreAll(analyzedState.board, direction, position);
        if (bestPlay.second < score) {
          bestPlay = std::make_pair(analyzedState, score);
        }
      }
    }

    else {
      char letter = analyzedState
                        .board(analyzedState.currentPosition.line,
                               analyzedState.currentPosition.column)
                        .letter;
      if (letter == 0) {
        if (analyzedState.currentGaddag->checkIfFinal() &&
            analyzedState.currentGaddag->checkIfGaddagsEmpty()) {
          int score = scoreAll(analyzedState.board, direction, position);
          if (bestPlay.second < score) {
            bestPlay = std::make_pair(analyzedState, score);
          }
          continue;
        }
        Position newPosition = analyzedState.currentPosition.findNextPosition(
            direction, analyzedState.isPlusHasBeenFound);

        if (analyzedState.currentGaddag->checkIfFinal()) {
          int score = scoreAll(analyzedState.board, direction, position);
          if (bestPlay.second < score) {
            bestPlay = std::make_pair(analyzedState, score);
          }
        }

        for (const Letter& tile : analyzedState.player.getInventory()) {
          if (analyzedState.currentGaddag->getGaddagByLetter(
                  tile.getLetter()) != nullptr) {
            Player player = analyzedState.player;
            player.removeLetter(tile);

            Board board;
            board = analyzedState.board;
            board(analyzedState.currentPosition.line,
                  analyzedState.currentPosition.column)
                .letter = tile.getLetter();

            State newState(player,
                           analyzedState.currentGaddag->getGaddagByLetter(
                               tile.getLetter()),
                           board, newPosition,
                           analyzedState.isPlusHasBeenFound);

            /*
            3 cas sont à prendre en compte :
            - Si la case suivante est vide (et que le noeud est terminal),
              pas de collisions rien à faire
            - Si la case suivante est non vide mais que sa lettre n'a pas
              d'arête dans le gaddag, ce n'est pas un état possible
            - Si la case suivante est non vide et que l'arête existe, il faut
              poursuivre les vérifications tant qu'on arrive pas sur un
              des cas précédents.
            */
            if (isPossible(newState.board, direction,
                           analyzedState.currentPosition, root)) {
              if (newState
                      .board(newState.currentPosition.line,
                             newState.currentPosition.column)
                      .letter == 0) {
                states.push(newState);
              } else if (checkValidCollision(newState.board,
                                             newState.currentGaddag, direction,
                                             newState.isPlusHasBeenFound,
                                             analyzedState.currentPosition)) {
                states.push(newState);
              }
            }
          }
        }

        if (analyzedState.currentGaddag->getGaddagByLetter('+') != nullptr) {
          newPosition = position.findNextPosition(direction, true);
          State newState(analyzedState.player,
                         analyzedState.currentGaddag->getGaddagByLetter('+'),
                         analyzedState.board, newPosition, true);
          states.push(newState);
        }
      }

      else {
        Position newPosition = analyzedState.currentPosition.findNextPosition(
            direction, analyzedState.isPlusHasBeenFound);

        if (analyzedState.currentGaddag->getGaddagByLetter(letter) != nullptr) {
          State newState(analyzedState.player,
                         analyzedState.currentGaddag->getGaddagByLetter(letter),
                         analyzedState.board, newPosition,
                         analyzedState.isPlusHasBeenFound);
          states.push(newState);
        }
        State newState(analyzedState.player, analyzedState.currentGaddag,
                       analyzedState.board, newPosition,
                       analyzedState.isPlusHasBeenFound);

        if (newState.board(newState.currentPosition.line,
                           newState.currentPosition.column)
                    .letter == 0 &&
            analyzedState.currentGaddag->checkIfFinal()) {
          int score = scoreAll(analyzedState.board, direction, position);
          if (bestPlay.second < score) {
            bestPlay = std::make_pair(analyzedState, score);
          }
        }
      }
    }
  }
  return bestPlay;
}

// Calcul le score des mots étant complété par un coup
int Game::calculSubWord(Board board, Direction direction, Position pos) {
  LettersCollection letterCollection;

  Position postemp = pos.findNextPosition(direction, true);

  int score = letterCollection.getPoint(board(pos.line, pos.column).letter) *
              board(pos.line, pos.column).bonus.letter_factor;

  int coefword = board(pos.line, pos.column).bonus.word_factor;

  pos = pos.findNextPosition(direction, false);

  while (pos.checkIfValid() && board(pos.line, pos.column).letter != 0) {
    // parcours vers la gauche tant que lettre non vide

    score += letterCollection.getPoint(board(pos.line, pos.column).letter);

    pos = pos.findNextPosition(direction, false);
  }

  pos = postemp;

  while (pos.checkIfValid() &&
         board(pos.line, pos.column).letter !=
             0) {  // parcours dans l'autre sens pour calculer score

    score += letterCollection.getPoint(board(pos.line, pos.column).letter);

    pos = pos.findNextPosition(direction, true);
  }

  return (score * coefword);
}

// Permet de calculer le nombre de points totaux ajouter par un coup
int Game::scoreAll(Board board, Direction direction, Position pos) {
  LettersCollection letterCollection;
  Position postemp = pos.findNextPosition(direction, true);
  int res = 0;

  int scorethis =
      letterCollection.getPoint(board(pos.line, pos.column).letter) *
      board(pos.line, pos.column).bonus.letter_factor;

  int coefword = board(pos.line, pos.column).bonus.word_factor;

  pos = pos.findNextPosition(direction, false);
  while (pos.checkIfValid() && board(pos.line, pos.column).letter != 0) {
    scorethis += letterCollection.getPoint(board(pos.line, pos.column).letter) *
                 board(pos.line, pos.column).bonus.letter_factor;

    coefword *= board(pos.line, pos.column).bonus.word_factor;

    Position postemp1 =
        pos.findNextPosition((Direction)((direction + 1) % 2), false);

    Position postemp2 =
        pos.findNextPosition((Direction)((direction + 1) % 2), true);

    if (board(postemp1.line, postemp1.column).letter != 0 ||
        board(postemp2.line, postemp2.column).letter != 0) {
      res += calculSubWord(board, (Direction)((direction + 1) % 2), pos);
    }

    pos = pos.findNextPosition(direction, false);
  }

  pos = postemp;
  while (pos.checkIfValid() && board(pos.line, pos.column).letter != 0) {
    scorethis += letterCollection.getPoint(board(pos.line, pos.column).letter) *
                 board(pos.line, pos.column).bonus.letter_factor;

    coefword *= board(pos.line, pos.column).bonus.word_factor;
    // vérif les deux case adjacente avec la direction opposée

    Position postemp1 =
        pos.findNextPosition((Direction)((direction + 1) % 2), false);

    Position postemp2 =
        pos.findNextPosition((Direction)((direction + 1) % 2), true);

    if (board(postemp1.line, postemp1.column).letter != 0 ||
        board(postemp2.line, postemp2.column).letter != 0) {
      res += calculSubWord(board, (Direction)((direction + 1) % 2), pos);
    }

    pos = pos.findNextPosition(direction, true);
  }

  return (scorethis * coefword + res);
}

// Construction de la chaine de charactère associé à un placement de lettre
std::string Game::buildMot(Board board, Direction direction, Position pos) {
  Position postemp = pos.findNextPosition(direction, true);
  std::string res = "";
  // construction dans le sens inverse (avant le +)
  while (pos.checkIfValid() && board(pos.line, pos.column).letter != 0) {
    res = board(pos.line, pos.column).letter + res;
    pos = pos.findNextPosition(direction, false);
  }
  pos = postemp;
  // construction dans le bon sens (après le +)
  while (pos.checkIfValid() && board(pos.line, pos.column).letter != 0) {
    res = res + board(pos.line, pos.column).letter;
    pos = pos.findNextPosition(direction, true);
  }

  return res;
}

// on vérifie si le mot créer est terminal dans la deuxième direction, tandis
// qu'on cherche à vérifier que le mot dans la direction existe dans le gaddag
bool Game::isPossible(Board board, Direction direction, Position pos,
                      Gaddag* gadd) {
  Direction oppositeDirection = (Direction)((direction + 1) % 2);
  std::string word = buildMot(board, oppositeDirection, pos);
  bool condition1 = gadd->checkIfWordInGaddag(word);

  Position previous = pos.findNextPosition(oppositeDirection, false);
  Position next = pos.findNextPosition(oppositeDirection, true);

  bool areNextTilesEmpty = previous.checkIfValid() && next.checkIfValid() &&
                           board(previous.line, previous.column).letter == 0 &&
                           board(next.line, next.column).letter == 0;

  bool isNextTileEmpty = !previous.checkIfValid() && next.checkIfValid() &&
                         board(next.line, next.column).letter == 0;

  bool isPreviousTileEmpty = previous.checkIfValid() && !next.checkIfValid() &&
                             board(previous.line, previous.column).letter == 0;

  bool condition2 = areNextTilesEmpty || isNextTileEmpty || isPreviousTileEmpty;

  return condition1 || condition2;
}

std::pair<State, int> Game::getBestPlayOnEmptyBoard() {
  std::pair<State, int> bestPlay = std::make_pair(currentState, 0);

  Position center(7, 7);
  Direction directions[2] = {Direction::HORIZONTAL, Direction::VERTICAL};

  currentState.player.printInventory();

  for (Direction direction : directions) {
    std::stack<State> states;

    State startState(currentState.player, currentState.currentGaddag,
                     currentState.board, center, false);
    states.push(startState);

    while (!states.empty()) {
      State state = states.top();
      states.pop();

      char cellLetter =
          state.board(state.currentPosition.line, state.currentPosition.column)
              .letter;

      if (cellLetter == 0) {
        for (const Letter& tile : state.player.getInventory()) {
          Gaddag* nextGaddag =
              state.currentGaddag->getGaddagByLetter(tile.getLetter());

          if (nextGaddag != nullptr) {
            Player nextPlayer = state.player;
            nextPlayer.removeLetter(tile);

            Board nextBoard = state.board;
            nextBoard(state.currentPosition.line, state.currentPosition.column)
                .letter = tile.getLetter();

            Position nextPosition = state.currentPosition.findNextPosition(
                direction, state.isPlusHasBeenFound);

            State nextState(nextPlayer, nextGaddag, nextBoard, nextPosition,
                            state.isPlusHasBeenFound);

            if (nextGaddag->checkIfFinal()) {
              if (nextBoard(center.line, center.column).letter != 0) {
                int score = scoreAll(nextBoard, direction, center);
                if (score > bestPlay.second) {
                  bestPlay = std::make_pair(nextState, score);
                }
              }
            }

            states.push(nextState);
          }
        }

        if (state.currentGaddag->getGaddagByLetter('+') != nullptr &&
            !state.isPlusHasBeenFound) {
          Position nextPosition = center.findNextPosition(direction, true);

          State nextState(state.player,
                          state.currentGaddag->getGaddagByLetter('+'),
                          state.board, nextPosition, true);
          states.push(nextState);
        }
      }
    }
  }

  return bestPlay;
}

bool Game::checkValidCollision(const Board& board, Gaddag* gaddag,
                               Direction direction, bool isPlusHasBeenFound,
                               Position position) {
  Position nextPosition =
      position.findNextPosition(direction, isPlusHasBeenFound);

  char nextLetter = board(nextPosition.line, nextPosition.column).letter;

  while (nextPosition.checkIfValid() && nextLetter != 0) {
    if (gaddag->getGaddagByLetter(nextLetter) == nullptr) return false;

    gaddag = gaddag->getGaddagByLetter(nextLetter);
    nextPosition = nextPosition.findNextPosition(direction, isPlusHasBeenFound);
    nextLetter = board(nextPosition.line, nextPosition.column).letter;
  }

  return gaddag->checkIfFinal();
}

std::pair<State, int> Game::getMaxScore(std::pair<State, int> pair1,
                                        std::pair<State, int> pair2) {
  if (pair1.second > pair2.second) return pair1;
  return pair2;
}

std::pair<State, int> Game::getBestOverallPlay() {
  std::pair<State, int> bestPair = std::make_pair(currentState, 0);
  for (int line = 0; line < 15; line++) {
    for (int column = 0; column < 15; column++) {
      Position position(line, column);
      if (currentState.board(line, column).letter != 0) {
        std::pair<State, int> pair1 =
            getBestPlayFromPosition(position, HORIZONTAL);

        std::cout << "Pair 1 : " << std::endl;
        std::cout << pair1.first.board << std::endl;

        std::pair<State, int> pair2 =
            getBestPlayFromPosition(position, VERTICAL);

        std::cout << "Pair 2 : " << std::endl;
        std::cout << pair2.first.board << std::endl;

        std::pair<State, int> currentBestPair = getMaxScore(pair1, pair2);

        std::cout << "Meilleur coup entre HORIZONTAL et VERTICAL : "
                  << currentBestPair.second << std::endl;

        if (currentBestPair.second > bestPair.second) {
          bestPair = currentBestPair;
          std::cout << "New best score : " << bestPair.second << std::endl;
        }
      }
    }
  }
  return bestPair;
}