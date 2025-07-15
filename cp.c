#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define COUNT 100

int main(int argc , char **argv)
{
  char buf[COUNT];
  if(argc > 3 || argc < 3 ){
    printf("%s : \"%s\" : No such file or directory ", argv[0], argv[2]);
    exit(-1);
  }	
  int source_fd = open(argv[1], O_RDONLY);
  if(source_fd < 0){
    printf("Couldn't open the source file %s : error %d \n", argv[1] , errno);
    exit(-2);
  }
  int dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
  if(dest_fd < 0){
    printf("Couldn't open the source file %s : error %d \n", argv[2] , errno);
    exit(-3);
  }
  int num_read = 0;
  while((num_read = read(source_fd, buf, COUNT)) > 0){
    int num_write = write(dest_fd, buf, num_read);
    if(num_write == -1)
    {
      printf("could not write into dest file %s , num_write = %d\n", argv[2] , num_write);
      exit(-4);
    }
  }
  if(num_read == -1){
    printf("error in reading operation , error %d\n", errno);
    exit(-5);
  }
  close(source_fd);
  close(dest_fd);
  
  return 0;
}
