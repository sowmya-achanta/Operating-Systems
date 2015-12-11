/* xsh_udpcom.c - xsh_udp */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_udpcom - obtain string and send it to the server
 *------------------------------------------------------------------------
 */
shellcmd xsh_udpcom(int nargs, char *args[]) 
{
         
        
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
		printf("Usage: %s String\n", args[0]);
		printf("Enter udp followed by a message to send\n");
                return 1;
              }
       	      /* Print the message*/
 
	     else
             {
                 if (nargs == 2) 
	         {
		    if (strncmp(args[0], "udp", 3) == 0) 
		    {
                        printf("Hello %s, Welcome to the world of Xinu-udp\n", args[1]);
			return 1;
		    }
		    else 
		    printf("The command entered is wrong");
		     return 1;
                 }
            }
	}

}
