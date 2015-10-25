#include <xinu.h>
#include <future.h>

uint32 future_prod(future *fut) {
  int i, j;
  j = 5;
  /*j = (int)fut;
  for (i=0; i<1000; i++) {
    j += i;
  }*/
  future_set(fut, &j);

  return OK;
}
