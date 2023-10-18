#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int players[101] = {0};
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int person;
			scanf("%d", &person);
			players[person]++;
		}
	}
	
	int incomplete = 0;
	for (int i = 1; i <= N; i++)
	{
		if (players[i] < N)
		{
			incomplete++;
		}
	}
	
	printf("%d\n", incomplete);
}
