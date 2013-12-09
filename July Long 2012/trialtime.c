#include <time.h>
#include <stdio.h>

int main ()
{ 
  clock_t start, end;
  double runTime;
  start = clock();
  /* my actual program */
  end = clock();
  runTime = (end - start) / (double) CLOCKS_PER_SEC ;
  printf ("Run time is &#37;g seconds\n", runTime);
  getchar();
  return 0;
}
