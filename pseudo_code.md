# Pseudos codes

## Verifier les coups possibles : ébauche de code 1ère version

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

# Vérification des coups possibles : 2e ébauche

Dans un état, on a besoin de l'inventaire du joueur, du plateau (avec les lettres déjà placées) ainsi que l'avancement dans le gaddag (le noeud courant)

Pseudo code itératif pour lister les coups possibles à partir d'une case, dans le code final, il faudra bien distinguer exploration verticale et horizontale, dans ce pseudo code, je ne vais pas préciser car c'est la même chose sur le principe.

Il faut aussi ajouter la prise en compte du bord
Si jamais on arrive sur le bord haut ou gauche : il faut vérifier que le noeud soit terminal ou bien qu'un + existe

Si jamais on arrive sur le bord bas ou droite, le noeud doit être terminal

Le pseudo code n'est pas complet, il donne les grandes idées.  
On considère que la position de départ est valide

Certains cas d'erreur ne sont pas encore pris en compte par cet algorithme  
Un mot pourrait être juste dans une direction, mais créer des mots invalides dans une autre.

C'est pour cette raison que j'ai choisi de stocker le résultat dans une file, pour pouvoir défiler les états qui ne sont pas valides après d'autres vérfications (par exemple, les cas d'erreurs cités précédemment).

```
file etats_possibles : etats_possibles_de_position(Position depart)
    ajouter etat_courant a la pile_etats

    Tant que pile_etats non vide :
        On dépile le l'état au sommet

        Si le noeud courant est terminal :
            On enfile l'état courant à la file de résultats

        Si case courante vide :
            empiler un nouvel etat pour chaque lettre jouable
            Si arête + :
                On ajoute un nouvel etat partant
                de la position initiale
                et on change le sens de parcours
        Sinon :
            Si l'arête existe :
                on empile le nouvel etat
            Sinon :
                On dépile l'état sans rien en faire

    Retourner etats_possibles
```
