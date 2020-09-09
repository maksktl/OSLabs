#include<stdio.h>
#include<sys/types.h>

int main(){
    char s[100];
    while(1){
        scanf("%s", s);
        system(s);
    }
    return 0;
}