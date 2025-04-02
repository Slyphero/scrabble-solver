# Pseudos codes

## Verifier les coups possibles : ébauche de code

```cpp
coup(Board currentBoard, Spot currentLocation, Direction currentDirection, Player player,gaddag, struct save){
  if (Board(currentLocation) == 0 {
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
  } else {
    coup(currentBoard, currentLocation + direction, currentDirection, player, gaddag, save);
  }
}
```
