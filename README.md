# generation_labyrinthes_parfaits
Un labyrinthe est dit parfait dès lors qu’entre toute paire de cases, il existe un
et un seul chemin de l’une à l’autre dans le labyrinthe. Autrement dit le graphe dont les sommets
sont les cases du labyrinthe et dont les arêtes joignent deux cases ayant un côté commun sans
mur est un arbre. 
L'objectif est de générer des labyrinthes parfait à l'aide d'une structure UnionFind

Dans le fichier uf.c est implémentée la structure UnionFind, il s'agit d'une strucure arborescente pour représenter des partitions d'un ensemble.
Y sont stockées les informations suivantes :
- l’entier représenté par le nœud : elem,
- le père du nœud x (qui est lui même un nœud) : parent,
- le rang du nœud x : rank
