#include <xinu.h>
#include <future.h>


uint32 future_networks(future *net_fut)
{
printf("Got a call from udpclient");
int status;
char *fut_buff;
  //printf("fut_buff %s", &fut_buff);
  status = future_get(net_fut, fut_buff);
 
  if (status < 1) {
    printf("future_get failed\n");
    return -1;
  }
  printf("it produced %s\n", net_fut->value);
  future_free(net_fut); 
  return OK;
}
