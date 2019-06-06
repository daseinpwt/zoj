#include<stdio.h>
#include<string.h>
 
int main()
{
	int T, flag[200];
	scanf("%d", &T);
	while (T--)
	{
		int i, n, s, t, temp;
		scanf("%d", &n);
		memset(flag, 0, sizeof(flag));
		while (n--)
		{
			scanf("%d %d", &s, &t);
			s = s % 2 ? (s - 1) / 2 : (s - 2) / 2;
			t = t % 2 ? (t - 1) / 2 : (t - 2) / 2;
			if (s > t)
			{
				temp = s;
				s = t;
				t = temp;
			}
			for (i = s; i <= t; i++)
				flag[i]++;
		}
		int max = 1;
		for (i = 0; i < 200; i++)
			if (flag[i] > max)
				max = flag[i];
		printf("%d\n", max * 10);
	}
	return 0;
}