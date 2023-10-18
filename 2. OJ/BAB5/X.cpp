#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int tc = 1; tc <= t; tc++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		
		long long int num;
		long long int maxChoco = 0;
		for (int i = 0; i < N; i++)
		{
			long long int max = -1;
			for (int j = 0; j < M; j++)
			{
				scanf("%lld", &num);
				if (num > max) max = num;
			}
			
			maxChoco += max;
//			printf("%lld\n", max);
		}
		
		printf("Case #%d: %lld\n", tc, maxChoco);
	}
}
