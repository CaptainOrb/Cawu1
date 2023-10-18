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
		int outputArr[1000];
		for (int i = 0; i < len; i++)
		{
			char tmp;
			if (str[i] >= 'A' && str[i] <= 'D')
			{
				tmp = 'A';
			}
			else if (str[i] >= 'E' && str[i] <= 'H')
			{
				tmp = 'E';
			}
			else if (str[i] >= 'I' && str[i] <= 'N')
			{
				tmp = 'I';
			}
			else if (str[i] >= 'O' && str[i] <= 'T')
			{
				tmp = 'O';
			}
			else if (str[i] >= 'U' && str[i] <= 'Z')
			{
				tmp = 'U';
			}
			
			outputArr[i] = str[i] - tmp;
			str[i] = tmp;
		}
		
		printf("Case #%d:\n", tc);
		printf("%s\n", str);
		for (int i = 0; i < len; i++)
			printf("%d", outputArr[i]);
		printf("\n");
	}
}
