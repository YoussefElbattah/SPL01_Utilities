#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
        int i = 1;
        char *buffer ;

        if(argc == 1){
                if(write(1, "\n", 1) == -1){
                        printf("could not write backslash n to stdout\n");
                        exit(-5);
                }       
        }
        while(argv[i] != NULL){
                int len = strlen(argv[i]);
                int num_write = write(1, argv[i], len);
                if(num_write == -1)
                {
                        printf("could not write into stdout, error %d\n", errno);
                        exit(-2);
                }       
                if(i < (argc - 1)){
                        if(write(1, " " , 1) == -1){
                                printf("could not write space char to stdout\n");
                                exit(-3);
                        }
                }else{
                        if(write(1, "\n\0", 2) == -1){
                                printf("could not write backslash n to stdout\n");
                                exit(-4);
                        }
                }       
                i++;
        }
        return 0;
}
