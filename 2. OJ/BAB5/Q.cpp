#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++)
	{
		int friends, rooms, visitors;
		scanf("%d %d %d", &friends, &rooms, &visitors);
		
		int pattern[50][50];
		for (int i = 0; i < friends; i++)
		{
			for (int j = 0; j < rooms; j++)
			{
				scanf("%d", &pattern[i][j]);
			}
		}
		
		int room[50] = {0};
		for (int i = 0; i < visitors; i++)
		{
			int visit;
			scanf("%d", &visit);
			
			for (int j = 0; j < rooms; j++)
			{
				room[j] += pattern[visit-1][j];
			}
		}
		
//		for (int j = 0; j < rooms; j++)
//		{
//			printf("%d ", room[j]);
//		}
		
		printf("Case #%d:\n", tc);
		for (int i = 0; i < rooms; i++)
		{
			if (room[i] % 2 == 1)
			{
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
}
