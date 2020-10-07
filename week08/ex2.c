#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int mb = 1048576;
size_t sz = 0;
int *info = NULL;

int main()
{
	for(int i=0; i<10; ++i)
	{
		sz += mb*10;
		info = realloc(info, sz);
		if(info == NULL)exit(1);
		memset(info, 0, sz);
		sleep(1);
	}
	free(info);
	return 0;
}
