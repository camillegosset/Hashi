# Mise au point de ce qui fait qu'un voisin est possible ou non

- Le plus proche voisin sur la même abscisse positive
- Le plus proche voisin sur la même abscisse négative
- De même pour l'ordonnée
- Lorsque ile.val = 0 alors celle ci n'a plu de voisin possible et elle n'est plus voisin possible des autres iles
- Lorsqu'un pont est placé, il coupe des ponts possibles alors les voisins ne sont plu possibles entre eux.
