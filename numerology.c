#include <stdio.h>
#include <stdlib.h>

#define N 24
int n, A[N];

long long data[N];
char operator[N];
int top;
long long min, value, d;

void dfs(int);
int main(int argc, char **argv)
{
     scanf("%d%lld", &n, &d);
     int i;
     for (i = 0; i < n; i++)
	  scanf("%d", A+i);

     dfs(n);
     printf("No\n%lld\n", min);

     return 0;
}

void dfs(int m)
{
     int i, j, k;
     if (m == 0 && operator[top - 1] == '+')
     {
	  if (value == d)
	  {
	       for (k = 0; k < top - 1; k++)
		    printf("%lld%c", data[k], operator[k]);
	       printf("%lld\n", data[top-1]);
	       exit(0);
	  }
	  if (value > d && (value < min || min == 0))
	       min = value;
     }

     if (value >= d)
	  return;


     for (i = 0; i < m; i++)
     {
	  if (m - i > 18)
	       continue;
	  
	  long long in = 0;
	  for (j = n - m; j < n - i; j++)
	  {
	       in *= 10;
	       in += A[j];
	  }
	  long long tmp = value;
	  if (top == 0)
	       value = in;
	  else if (operator[top - 1] == '+')
	       value += in;
	  else
	       value *= in;
	  
	  data[top] = in;
	  operator[top++] = '+';
	  dfs(i);
	  operator[top - 1] = '*';
	  dfs(i);
	  top--;
	  value = tmp;
     }
}
