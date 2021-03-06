#include <xinu.h>
#include <future.h>


typedef struct futent future;

syscall future_set(future *f, char *value) /* changed value type from int to char for Assignment7 */
{
pid32 pid;

if (f->flag == FUTURE_EXCLUSIVE){
	if (f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING ){
	   //f->value = *value; commented this and added below line for Assignment7
	   f->value = value;
	   f->state = FUTURE_VALID;
	   return OK;
	 }

}

if (f->flag == FUTURE_SHARED){
	if (f->state == FUTURE_EMPTY ){
                f->value = *value;
		f->state = FUTURE_VALID;

        }
        if (f->state == FUTURE_WAITING){
                f->value = *value;
		f->state = FUTURE_VALID;
		while (front_gq <= rear_gq ){
		f->pid = gdequeue_pid(f->get_queue);
                resume(f->pid); 
                }
        return OK;
		
        }
}

if (f->flag == FUTURE_QUEUE){
     if (f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING){
     if (front_gfq != -1 && rear_gfq != -1){

        pid = gfdequeue_pid(f->get_queue);
	f->state = FUTURE_VALID;
        f->value = *value;
        resume(pid);
        }
     else{
        f->pid = getpid();
        f->state = FUTURE_WAITING;
        senqueue_pid(f->set_queue, f->pid);
        suspend(f->pid);
        }
     }
  
}

return SYSERR;

}


