#include <stdio.h>
#define M 10000

struct stack
{
     int data[M];
     int top;
}A, S;

int pop(struct stack *);
void push(struct stack *, int);
int findmax(void);

int main(int argc, char *argv[])
{
     int n, i;
     scanf("%d", &n);
     for (i = 0; i < n; i++)
	  scanf("%d", A.data + n - 1 - i); /* 后进者进栈底 */

     A.top = n;
     S.top = 0;
     int a, e;

     for (i = 0; i < n; i++)
     {
	  a = findmax();	/* 从A中取出最大的元素 */

	  if (S.top == 0 || a > S.data[S.top - 1])
	  {
	       do {
		    e = pop(&A);
		    push(&S, e);
	       } while(e < a);
	  }
	  printf("%d ", pop(&S));
     }
     printf("\n");

     return 0;
}

int pop(struct stack *pA)
{
     return pA->data[--(pA->top)];
}

void push(struct stack *pA, int e)
{
     pA->data[(pA->top)++] = e;
}

int findmax()
{
     int i;
     int max = 0;
     for (i = 0; i < A.top; i++)
	  if (A.data[i] > max)
	       max = A.data[i];
     return max;
}
