#include <xinu.h>
#include <future.h>

uint32 future_cons(future *fut) {

  /*int  status;
//int i;
  char *buff; /*passing string instead of int i for ass7 * /
  //status = future_get(fut, &i); commented this one for Ass7 and added below line
  status = future_get(fut, buff);

  if (status < 1) {
    printf("future_get failed\n");
    return -1;
  }
  //printf("it produced %d\n", i); commented this one for Ass7 and added below line
  printf("it produced %d\n", buff);
   future_free(fut); */
  return OK;
}
