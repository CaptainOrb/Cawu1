#include <stdio.h>
#include <string.h>

void merge(char titles[][1001], char artists[][1001], int views[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    char tmpTitlesL[51][1001], tmpArtistsL[51][1001];
    char tmpTitlesR[51][1001], tmpArtistsR[51][1001];
    int tmpViewsL[51] = {0}, tmpViewsR[51] = {0};
    for (int i = 0; i < leftLength; i++){
        strcpy(tmpTitlesL[i], titles[start + i]);
        strcpy(tmpArtistsL[i], artists[start + i]);
        tmpViewsL[i] = views[start + i];
    }
    for (int i = 0; i < rightLength; i++){
        strcpy(tmpTitlesR[i], titles[mid + 1 + i]);
        strcpy(tmpArtistsR[i], artists[mid + 1 + i]);
        tmpViewsR[i] = views[mid + 1 + i];
    }

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (tmpViewsL[L] >= tmpViewsR[R]){
            views[index] = tmpViewsL[L];
            strcpy(titles[index], tmpTitlesL[L]);
            strcpy(artists[index], tmpArtistsL[L]);
            L++;
        }
        else{
            views[index] = tmpViewsR[R];
            strcpy(titles[index], tmpTitlesR[R]);
            strcpy(artists[index], tmpArtistsR[R]);
            R++;
        }
        index++;
    }
    while (L < leftLength){
        views[index] = tmpViewsL[L];
        strcpy(titles[index], tmpTitlesL[L]);
        strcpy(artists[index], tmpArtistsL[L]);
        L++;
        index++;
    }
    while (R < rightLength){
        views[index] = tmpViewsR[R];
        strcpy(titles[index], tmpTitlesR[R]);
        strcpy(artists[index], tmpArtistsR[R]);
        R++;
        index++;
    }
}

void mergeSort(char titles[][1001], char artists[][1001], int views[], int start, int end){
    if (start >= end) return;
    int mid = start + (end - start)/2;

    mergeSort(titles, artists, views, start, mid);
    mergeSort(titles, artists, views, mid+1, end);

    merge(titles, artists, views, start, mid, end);
}

void resort(char titles[][1001], char artists[][1001], int views[], int start, int end){
    for (int i = start; i <= end-1; i++){
        if (views[i] == views[i+1]){
            if (strcmp(titles[i], titles[i+1]) > 0){
                char tmpA[1001];
                strcpy(tmpA, titles[i]);
                strcpy(titles[i], titles[i+1]);
                strcpy(titles[i+1], tmpA);

                char tmpB[1001];
                strcpy(tmpB, artists[i]);
                strcpy(artists[i], artists[i+1]);
                strcpy(artists[i+1], tmpB);
            }
        }
    }
}

int main(){
    FILE *fptr = fopen ("testdata.in", "r"); 

    char titles[101][1001]; 
    char artists[101][1001]; 
    int views[1001];

    int index = 0;
    while (!feof(fptr)) {
        fscanf(fptr, "%[^#]#%[^#]#%d\n", titles[index], artists[index], &views[index]);
        index++;
    }
    mergeSort(titles, artists, views, 0, index-1); 
    resort(titles, artists, views, 0, index-1);

    for (int i = 0; i < index; i++) {
        printf ("%s by %s - %d\n", titles[i], artists[i], views[i]);
    }
    fclose (fptr);
}