#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
int main(int argc , char **argv)
{
	char buffer[MAX_SIZE];

	char* ret_buf = getcwd(buffer, MAX_SIZE);

	if(ret_buf == NULL){
		printf("could not get the current directory, error : %d\n", errno);
		exit(-1);
	}
	int length = strlen(ret_buf);
	ret_buf[length + 1] = '\n';
	ret_buf[length + 2] = '\0';
	int num_write = write(1, ret_buf, length + 2);
	if(num_write == -1)
	{
		printf("could not write to stdout");
		exit(-2);
	}
	return 0;
}
