#include <stdio.h>
#include<string.h>

int main()
{
    char str[256];
    scanf("%s", str);
    for(int i = strlen(str)-1; i >= 0; i--){
        putchar(str[i]);
    }
    return 0;
}
