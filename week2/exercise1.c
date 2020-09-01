#include<limits.h>
#include<float.h>
#include<stdio.h>
int main(){
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("for integer max value %d and size %lu bytes\n", a, sizeof(a));
    printf("for float max value %f and size %lu bytes\n", b, sizeof(b));
    printf("for double max value %f and size %lu bytes\n", c, sizeof(c));

}
