#include <xinu.h>
#include <prodcons.h>



 void produce(int count)
 {
       
      //Use system call wait() and signal() with predefined semaphores produced and consumed to synchronize critical section
      //Code to produce values less than equal to count,
      //produced value should get assigned to global variable 'n'.
      //print produced value e.g. produced : 8 
       
       int i;
       
       for(i=0; i<=count; i++)
       {
           printf("The produced value is: %d\n", n);
           wait(consumed);
           n++;
           signal(produced);
        }
      n = 0;
 }