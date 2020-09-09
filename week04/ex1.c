#include<stdio.h>
#include<sys/types.h>

int main(){
   int n = 10;
   pid_t fork_id = fork();
   if(fork_id == 0) {
       printf("Hello from child [%d - %d]\n", fork_id, n);
   }
   else {
       printf("Hello from parent [%d - %d]\n", getpid(), n);
   }
}