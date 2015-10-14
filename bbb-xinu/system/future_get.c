#include <xinu.h>
#include <future.h>

typedef struct futent future;

syscall future_get(future *f, int *value)
{

if (f->state == FUTURE_EMPTY)
{
   f->pid = getpid(); //get thread id  and store it in future's pid
   f->state = FUTURE_WAITING; // put to waiting queue

		while(f->state != FUTURE_VALID)
		 {
		   kprintf("");
		 }
}

if(f->state == FUTURE_VALID)
	{
	*value = f->value;
	f->state = FUTURE_EMPTY;
	return OK;
	}


return SYSERR;

}

