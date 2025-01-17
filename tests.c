#include "tests.h"


uf_partition_t ex0() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 0;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 0;
  res[4]->elem = 4;
  res[4]->parent = res[4];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[5];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[6];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[8];
  res[8]->rank = 0;
  res[9]->elem = 9;
  res[9]->parent = res[9];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex1() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 0;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 0;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[5];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[6];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[8];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[9];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex2() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 0;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 0;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[5];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[8];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[9];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex3() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 1;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 0;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[5];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[8];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex4() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 0;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[5];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex5() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 1;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[3];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[7];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex6() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[2];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 1;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[3];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[3];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex7() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[1];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[3];
  res[3]->rank = 1;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[3];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[3];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex8() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[1];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[1];
  res[3]->rank = 1;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[3];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[3];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t ex9() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0; i < 10; i ++) {
    res[i]= malloc(sizeof(struct uf_elem_s));
  }
  res[0]->elem = 0;
  res[0]->parent = res[0];
  res[0]->rank = 0;
  res[1]->elem = 1;
  res[1]->parent = res[1];
  res[1]->rank = 2;
  res[2]->elem = 2;
  res[2]->parent = res[1];
  res[2]->rank = 0;
  res[3]->elem = 3;
  res[3]->parent = res[1];
  res[3]->rank = 1;
  res[4]->elem = 4;
  res[4]->parent = res[8];
  res[4]->rank = 0;
  res[5]->elem = 5;
  res[5]->parent = res[1];
  res[5]->rank = 0;
  res[6]->elem = 6;
  res[6]->parent = res[8];
  res[6]->rank = 0;
  res[7]->elem = 7;
  res[7]->parent = res[3];
  res[7]->rank = 0;
  res[8]->elem = 8;
  res[8]->parent = res[1];
  res[8]->rank = 1;
  res[9]->elem = 9;
  res[9]->parent = res[1];
  res[9]->rank = 0;
  return res;
}

uf_partition_t exemple_pour_test_1() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0 ; i < 10; i ++) {
    res[i] = malloc(sizeof(struct uf_elem_s));
    res[i]->elem = i;
    res[i]->rank = 0;
  }
  res[0]->parent  = res[0];
  res[1]->parent  = res[2];
  res[2]->parent  = res[7];
  res[3]->parent  = res[7];
  res[4]->parent  = res[8];
  res[5]->parent  = res[3];
  res[6]->parent  = res[8];
  res[7]->parent  = res[7];
  res[8]->parent  = res[1];
  res[9]->parent  = res[1];

  res[1]->rank   = 2;
  res[2]->rank   = 3;
  res[3]->rank   = 1;
  res[7]->rank   = 4;
  res[8]->rank   = 1;

  return res;
}

uf_partition_t exemple_pour_test_2() {
  uf_partition_t res = malloc(sizeof(uf_elem_t) * 10);
  for (int i = 0 ; i < 10; i ++) {
    res[i] = malloc(sizeof(struct uf_elem_s));
    res[i]->elem = i;
    res[i]->rank = 0;
  }
  res[0]->parent  = res[0];
  res[1]->parent  = res[7];
  res[2]->parent  = res[7];
  res[3]->parent  = res[7];
  res[4]->parent  = res[8];
  res[5]->parent  = res[3];
  res[6]->parent  = res[8];
  res[7]->parent  = res[7];
  res[8]->parent  = res[7];
  res[9]->parent  = res[1];

  res[1]->rank   = 2;
  res[2]->rank   = 3;
  res[3]->rank   = 1;
  res[7]->rank   = 4;
  res[8]->rank   = 1;

  return res;
}

void equality_aux(uf_elem_t x, uf_elem_t y) {
  assert(x->rank == y->rank);
  assert(x->elem == y->elem);
  assert((x->parent == x) == (y->parent == y));
  if (x->parent != x) {equality_aux(x->parent, y->parent);}
}

void equality(uf_partition_t part1, uf_partition_t part2, int size) {
  for (int i = 0 ; i < size ; i ++) {
    equality_aux(part1[i], part2[i]);
  }
}
