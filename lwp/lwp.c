#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>

#define STACK 4096

int a = 0;

static int child(void *data)
{
  printf("Child started\n");
  a = 1;
  exit(0);
}

int main()
{
  char *stack;
  char buf[1024];
  int ret;

  stack = malloc(STACK*sizeof(char));
  if (stack == NULL) {
    perror("Malloc failed: ");
    exit(1);
  }
  printf("Starting thread\n");

  ret = clone(child, stack + STACK, SIGCHLD |  CLONE_VM, buf);
  if (ret < 0) {
    perror("Clone failed\n");
    exit(2);
  }
  printf("Ret = %d\n", ret);

  if (wait(&ret) == -1) {
    perror("Wait error\n");
    exit(3);
  }
  printf("A = %d\n", a);

  return 0;
}
