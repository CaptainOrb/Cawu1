#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{ 
		int N;
		scanf("%d", &N);

		long long arr[100][100];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%lld", &arr[i][j]);
			}
		}
		
		long long res[100] = {0};
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				res[i] += arr[j][i];
			}
		}
		
		printf("Case #%d: ", tc);
		for (int i = 0; i < N; i++)
		{
			printf("%lld", res[i]);
			
			if (i < N-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
