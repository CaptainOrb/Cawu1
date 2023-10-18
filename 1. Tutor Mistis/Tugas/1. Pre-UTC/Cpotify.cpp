#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void mainMenu(char currentSong[])
{
	printf("Cpotify\n");
	printf("=======\n");
	printf("Current played song: %s\n", currentSong);
	printf("Menu:\n");
	printf("1. Queue new song\n");
	printf("2. Show all queued songs\n");
	printf("3. Play next song\n");
	printf("4. Exit\n");
}

void insertSong(char songs[][201], char singer[][201], int duration[], char songID[][201], int *queued)
{
	int length;
	do {
		printf("Song name [5-100 characters]: ");
		scanf("%[^\n]", songs[*queued]);
		getchar();
		length = strlen(songs[*queued]);
	} while (length < 5 || length > 100);
	do {
		printf("Singer name [not empty]: ");
		scanf("%[^\n]", singer[*queued]);
		getchar();
	} while (strlen(singer[*queued]) == 0);
	do {
		printf("Song duration [positive number, in seconds]: ");
		scanf("%d", &duration[*queued]);
		getchar();
	} while (duration[*queued] < 1);
	
	char id[31];
	bool valid = true;
	do {
		sprintf(id, "SNG-%d-%03d", duration[*queued], rand() % 1000);
		
		int i;
		valid = true;
		for (i = 0; i < *queued; i++)
		{
			if (strcmp(songID[i], id) == 0)
			{
				valid = false;
			}
		}
	} while (!valid);
	
	strcpy(songID[*queued], id);
	(*queued)++;

	getchar();
}

void showSong(char songs[][201], char singer[][201], int duration[], char songID[][201], int *queued)
{
	if (*queued == 0)
	{
		puts("No queued song...");
		getchar();
		return;
	}
	int i;
	for (i = 0; i < *queued; i++)
	{
		char tmp[15];
		sprintf(tmp, "%02d:%02d:%02d", duration[i]/3600, duration[i]/60 % 60, duration[i]%60);
		
		printf("Song ID: %s\n", songID[i]);
		printf("Song Name: %s\n", songs[i]);
		printf("Singer Name: %s\n", singer[i]);
		printf("Song Duration: %s\n\n", tmp);
	}
	
	getchar();
}

void nextSong(char songs[][201], char singer[][201], int duration[], char songID[][201], int *queued, char currentSong[201])
{
	if (*queued == 0)
	{
		strcpy(currentSong, "-");
		return;
	}

	char tmp[15];
	sprintf(tmp, "%02d:%02d:%02d", duration[0]/3600, duration[0]/60 % 60, duration[0]%60);
	sprintf(currentSong, "[%s] %s - %s (%s)", songID[0], songs[0], singer[0], tmp);
	
	int i;
	for (i = 0; i < (*queued) - 1; i++)
	{
		strcpy(songs[i], songs[i+1]);
	}
	
	(*queued)--;
}

int main()
{
	srand(time(NULL));
	// var
	char currentSong[201] = "-";
	char songs[119][201], singer[119][201];
	int duration[201];
	char songID[119][201];
	int queued = 0;

	int userInput;
	do {
		system("cls");
		mainMenu(currentSong);
		printf(">> ");
		scanf("%d", &userInput);
		getchar();
		
		if (userInput == 1)
		{
			insertSong(songs, singer, duration, songID, &queued);
		}
		else if (userInput == 2)
		{
			showSong(songs, singer, duration, songID, &queued);
		}
		else if (userInput == 3)
		{
			nextSong(songs, singer, duration, songID, &queued, currentSong);
		}
	} while (userInput != 4);
}
