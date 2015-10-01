#include <xinu.h>
#include <prodcons.h>
#include <stdlib.h>

int n;                             //Definition for global variable 'n
sid32 consumed, produced;     //Definition for semaphores

/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/

shellcmd xsh_prodcons(int nargs, char *args[])
{
      //Argument verifications and validations

      int count = 2000;             //local varible to hold count
      
     /*Initialise semaphores*/
      consumed = semcreate(0);      
      produced = semcreate(1);

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

	     else
             {
               //check args[1] if present assign value to count
               if (nargs == 2 && strncmp(args[0], "prodcons", 8) == 0 ) 
	         {                        
                   count = atoi(args[1]);
              //     printf("This is the value of count %d\n", count);

                 }
                 
            }
	}

       //create the process producer and consumer and put them in ready queue.
      //Look at the definations of function create and resume in exinu/system folder for reference.      
      resume( create(produce, 1024, 20, "produce", 1, count) );
      resume( create(consume, 1024, 20, "consume", 1, count) );
         
return 0;
}


