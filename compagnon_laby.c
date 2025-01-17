#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

struct laby_s {
  int   width  ;                /* largeur du labyrinthe                                     */
  int   height ;                /* hauteur du labyrinthe                                     */
  int* cells  ;                /* tableau indiquant le contenu de chaque case du labyrinthe */
};

typedef struct laby_s laby_t;

/* Description des types de cases.
   ? indique une information présente dans une autre case,
   | ou - indique un mur (vertical ou horizontal)

   De type 0 :
   +?+
   ?
   + +

   De type 1 :
   +?+
   ? |
   + +

   De type 2 :
   +?+
   ?
   +-+

   De type 3 :
   +?+
   ? |
   +-+
   
   Ainsi entre deux cases a et b de coordonnées (i,j) et (i,j+1), ie l'une à côté de l'autre avec a à gauche,
   il y a un mur ssi la case a est de type 1 ou 3, soit de type impair.
   Entre deux cases a et b de coordonnées (i,j) et (i+1,j), ie l'une au dessus de l'autre avec a au dessus, 
   il y a un mur ssi la case a est de type 2 ou 3, soit de type de quotient modulo 2 égal à 1.
*/



void draw_laby(laby_t laby) {
	//affiche le labyrinthe laby avec des caractères ASCII
  for (int j = 0 ; j < laby.width ; j ++) {
    printf("+-");
  }
  printf("+\n");
  for (int i = 0 ; i < laby.height-1 ; i ++) {
    printf("| ");
    for (int j = 0 ; j < laby.width-1 ; j ++) {
      int c = laby.cells[i*laby.width+j];
      if (c % 2 == 1) {printf("| ");}
      else {printf("  ");}
    }
    printf("|\n");
    printf("+");
    for (int j = 0 ; j < laby.width ; j ++) {
      int c = laby.cells[i*laby.width+j];
      if ((c/2) % 2 == 1) {printf("-+");}
      else {printf(" +");}
    }
    printf("\n");
  }
  printf("| ");
  for (int j = 0 ; j < laby.width-1 ; j ++) {
    int c = laby.cells[(laby.height-1)*laby.width+j];
    if (c % 2 == 1) {printf("| ");}
    else {printf("  ");}
  }
  printf("|\n");
  printf("+");
  for (int j = 0 ; j < laby.width ; j ++) {
    printf("-+");
  }
  printf("\n");
}





void draw_laby_with_visited(laby_t laby, bool* visited) {
	//affiche le labyrinthe laby et le chemin décrit par visited en ASCII
  for (int j = 0 ; j < laby.width ; j ++) {
    printf("+-");
  }
  printf("+\n");
  for (int i = 0 ; i < laby.height-1 ; i ++) {
    printf("|");
    for (int j = 0 ; j < laby.width-1 ; j ++) {
      if (visited[i*laby.width+j]) {printf("·");}
      else {printf(" ");}
      int c = laby.cells[i*laby.width+j];
      if (c % 2 == 1) {printf("|");}
      else {
        if (visited[i*laby.width+j] && visited[i*laby.width+j+1]) {printf("·");}
        else {printf(" ");}
      }
    }
    if (visited[i*laby.width+laby.width-1]) {printf("·");}
    else {printf(" ");}
    printf("|\n");
    printf("+");
    for (int j = 0 ; j < laby.width ; j ++) {
      int c = laby.cells[i*laby.width+j];
      if ((c/2) % 2 == 1) {printf("-+");}
      else {
        if (visited[i*laby.width+j] && visited[(i+1)*laby.width+j]) {printf("·+");}
        else {printf(" +");}
      }
    }
    printf("\n");
  }
  printf("|");
  for (int j = 0 ; j < laby.width-1 ; j ++) {
    if (visited[(laby.height-1)*laby.width+j]) {printf("·");}
    else {printf(" ");}
    int c = laby.cells[(laby.height-1)*laby.width+j];
    if (c % 2 == 1) {printf("|");}
    else {
      if (visited[(laby.height-1)*laby.width+j] && visited[(laby.height-1)*laby.width+j+1]) {printf("·");}
      else {printf(" ");}
    }
  }
  if (visited[(laby.height-1)*laby.width+laby.width-1]) {printf("·");}
  printf("|\n");
  printf("+");
  for (int j = 0 ; j < laby.width ; j ++) {
    printf("-+");
  }
  printf("\n");
}


bool is_laby_plein(laby_t laby) {
	//teste si le labyrinthe laby est plein
  for(int k=0; k < laby.height; k++){
  	if (laby.cells[k] != 3) return false;
  	//3 est le type des cases ac mur sud et mur est
  } 
  return true;
}


int linearise(laby_t laby, int i, int j) { 
	//indice ds le tableau unidimensionnel de la case de coordonnées (i,j) 
	//dans le tableau bidimensionnel aux dimensions de laby
	return i * laby.width + j ; 
}

void delinearise(laby_t laby, int x, int* pi, int* pj) {
	//modifie les valeurs de *pi et *pj pour qu'ils enregistrent les
	//coordoonées dans le tableau bidimensionnel aux dimensions de laby *
	//de la case d'indice x dans le tableau  unidimensionnel correspondant
  *pi = x / laby.width;
  *pj = x % laby.width;
}


bool is_in_laby(laby_t laby, int i, int j) {
  return i >= 0 && j >= 0 && i < laby.height && j < laby.width;
  // teste si la case de coordonnées (i,j) est dans laby
}

bool can_go_from(laby_t laby, int i1, int j1, int i2, int j2) {	
	//hypothèse : is_in_laby(laby,i1,j1) && is_in_laby(laby,i2,j2)
	//teste l'abscence de mur entre les cases (i1,j1) et (i2,j2) ds laby 
  if      (i1 == i2     && j2 == j1 + 1 ) //1 à gauche, 2 à droite
  	{return laby.cells[linearise (laby, i1, j1 )] % 2 == 0;     }
  else if (i1 == i2     && j2 == j1 - 1 ) //2 à gauche, 1 à droite
  	{return laby.cells[linearise (laby, i2, j2 )] % 2 == 0;     }
  else if (i2 == i1 + 1 && j1 == j2     ) //1 au dessus, 2 en dessous
  	{return laby.cells[linearise (laby, i1, j1 )] / 2 % 2 == 0; }
  else if (i1 == i2 + 1 && j1 == j2     ) //2 au dessus, 1 en dessous
  	{return laby.cells[linearise (laby, i2, j2 )] / 2 % 2 == 0; }
  else {return false;}
}



void casse_mur(laby_t laby, int i1, int j1, int i2, int j2) {
	//hypothèse : is_in_laby(laby,i1,j1) && is_in_laby(laby,i2,j2)
	//casse le mur entre la case (i1,j1) et la case (i2,j2) dans laby
  if      (i1 == i2   && j2 == j1 + 1 ) 
  	{laby.cells[linearise (laby, i1, j1 )] = (laby.cells[linearise (laby, i1, j1 )] / 2 ) * 2;}
  else if (i1 == i2   && j2 == j1 - 1 ) 
  	{laby.cells[linearise (laby, i2, j2 )] = (laby.cells[linearise (laby, i2, j2 )] / 2 ) * 2;}
  else if (i2 == i1+1 && j1 == j2     ) 
  	{laby.cells[linearise (laby, i1, j1 )] =  laby.cells[linearise (laby, i1, j1 )] % 2;}
  else if (i1 == i2+1 && j1 == j2     ) 
  	{laby.cells[linearise (laby, i2, j2 )] =  laby.cells[linearise (laby, i2, j2 )] % 2;}
}

//1. Création de labyrinthes parfaits au moyen d’un parcours en profondeur

//Version récursive
void rec_generator(laby_t laby, bool* visited, int i, int j){
  if(i!=0 && !visited[linearise(laby, i-1, j)]){
    casse_mur(laby, i-1, j, i, j);
    visited[linearise(laby, i-1, j)]=true;
    rec_generator(laby, visited, i-1, j);
  }
  if(i<laby.height && !visited[linearise(laby, i+1, j)]){
    casse_mur(laby, i+1, j, i, j);
    visited[linearise(laby, i+1, j)]=true;
    rec_generator(laby, visited, i+1, j);
  }
  if(j!=0 && !visited[linearise(laby, i, j-1)]){
    casse_mur(laby, i, j-1, i, j);
    visited[linearise(laby, i, j-1)]=true;
    rec_generator(laby, visited, i-1, j);
  }
  if(j<laby.width && !visited[linearise(laby, i, j+1)]){
    casse_mur(laby, i, j, i, j+1);
    visited[linearise(laby, i, j+1)]=true;
    rec_generator(laby, visited, i, j+1);
  }
}

void generate_laby(laby_t laby){
  //Initialisation du tableau des visités
  bool* visited;
  int size = laby.height*laby.width;
  visited = (bool*)malloc(size * sizeof(bool));
  assert(visited!=NULL);
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }
  //Visite récursive du labyrinthe
  assert(is_laby_plein(laby));
  rec_generator(laby, visited, 0, 0);
  free(visited);
}

//Version non récursive
/* void generate_laby_not_recursive(laby_t laby){
  //Initialisation du tableau des visités
  bool* visited;
  int size = laby.height*laby.width;
  visited = (bool*)malloc(size * sizeof(bool));
  assert(visited!=NULL);
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }

  for (int i = 0; i < laby.height; i++)
  {
    for (int j = 0; j < laby.width; j++)
    {
      if(!visited[linearise(laby, i, j)]){
        
      }
    }
    
  }
  
} */

//2. Création de labyrinthes parfaits au moyen d’une structure UnionFind

// Définition du type mur
struct mur_s { // mur séparant 2 cases
  int i1 ;
  int j1 ; /* coordonnées de la première case */
  int i2 ;
  int j2 ; /* coordonnées de la deuxième case */
};

typedef struct mur_s mur_t;

// Tableau de tous les murs du labyrinthe passé en argument
mur_t* tab_murs_laby_plein(laby_t laby){
  int h = laby.height;
  int w = laby.width;
  int n = 2*h*w - w - h;
  
  mur_t* tab = (mur_t *)malloc(n * sizeof(mur_t));
  assert(tab!=NULL);

  int k=0;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (laby.cells[linearise(laby, i, j)]=1)
      {
        mur_t mur_droite;
        mur_droite.i1 = i;
        mur_droite.j1 = j;
        mur_droite.i2 = i+1;
        mur_droite.j2 = j;
        tab[k] = mur_droite;
        k++;
      }

      else if (laby.cells[linearise(laby, i, j)]=2)
      {
        mur_t mur_bas;
        mur_bas.i1 = i;
        mur_bas.j1 = j;
        mur_bas.i2 = i;
        mur_bas.j2 = j+1;
        tab[k+1] = mur_bas;
        k++;
      }
      
      else if(laby.cells[linearise(laby, i, j)]=3)
      {
        mur_t mur_droite;
        mur_droite.i1 = i;
        mur_droite.j1 = j;
        mur_droite.i2 = i+1;
        mur_droite.j2 = j;
        tab[k] = mur_droite;

        mur_t mur_bas;
        mur_bas.i1 = i;
        mur_bas.j1 = j;
        mur_bas.i2 = i;
        mur_bas.j2 = j+1;
        tab[k+1] = mur_bas;

        k = k+2;
      }
    } 
  }
  return tab;
}

// Mélange de Fisher-Yates
void melange_liste_murs(mur_t* murs, int n){
  srand(time(NULL));
  for (int i = n-1; i > 0; i--)
  {
    // Génération du nombre aléatoire dans l'intervalle [0, i]
    int j = rand() % (i + 1);
    // Échange des murs
    mur_t tempo = murs[i];
    murs[i] = murs[j];
    murs[j] = tempo;
  }
}

// Fonction pour créer un labyrinthe de taille width x height avec des cases du type donné
laby_t* create_laby(int width, int height, int cell_type) {

    laby_t *labyrinth = (laby_t *)malloc(sizeof(laby_t));
    assert(labyrinth != NULL);
    labyrinth->width = width;
    labyrinth->height = height;

    labyrinth->cells = (int *)malloc(width * height * sizeof(char));
    assert(labyrinth->cells != NULL);

    // Remplissage des cellules avec le type spécifié
    for (int i = 0; i < width * height; i++) {
        labyrinth->cells[i] = cell_type;
    }

    return labyrinth;
}

// Génération de labyrinthes parfaits
laby_t* create_perfect_laby(int h, int w){
  // Création du tableau plein associé au labyrinthe plein
  mur_t* murs = tab_murs_laby_plein(*create_laby(w, h, 3));
  // Mélange du tableau
  melange_liste_murs(murs, 2*w*h-h-w);

  
}


//Fonctions de tests

// Fonction pour libérer la mémoire allouée pour le labyrinthe
void free_laby(laby_t *labyrinth) {
    if (labyrinth != NULL) {
        free(labyrinth->cells);
        free(labyrinth);
    }
}

int main(){




  laby_t* laby_test_1 = create_laby(6, 6, 3);
  draw_laby(*laby_test_1);
  generate_laby(*laby_test_1);
  draw_laby(*laby_test_1);
  return 0;
}