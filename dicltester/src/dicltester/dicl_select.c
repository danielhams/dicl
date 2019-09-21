#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <bstring.h>
#include <time.h>
#include <sys/time.h>

void dicl_selecttest()
{
  printf("Beginning select test\n");

  fd_set readfds;
  fd_set writefds;
  fd_set exceptionfds;
  struct timeval timeout;

  FD_ZERO(&readfds);
  FD_ZERO(&writefds);
  FD_ZERO(&exceptionfds);
  memset(&timeout,0,sizeof(struct timeval));

  int s_rv = select(0, &readfds, &writefds, &exceptionfds, &timeout);
  printf("Select rv=%d\n", s_rv);

  return;
}
