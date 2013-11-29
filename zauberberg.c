#include <stdio.h>
#include <stdlib.h>
#define M 100000

int A[M], B[M], n, h, m, ia, ib;

void mergeSort(int *, int, int);
int main(int argc, char **argv)
{

     scanf("%d%d", &n, &h);
     int i;
     int lev; char ill;

     for (i = 0; i < n; i++)
     {
	  scanf("%d %c", &lev, &ill);
	  if (ill == '+')
	       A[ia++] = lev;
	  else
	       B[ib++] = lev;
     }

     mergeSort(A, 0, ia);
     mergeSort(B, 0, ib);

     scanf("%d", &m);
     double hit, hat;

     for (i = 0; i < m; i++)
     {
     	  scanf("%lf%lf", &hit, &hat);

	  int left, right;

	  if (hit == 0)
	       right = h;
	  else
	       right = A[(int)(hit * ia + 0.999999) - 1];

	  if (hat == 1)
	       left = 0;
	  else
	       left = B[(int)(hat * ib)] + 1;
	  
     	  if (left > right)
     	       printf("-1\n");
     	  else
     	       printf("%d %d\n", left, right);

     }

     return 0;
}

void mergeSort(int *C, int lo, int hi)
{

     if (hi - lo < 2)
	  return;

     int mi = lo + (hi - lo) / 2;
     mergeSort(C, lo, mi);
     mergeSort(C, mi, hi);
     
     int *pt = malloc((mi - lo) * sizeof(int));
     int i, j, k;
     for (i = 0; i  < mi - lo; i++)
	  pt[i] = C[lo + i];

     for (i = 0, j = mi, k = lo; i < mi - lo;)
     {
	  if (j > hi - 1 || pt[i] > C[j] )
	       C[k++] = pt[i++];
	  else
	       C[k++] = C[j++];
     }
 
     free(pt);

}

