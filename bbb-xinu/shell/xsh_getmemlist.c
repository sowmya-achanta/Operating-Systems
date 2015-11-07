/* xsh_getmemlist.c - xsh_getmemlist */

#include <xinu.h>
//#include <memory.h>
void dummy_process();
void another_dummy();

/*---------------------------------------------------------------------------------
 * xsh_getmemlist - obtain free memory blocks' address and length from memlist
 *---------------------------------------------------------------------------------
 */
shellcmd xsh_getmemlist(int nargs, char *args[]) 
{
   struct memblk *list_attr;
   list_attr = &memlist;
   int pid;
   int count =7;

      
	/* Check argument count */
	if (nargs != 2) {
	fprintf(stderr, "%s: incorrect number of arguments, need exactly two\n", args[0]);
	return 1;}
        else{     
              /* Output info for '--help' argument */
	      if (nargs == 2 && strncmp(args[1], "--help", 7) == 0){
		printf("Usage: %s String\n", args[0]);
		printf("Type getmemlist -f and hit enter\n");
                return 1;}
	      else{
                 if (nargs == 2){

		    if ( (strncmp(args[0], "getmemlist", 10) == 0 ) && (strncmp(args[1], "get91", 5) == 0) ){
                       while(list_attr != NULL){
                          kprintf("The address of free memory block is, %x length of block is %u\n",list_attr, list_attr->mlength);
                          list_attr = list_attr->mnext;}}

                    if ( (strncmp(args[0], "getmemlist", 10) == 0 ) && (strncmp(args[1], "get94", 5) == 0) ){
                            pid = create(dummy_process, 1024, 20, "dummy",0);
                            kprintf("The address of free memory block is, %x length of block:%u\n",list_attr, list_attr->mlength);
                            //list_attr = list_attr->mnext;
                            resume(pid);}
                    if ( (strncmp(args[0], "getmemlist", 10) == 0 ) && (strncmp(args[1], "get97", 5) == 0) ){
                            pid = create(another_dummy, 5000, 20, "anotherdummy",1, count);
                            kprintf("The address of free memory block is, %x length of block:%u\n",list_attr, list_attr->mlength);
                            //list_attr = list_attr->mnext;
                            resume(pid);}
                    }
		    else 
		    printf("The command entered is wrong");
		    return 1;
		}
            }
}

void dummy_process()
{
int n = 20;
char *f;
f = (char *)my_getmem(sizeof(1024));
printf("hello %d\n",n);
printf("The address of f allocated by my_getmem %x", f);
}

void another_dummy()
{
int n = 30;
int b=7;
char a[25] = {"This is a string string string"};
printf("hello %d\n",n);

}
