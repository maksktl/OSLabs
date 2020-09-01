#include<stdio.h>

void swapper(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    swapper(&a, &b);
    printf("a: %d\nb: %d", a, b);
}



