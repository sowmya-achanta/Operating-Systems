#include <xinu.h>
#include <future.h>
#include <prodcons.h>
#include <stdlib.h>

int n;                         //Definition for global variable 'n
sid32 consumed, produced;     //Definition for semaphores

int front_gq;
int rear_gq;

shellcmd xsh_prodcons(int nargs, char *args[])
{

//Argument verifications and validations

      int count = 2000;             //local varible to hold count
       n =0;

	front_gq=-1;
	rear_gq=-1;
     /*Initialise semaphores*/
      consumed = semcreate(1);      
      produced = semcreate(0);

     /* Check argument count */

	if (nargs != 2) {
		fprintf(stderr, "%s: incorrect number of arguments, need exactly two\n", args[0]);
                return 1;
	    }

        else
        {     
            /* Output info for '--help' argument */

	      if (nargs == 2 && strncmp(args[1], "--help", 7) == 0)
              {
		printf("Usage: %s [Integer] \n", args[0]);
		printf("Enter prodcons followed by an integer\n");
                return 1;
              }

	     else{
               //check args[1] if present assign value to count
               if (nargs == 2 && strncmp(args[0], "prodcons", 8) == 0 ) {
	        
	           if (strncmp(args[1], "-f", 2) != 0){
	           count = atoi(args[1]);
      		   //create the process producer and consumer and put them in ready queue.
      		   //Look at the definitions of function create and resume in exinu/system folder for reference.      
	           resume( create(produce, 1024, 20, "produce", 1, count) );
	           resume( create(consume, 1024, 20, "consume", 1, count) );
		  
	           }
	          
		  else {
	          future *f_exclusive, *f_shared, *f_queue;
 
		  f_exclusive = future_alloc(FUTURE_EXCLUSIVE);
		  f_shared = future_alloc(FUTURE_SHARED);
		  f_queue = future_alloc(FUTURE_QUEUE);
		 
		// Test FUTURE_EXCLUSIVE
		  //resume( create(future_cons, 1024, 20, "fcons1", 1, f_exclusive) );
		  //resume( create(future_prod, 1024, 20, "fprod1", 1, f_exclusive) );
		   resume( create(future_networks, 1024, 20, "fnet", 1, f_exclusive ));
		   resume( create(future_udpnetworks, 1024, 20, "fnetudp", 1, f_exclusive));
		  

		/*commented for Assignment 7
		// Test FUTURE_SHARED
		  resume( create(future_cons, 1024, 20, "fcons2", 1, f_shared) );
		  resume( create(future_cons, 1024, 20, "fcons3", 1, f_shared) );
		  resume( create(future_cons, 1024, 20, "fcons4", 1, f_shared) ); 
		  resume( create(future_cons, 1024, 20, "fcons5", 1, f_shared) );
		  resume( create(future_prod, 1024, 20, "fprod2", 1, f_shared) );

	
		//Test FUTURE_QUEUE
		  resume( create(future_cons, 1024, 20, "fcons6", 1, f_queue) );
		  resume( create(future_cons, 1024, 20, "fcons7", 1, f_queue) );
		  resume( create(future_cons, 1024, 20, "fcons8", 1, f_queue) );
		  resume( create(future_cons, 1024, 20, "fcons9", 1, f_queue) );
		  resume( create(future_prod, 1024, 20, "fprod3", 1, f_queue) );
		  resume( create(future_prod, 1024, 20, "fprod4", 1, f_queue) );
		  resume( create(future_prod, 1024, 20, "fprod5", 1, f_queue) );
		  resume( create(future_prod, 1024, 20, "fprod6", 1, f_queue) ); */

	          }
               }
              }
        }    

return 0;
}


