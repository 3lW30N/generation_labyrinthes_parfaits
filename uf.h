#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

struct uf_elem_s {
  int             rank   ;
  int             elem   ;
  struct uf_elem_s* parent ;
};

typedef struct uf_elem_s* uf_elem_t;

typedef uf_elem_t* uf_partition_t ;
