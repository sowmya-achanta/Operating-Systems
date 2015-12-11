#include <xinu.h>
#include <future.h>

uint32 future_prod(future *fut) {
  //int j; commented these two lines for ass7
  //j = 5;
  char *k = "This is it"; /*passing string instead of int j for ass7 */
	//*k = 'a';
  /*j = (int)fut;
  for (i=0; i<1000; i++) {
    j += i;
  }*/
  //future_set(fut, &j); commented this one for Ass7 and added below line
 future_set(fut, k);

  return OK;
}
