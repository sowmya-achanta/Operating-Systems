#include <xinu.h>
#include <future.h>

typedef struct futent future;


syscall future_free(future* f)
{

if (freemem(f, sizeof(future)))
   return OK;
else
    return SYSERR;


}


