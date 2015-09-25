/* xsh_reset.c - xsh_reset */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_reset
 *------------------------------------------------------------------------
 */
shellcmd xsh_reset(int nargs, char *args[]) 
{
 
volatile uint32 *prm_rstctrl = (volatile uint32 *) 0x44E00F00; //getting the address of the register
*prm_rstctrl = 0x01; //Generate warm software reset(setting the LSB to 1)

return 1;
}
