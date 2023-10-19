#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	
	for (int tc = 1; tc <= t; tc++)
	{
		char str[1001];
		scanf("%[^\n]", str);
		getchar();
		
		int len = strlen(str);
		
		int N;
		scanf("%d", &N);
		getchar();
		for (int i = 0; i < N; i++)
		{
			char init, changed;
			scanf("%c %c", &init, &changed);
			getchar();
			
			for (int j = 0; j < len; j++)
			{
				if (str[j] == init) str[j] = changed;
			}
		}
		printf("Case #%d: %s\n", tc, str);
	}
}
