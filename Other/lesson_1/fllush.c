#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

int main()
{

  printf("hello printf\n");
  fprintf(stdout, "hello fprintf\n");
  const char* pri = "hello fputs\n";
  fputs(pri, stdout);


  const char* wri = "hello write\n";
  write(1, wri, strlen(wri));

  fork();

  return 0;

}
