#include <xinu.h>
#include <future.h>
#include <prodcons.h>
#include <stdlib.h>
int n;                         //Definition for global variable 'n
sid32 consumed, produced;     //Definition for semaphores

shellcmd xsh_prodcons(int nargs, char *args[])
{

//Argument verifications and validations

      int count = 2000;             //local varible to hold count
       n =0;
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
      		   //Look at the definations of function create and resume in exinu/system folder for reference.      
	           resume( create(produce, 1024, 20, "produce", 1, count) );
	           resume( create(consume, 1024, 20, "consume", 1, count) );
	           }
	          
		  else {
	          future *f1, *f2, *f3;
               
 
		  f1 = future_alloc(FUTURE_EXCLUSIVE);
		  f2 = future_alloc(FUTURE_EXCLUSIVE);
		  f3 = future_alloc(FUTURE_EXCLUSIVE);
		    

		  resume( create(future_cons, 1024, 20, "fcons1", 1, f1) );
		  resume( create(future_prod, 1024, 20, "fprod1", 1, f1) );
		  resume( create(future_cons, 1024, 20, "fcons2", 1, f2) );
		  resume( create(future_prod, 1024, 20, "fprod2", 1, f2) );
		  resume( create(future_cons, 1024, 20, "fcons3", 1, f3) );
		  resume( create(future_prod, 1024, 20, "fprod3", 1, f3) );
	          }
               }
              }
        }    

return 0;
}


