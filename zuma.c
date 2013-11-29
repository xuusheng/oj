/* 第一次使用链表解决问题 */
/* 注意链表的尾部有一个换行 */
/* 利用这个可以简化程序 */

/* 程序效率不高，主要原因在于每次插入都是循秩访问， */
/* 思改进之道 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
     char color;
     struct Node *prev;
     struct Node *succ;
};

struct Node *head, *tail;
char A[10000+2];		/* 包括一个换行、一个终止 */
void traverse();
void destroy();
void eliminate(struct Node *);
void insert(int, char);
void insertAsLast(struct Node *);
void init();
int main(int argc, char *argv[])
{

     init();

     fgets(A, sizeof(A), stdin);
     int len = strlen(A);
     int i;
     for (i = 0; i < len; i++)
     {
	  struct Node *ball = malloc(sizeof(struct Node));
	  ball -> color = A[i];
	  insertAsLast(ball);
     }

     int n, m;
     char c;
     scanf("%d", &n);
     for (i = 0; i < n; i++)
     {
	  scanf("%d %c", &m, &c);
	  insert(m, c);
	  traverse();
     }
     
     destroy();

     return 0;
}

void destroy()
{
     struct Node *p = head;
     while((p = p->succ))
	  free(p->prev);
     free(tail);

}

void insertAsLast(struct Node *ball)
{
	  tail->prev->succ = ball;
	  ball->succ = tail;
	  ball->prev = tail->prev;
	  tail->prev = ball;
}

void traverse()
{
     if (head->succ->color == '\n')
     {
	  printf("-\n");
	  return;
     }
     
     struct Node *p = head;
     while ((p = p -> succ) != tail)
	  printf("%c", p->color);

}

void insert(int m, char c)
{
     struct Node *p =  head;
     while(m--)
	  p = p -> succ;
     struct Node *ball = malloc(sizeof(struct Node));
     ball->color = c;

     ball->prev = p;
     ball->succ = p->succ;
     p->succ->prev = ball;
     p->succ = ball;

     eliminate(ball);
	  
}

void eliminate(struct Node *ball)
{
     int count = 1;
     struct Node *left, *right;
     left = ball;
     while ((left = left->prev)->color == ball->color)
	  count++;

     right = ball;
     while ((right = right->succ)->color == ball->color)
	  count++;
     
     if (count > 2)
     {
	  left->succ = right;
	  right->prev = left;
	  eliminate(right);
     }
}

void init()
{
     head =  malloc(sizeof(struct Node));
     tail =  malloc(sizeof(struct Node));
     head->succ = tail;
     head->prev = NULL;
     tail->prev = head;
     tail->succ = NULL;
}
