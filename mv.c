#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int mv_main(int argc, char *argv[]) {
    if(argc == 1){
		printf("%s: missing file operand\n", argv[0]);
		exit(-1);
	}else if(argc == 2){
		printf("%s: missing destination file operand after '%s' \n", argv[0], argv[1]);
		exit(-2);
	}
	const char *source = argv[1];
	const char *destination = argv[2];

	int ret = rename(source, destination);
	if(ret == -1){
		printf("Could not rename the source file , error %d\n", errno);
		exit(-3);
	}

	return 0;
}
