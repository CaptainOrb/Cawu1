#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[69];
	scanf("%[^\n]", str);
	getchar();
	char str2[69];
	scanf("%[^\n]", str2);
	getchar();
	
	do {
		printf("str = %s\n", str);
		printf("str2 = %s\n", str2);
		printf("1. strcat()\n");
		printf("2. strncat()\n");
		printf("3. strcpy()\n");
		printf("4. strncpy()\n");
		printf("5. strstr()\n");
		int in;
		scanf("%d", &in);
		getchar();
		
		if (in == 1)
		{
			strcat(str, str2);
			printf("%s\n", str);
			getchar();
			system("cls");
		}
		if (in == 2)
		{
			strncat(str, str2, 1);
			printf("%s\n", str);
			getchar();
			system("cls");
		}
		if (in == 3)
		{
			strcpy(str, str2);
			printf("%s\n", str);
			getchar();
			system("cls");
		}
		if (in == 4)
		{
			strncpy(str, str2, 1);
			printf("%s\n", str);
			getchar();
			system("cls");
		}
		
	} while (true);
}
