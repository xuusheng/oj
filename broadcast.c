#include <stdio.h>
#include <stdlib.h>
#define N 10001			/* 小镇个数最大值 */
#define M 30000			/* 限制条件个数 */

struct node
{
     int data;
     struct node *next;
};

struct node *Head[N];
int fm[N];

int q[N];
int h = 0;
int t = 0;

int n, m;
void bfs();
void init();
void enq(int);
int deq();
void insertAsHead(int, struct node *);
int main(int argc, char **argv)
{
     scanf("%d%d", &n, &m);
     init();

     int i, a, b;
     for (i = 0; i < m; i++) {
	  scanf("%d%d", &a, &b);
	  struct node *town = malloc(sizeof(struct node));
	  town->data = b;
	  insertAsHead(a, town);
	  town = malloc(sizeof(struct node));
	  town->data = a;
	  insertAsHead(b, town);
	       
     }

     for (i = 1; i <= n; i++)
     {
     	  if (!fm[i]) {
     	       fm[i] = 1;
     	       h = 0;
     	       t = 0;
	       enq(i);
	       bfs();
     	  }
     }
     printf("1\n");
     
     return 0;
}

void init()
{
     int i;
     for (i = 0; i < n; i++)
	  Head[i] = NULL;
}
void insertAsHead(int a, struct node *town)
{
     town->next = Head[a];
     Head[a]= town;
}

void bfs()
{
     int a = deq();
     if (a == 0)
	  return;
     
     int temp = (fm[a] == 1 ? 2 : 1);
     struct node *p = Head[a];

     while(p) {
	  if (fm[p->data] == 0) {
	       fm[p->data] = temp;
	       enq(p->data);
	  }
	  else if (fm[p->data] != temp) {
		    printf("-1\n");
		    exit(0);
	  }
	  p = p->next;
     }
     bfs();
}

void enq(int a)
{
     q[t++] = a;
}

int deq()
{
     return q[h++];
}
