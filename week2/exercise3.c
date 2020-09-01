#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void piramid(int n){
     for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i - 1; ++j)
            printf(" ");
        for(int j = 0; j < (i+1)*2-1; ++j)
            printf("*");
        printf("\n");
    }
}

void triangle(int n){
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n/2-abs(n/2-i);++j)
            printf("*");
    printf("\n");
    }
}

void sqr(int n){
     for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            printf("*");
    printf("\n");
    }
}

int main(int argc, char *argv[]){
    int n;
    if(sscanf(argv[1], "%d", &n) != 1){
	printf("Error");
	return -1;
    }
    printf("Type:\n1 for piramid\n2 for triangle\n3 for square\n");
    int type;
    scanf("%d", &type);
    switch(type){
        case 1:
        piramid(n);
        break;
        case 2:
        triangle(n);
        break;
        case 3:
        sqr(n);
        break;
        default:
        printf("Error data");
        break;
    }
}


