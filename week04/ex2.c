#include<stdio.h>
#include<sys/types.h>

/*
 ex02─┬─ex02─┬─ex02───ex02
      │      └─ex02
      ├─ex02───ex02
      └─ex02

for three calls of fork there are 8 processes.

 each fork clone the current program in current state to another process. Then the number of processes will be 2^n,
 where n is number of fork calls

 The result for 5 calls of fork will be 32 processes.
*/

int main(){
    for(int i = 0; i < 5; ++i){
        fork();
    }
    sleep(5);
}