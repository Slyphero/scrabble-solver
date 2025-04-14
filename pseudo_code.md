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

Dans un état, on a besoin de l'inventaire du joueur, du plateau (avec les lettres déjà placées), la position courante, ainsi que l'avancement dans le gaddag (le noeud courant)

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
On empile l'état initial.
Tant que pile d'états à étudier n'est pas vide :
  On dépile le sommet puis on l'étudie.

  Si bord haut ou gauche :
    Si noeud terminal :
      Enfiler etat.

    Si + existe :
      Empiler nouvel etat.

  Si bord bas ou droite :
    Si noeud terminal :
      Enfiler etat.

  Si case vide :
    Si aucune arête et noeud terminal:
      Enfiler état.

    Si noeud terminal (et qu'il y a des arêtes):
      Enfiler etat.

    On empile les états données après avoir joué toutes
    les lettres jouables (si arête existe et si dans l'inventaire).

    Si on a une arête + :
      On retourne à la position initiale et on empile le nouvel état.
      On pense bien à changer de sens dans le parcours.

  Si case occupée :
    Si arête existe :
      On empile un nouvel état.
```
