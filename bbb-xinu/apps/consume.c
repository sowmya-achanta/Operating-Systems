#include <xinu.h>
#include <stdio.h>
#include <prodcons.h>


 void consume(int count)
 {
   
     //Code to consume values of global variable 'n' until the value of n is less than or equal to count
     //print consumed value e.g. consumed : 8
     int i = n; 
      for(i=0; i<=count; i++)
       {
           printf("The consumed value is: %d\n", n);

        }
 }
