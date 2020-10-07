#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

const int mb = 1048576;
int *info = NULL;
size_t sz = 0;
struct rusage usage;

int main()
{
	printf("%s\n", "---------------------------------------------------------------------------------------");
	printf("| User CPU time (usec) | System CPU time (usec) | Page faults"
		   " (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");
	printf("%s\n", "---------------------------------------------------------------------------------------");
	for(int i = 0; i < 10; ++i)
	{
		sz += 10*mb;
		info = realloc(info, sz);
		if(info == NULL)exit(1);
		memset(info, 0, sz);
		getrusage(RUSAGE_SELF, &usage);
		printf("| %20ld | %22ld | %21ld | %20ld | %16ld |\n",usage.ru_utime.tv_usec,usage.ru_stime.tv_usec,usage.ru_minflt,usage.ru_majflt,usage.ru_nvcsw + usage.ru_nivcsw);
		sleep(1);
	}
	printf("%s\n", "----------------------------------------------------------------------------------------");
	free(info);
	return 0;
}
