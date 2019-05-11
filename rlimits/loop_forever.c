#include <stdio.h>
#include <stdlib.h>

int main()
{
  long a;
  while (1) {
    a += rand();
    if (a % 99 == 0)
      a = 0;
  }
}
