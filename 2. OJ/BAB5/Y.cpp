#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		char str[1001];
		scanf("%d %[^\n]", &N, str);
		getchar();
		
		for (int i = 0; i < N; i++)
		{
			int start, end;
			scanf("%d %d", &start, &end);
			getchar();
			
			start--;
			end--;
			
			while (start < end)
			{
				char tmp = str[start];
				str[start] = str[end];
				str[end] = tmp;
				
				start++;
				end--;
			}
		}
		
		printf("Case #%d: %s\n", tc, str);
	}
}
