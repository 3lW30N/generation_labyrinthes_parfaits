#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>


void print_uf_partition_verbose(uf_partition_t p, int n) {
  // hypothèse : p est une partition de [0..n[
  // affiche pour chaque élém de [0..n[ la remontée jusqu'à une racine
  // dans la structure union find p
  for (int i = 0; i < n; i ++) {
    uf_elem_t cursor = p[i];
    for (; cursor->parent != cursor; cursor = cursor->parent) {
      printf("%d ~> ", cursor->elem);
    };
    printf("%d", cursor->elem);
    printf("\n");
  }
}


uf_partition_t exemple() {
  //crée la partition donnée en exemple dans l'énoncé du DM
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 11);
  for (int i = 0 ; i < 11; i ++) {
    res[i] = malloc(sizeof(struct uf_elem_s));
    res[i]->elem = i;
    res[i]->rank = 0;
  }
  res[0]->parent  = res[5];
  res[1]->parent  = res[2];
  res[2]->parent  = res[7];
  res[3]->parent  = res[7];
  res[4]->parent  = res[4];
  res[5]->parent  = res[5];
  res[6]->parent  = res[6];
  res[7]->parent  = res[7];
  res[8]->parent  = res[4];
  res[9]->parent  = res[4];
  res[10]->parent = res[4];

  res[2]->rank   = 1;
  res[7]->rank   = 2;
  res[5]->rank   = 1;
  res[4]->rank   = 1;

  return res;
}


//  IMPLEMENTATION DE LA STRUCTURE UNIONFIND

uf_partition_t uf_initialize(int size){
  uf_partition_t res = malloc(sizeof(uf_elem_t)*(size+1));
  for (int i = 0; i < size; i++)
  {
    res[i] = malloc(sizeof(struct uf_elem_s));
    res[i]->elem = i;
    res[i]->rank = 0;
    res[i]->parent = res[i];
  }
  return res;
}

void uf_free(uf_partition_t p, int size){
  for (int i = 0; i < size; i++)
  {
    free(p[i]);
  }
  free(p);
}

uf_elem_t uf_find_no(uf_elem_t e){
  while (e->parent != e)
  {
    e = e->parent;
  }
  return e;
}

uf_elem_t uf_find(uf_elem_t x){
  if(x->parent != x){
    x->parent = uf_find(x->parent);
  }
  return x->parent;
}

void uf_union(uf_elem_t a, uf_elem_t b){
  if(a->rank < b->rank){
    // Alors on mettra b comme père de a
    a->parent = b;
  }
  else if (a->rank == b->rank){
    a->parent = b;
    b->rank ++;
  }
  else {
    b->parent = a;
  }
}

/* La fonction ci-dessous devra être utilisée pour tester vos fonctions */
int main() {
  /* Q1 */
  /* Décommenter ci-dessous pour tester la question 1. */
  uf_partition_t part_0 = uf_initialize(0); 
  int q1_test = 10; 
  uf_partition_t part_1 = uf_initialize(q1_test); 
  for (int i = 0; i < q1_test; i ++) { 
    assert(part_1[i]->rank == 0); 
    assert(part_1[i]->elem == i); 
    assert(part_1[i]->parent == part_1[i]); 
  } 
  printf("Test Q1 OK\n");

  /* Q2 */
  /* Décommenter ci-dessous pour tester la question 2. */
  uf_free(part_0, 0);
  uf_free(part_1, q1_test);
  printf("Test Q2 OK\n");

  /* Q3 */
  /* Décommenter ci-dessous pour tester la question 3. */
  uf_partition_t q3_ex = exemple();
  uf_partition_t q3_ex_copy = exemple();
  assert(uf_find_no(q3_ex[0]) == q3_ex[5]);
  assert(uf_find_no(q3_ex[1]) == q3_ex[7]);
  assert(uf_find_no(q3_ex[2]) == q3_ex[7]);
  assert(uf_find_no(q3_ex[3]) == q3_ex[7]);
  assert(uf_find_no(q3_ex[4]) == q3_ex[4]);
  assert(uf_find_no(q3_ex[5]) == q3_ex[5]);
  assert(uf_find_no(q3_ex[6]) == q3_ex[6]);
  assert(uf_find_no(q3_ex[7]) == q3_ex[7]);
  assert(uf_find_no(q3_ex[8]) == q3_ex[4]);
  assert(uf_find_no(q3_ex[9]) == q3_ex[4]);
  assert(uf_find_no(q3_ex[10]) == q3_ex[4]);
  equality(q3_ex, q3_ex_copy, 11);
  printf("Test Q3 OK\n");

  /* Q4 */
  /* Décommenter ci-dessous pour tester la question 4. */
  uf_partition_t q4_ex = exemple_pour_test_1();
  uf_partition_t q4_ex_res = exemple_pour_test_2();
  assert(uf_find(q4_ex[8]) == q4_ex[7]);
  equality(q4_ex, q4_ex_res, 10);
  assert(uf_find(q4_ex[0]) == q4_ex[0]);
  assert(uf_find(q4_ex[1]) == q4_ex[7]);
  assert(uf_find(q4_ex[2]) == q4_ex[7]);
  assert(uf_find(q4_ex[3]) == q4_ex[7]);
  assert(uf_find(q4_ex[4]) == q4_ex[7]);
  assert(uf_find(q4_ex[5]) == q4_ex[7]);
  assert(uf_find(q4_ex[6]) == q4_ex[7]);
  assert(uf_find(q4_ex[7]) == q4_ex[7]);
  assert(uf_find(q4_ex[8]) == q4_ex[7]);
  assert(uf_find(q4_ex[9]) == q4_ex[7]);
  assert(q4_ex[0]->rank == q4_ex_res[0]->rank);
  assert(q4_ex[0]->elem == 0);
  assert(q4_ex[0]->parent == q4_ex[0]);
  for (int i = 1; i < 10; i ++) {
    assert(q4_ex[i]->rank == q4_ex_res[i]->rank);
    assert(q4_ex[i]->elem == i);
    assert(q4_ex[i]->parent == q4_ex[7]);
  }
  printf("Test Q4 OK\n");

  /* Q5 */
  /* Décommenter ci-dessous pour tester la question 4. */
/*   int q5_size = 10;
  uf_partition_t q5_ex = uf_initialize(q5_size);
  equality(q5_ex, ex0(), q5_size);
  uf_union(q5_ex[4], q5_ex[8]);
  equality(q5_ex, ex1(), q5_size);
  uf_union(q5_ex[6], q5_ex[4]);
  equality(q5_ex, ex2(), q5_size);
  uf_union(q5_ex[9], q5_ex[1]);
  equality(q5_ex, ex3(), q5_size);
  uf_union(q5_ex[8], q5_ex[1]);
  equality(q5_ex, ex4(), q5_size);
  uf_union(q5_ex[5], q5_ex[3]);
  equality(q5_ex, ex5(), q5_size);
  uf_union(q5_ex[3], q5_ex[7]);
  equality(q5_ex, ex6(), q5_size);
  uf_union(q5_ex[1], q5_ex[2]);
  equality(q5_ex, ex7(), q5_size);
  uf_union(q5_ex[2], q5_ex[7]);
  equality(q5_ex, ex8(), q5_size);
  uf_union(q5_ex[8], q5_ex[5]);
  equality(q5_ex, ex9(), q5_size);
  printf("Test Q5 OK\n"); */
}


/* int test() {
  uf_partition_t ex = exemple();
  print_uf_partition_verbose(ex, 11);
} */
