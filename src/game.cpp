#include "game.hpp"

void Game::clearNextStates() {
  std::queue<State> emptyQueue;
  std::swap(nextPossibleStates, emptyQueue);
}

void Game::getPossibleNextStates(Position position, Direction direction) {
  Gaddag* root = currentState.currentGaddag;
  std::cout << "Racine : " << std::endl;
  root->getGaddagByLetter('W')->showKeys();

  clearNextStates();
  std::stack<State> states;
  currentState.currentPosition = position;
  currentState.isPlusHasBeenFound = false;

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
        nextPossibleStates.push(analyzedState);
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
        nextPossibleStates.push(analyzedState);
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
          nextPossibleStates.push(analyzedState);
          continue;
        }

        if (analyzedState.currentGaddag->checkIfFinal()) {
          nextPossibleStates.push(analyzedState);
        }

        Position newPosition = analyzedState.currentPosition.findNextPosition(
            direction, analyzedState.isPlusHasBeenFound);

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

            std::cout << "Avant condition : " << std::endl;
            root->showKeys();

            if (isPossible(newState.board, direction, newState.currentPosition,
                           root)) {
              states.push(newState);
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
          nextPossibleStates.push(analyzedState);
        }
      }
    }
  }
}

void Game::getAllPossibleNextStates() {}

void Game::showPossibleNextStates() {
  std::queue<State> temp = nextPossibleStates;

  while (!temp.empty()) {
    std::cout << temp.front().board << std::endl;
    temp.pop();
  }
}

// Calcul le score des mots étant complété par un coup
int Game::calculSubWord(Board board, Direction direction, Position pos) {
  LettersCollection letterCollection;

  Position postemp = pos.findNextPosition(direction, true);

  int score = letterCollection.getPoint(board(pos.line, pos.column).letter) *
              board(pos.line, pos.column).bonus.letter_factor;

  int coefword = board(pos.line, pos.column).bonus.word_factor;

  pos = pos.findNextPosition(direction, false);

  while (pos.checkIfValid() &&
         board(pos.line, pos.column).letter !=
             0) {  // parcours vers la gauche tant que lettre non vide

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
  int scorethis = 0;
  int coefword = 1;

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
  std::string word = buildMot(board, (Direction)((direction + 1) % 2), pos);
  bool condition1 = gadd->checkIfWordInGaddag(word);
  std::cout << "Mot : " << word << std::endl;
  std::cout << "condition : " << condition1 << std::endl;
  return condition1;
}