#include <stdio.h>
#include <stdlib.h>
#define N 100001
#define M 1000000
#define max(a,b) ((a)>(b)?(a):(b))

int n, m;
int max;

int indegree[N];
int path[N];

struct node
{
     int data;
     struct node *next;
};

struct node *graph[N];

void insertAsHead(int a, int b)
{
     struct node *village = malloc(sizeof(struct node));
     village->data = b;
     village->next = graph[a];
     graph[a] = village;
}

void build_graph(int a, int b)
{
     insertAsHead(a, b);
     indegree[b]++;
}

int find_an_end()
{
     int i;
     for (i = 1; i <= n; i++)
	  if (indegree[i] == 0)
	       return i;
     return -1;
}

void output()
{
     printf("%d\n", max + 1);
}

void toposort()
{
     int v = find_an_end();
     if (v == -1) 
	  return;

     struct node *p = graph[v];
     while (p)
     {
	  indegree[p->data]--;
	  path[p->data] = max(path[p->data], path[v]+1);
	  max = max(path[p->data], max);
	  p = p->next;
     }
     indegree[v]--;
     toposort();

}
void input()
{
     scanf("%d%d", &n, &m);
     int i, a, b;
     for (i = 0; i < m; i++)
     {
	  scanf("%d%d", &a, &b);
	  build_graph(a, b);
     }
}

int main(int argc, char **argv)
{
     input();
     toposort();
     output();
     return 0;
}
