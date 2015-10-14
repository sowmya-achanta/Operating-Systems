#include <xinu.h>
#include <future.h>

typedef struct futent future;

future* future_alloc(int future_flags)
{

future* f;

f = (future *)getmem(sizeof(future));

if (f == NULL)
   return NULL;

f->flag = future_flags;
f->state = FUTURE_EMPTY;

return f;

}
