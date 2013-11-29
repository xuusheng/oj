/* 判断一个数是否是回文数 */

/* 其中1 <= a <= 10^10 */

/* 如果按照最简单的方法，因为a可以很大，程序会超时。 */
/* 超时的原因是循环尝试进制基底的次数过多。因此，注意力应放在 */
/* 如何减少尝试基底的次数。 */

/* 注意到，当基底超过a的平方根时，a必然可以表示为一个两位数。 */
/* 这时，假如a有一个不超过sqrt(a)的因数j，那么以a/j - 1为基底， */
/* a就一定可以表示为jj，从而成为回文数。如果a没有这样的因数， */
/* 则以a-1为基底，a可以表示为11。两种情况可以统一的表示，不必 */
/* 明确区分。因为a至少可以被1整除。只要从sqrt(a)一直尝试到1，就 */
/* 没有失败的情况。 */

/* 程序使用了intsqrt函数，利用sqrt - 1 < intsqrt <= sqrt，细密 */
/* 审视边界条件，防止遗漏。 */

/* 需要特殊处理a为1或2时的情况。因为以上的分析都是建立在a可以 */
/* 表示为两位数，也就是a >= 3的情况。 */


#include <stdio.h>
int isp(long long, long long);
int intsqrt(long long n);
int main(int argc, char *argv[])
{
     int n, i;
     long long a, j;
     scanf("%d", &n);

     for (i = 0; i < n; i++)
     {
     	  scanf("%lld", &a);
	  if (a < 3)
	  {
	       printf("%lld\n", a + 1);
	       continue;
	  }

     	  j = 2;
	  int sq = intsqrt(a + 1);
     	  while (!isp(a,j) && j <= sq)
     	       j++;

	  if (j > sq) /* 可以表示为两位数 */
	  {
	       for(j = sq - 1; j > 0; j--)
		    if (a % j == 0)
		    {
			 printf("%lld\n", a / j - 1);
			 break;
		    }
	  }
	  else
	       printf("%lld\n", j);

     }
     return 0;
}

int isp(long long a, long long j)
{
     long long A[34];
     int i = 0;
     while (a)
     {
	  A[i++] = a % j;
	  a /= j;
     }
     int k;
     for (k = 0; k < i - 1; k++, i--)
	  if (A[i-1] != A[k])
	       return 0;
     return 1;
}


int intsqrt(long long n)
{
     long long p, q;
	q = n / 2;
     do
     {
	  p = q;
	  q = (p + n/p)/2;
     } while (q < p);
     
     return q;
}
