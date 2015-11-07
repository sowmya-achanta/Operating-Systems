/* my_getstk.c - my_getstk */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  my_getstk  -  Allocate stack memory, returning highest word address
 *------------------------------------------------------------------------
 */
char  	*my_getstk(
	  uint32	nbytes		/* Size of memory requested	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	memblk	*prev, *curr;	/* Walk through memory list	*/

	mask = disable();
	if (nbytes == 0) {
		restore(mask);
		return (char *)SYSERR;
	}

	nbytes = (uint32) roundmb(nbytes);	/* Use mblock multiples	*/
        //printf("The bytes passed: %d\n", nbytes);
	prev = &memlist;
	curr = memlist.mnext;
	
	        curr->mlength -= nbytes;
		curr = (struct memblk *)((uint32)curr + curr->mlength);

	memlist.mlength -= nbytes;
	restore(mask);
	return (char *)((uint32) curr + nbytes - sizeof(uint32));
}
