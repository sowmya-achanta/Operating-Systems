#ifndef _FUTURE_H_
#define _FUTURE_H_
 
/* define states */
#define FUTURE_EMPTY	  0
#define FUTURE_WAITING 	  1         
#define FUTURE_VALID 	  2         

/* modes of operation for future*/
#define FUTURE_EXCLUSIVE  1
#define FUTURE_SHARED     2
#define FUTURE_QUEUE      3

#define MAX 4

extern int front_gq, rear_gq, front_sq, rear_sq, front_gfq, rear_gfq;

typedef struct futent
{
   char *value;		
   int flag;		
   int state;         	
   pid32 pid;
   int get_queue[MAX];
   int set_queue[MAX];
} future;


int genqueue_pid(int get_queue[], pid32 pid);
pid32 gdequeue_pid(int get_queue[]);

int senqueue_pid(int set_queue[], pid32 pid);
pid32 sdequeue_pid(int set_queue[]);

/* Interface for system call */
future* future_alloc(int future_flags);
syscall future_free(future*);
syscall future_get(future*, char*); /*changed from int* to char* for ass7 */
syscall future_set(future*, char*);	/*changed from int* to char* for ass7 */

/*function Prototype*/
uint32 future_cons(future *fut);
uint32 future_prod(future *fut);
uint32 future_networks(future *net_fut);
uint32 future_udpnetworks(future *net_fut);

#endif /* _FUTURE_H_ */


	
