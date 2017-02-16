# Enumération des cas généraux

- si (pont_placé = 0 & val = 2card(voisins_possibles) ) alors placer pont double avec tous les voisins
- si 1+ (val quo 2) = card(voisins_possibles) alors placer un pont simple avec tous les voisins
- Si 1+ ((val- ponts_placés) quo 2 ) = card(voisins_possibles) alors placer un pont simple avec tous les voisins


## pont_placés = 0 & val = 2card(VP)
- Se placer dans la case (peut en avoir plusieurs (?)) de la grille entre les 2 iles et créer un pont (Quel Constructeur ?)
    - construire Pont(ile1, ile2, 2, (Boolean ou pas?))
- déterminer si le pont est vertical ou horizontal (à faire avant ou maintenant si on utilise l'Accesseur ou le Constructeur)
- majVoisinsReels(pont)

## 1+ (val quo 2) = card(voisins_possibles)
- Se placer dans la case (comme précédemment)
    - construire Pont(ile1, ile2, 1, (Boolean ou pas?))
- déterminer si le pont est vertical ou horizontal (à faire avant ou maintenant si on utilise l'Accesseur ou le Constructeur)
- majVoisinsReels(pont)


## Conclusion
Dans tous les cas on appelle Constructeur + fonction pont vertical ou non + majVoisinsReels => Trouver une alternative
