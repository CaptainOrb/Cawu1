#include <stdio.h>
#include <string.h>

typedef struct city {
    char name[1001];
    double temperature;
    char metric;
}city;

double toCelcius(city data){
    if (data.metric == 'C') return data.temperature;
    double ret = (data.temperature - 32) * 5 / 9;
    return ret;
}

void merge(city data[], int start, int mid, int end){
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    city tmpL[50], tmpR[50];
    for (int i = 0; i < leftLength; i++) tmpL[i] = data[start+i];
    for (int i = 0; i < rightLength; i++) tmpR[i] = data[mid+1+i];

    int L = 0, R = 0, index = start;
    while (L < leftLength && R < rightLength){
        if (toCelcius(tmpL[L]) < toCelcius(tmpR[R])){
            data[index++] = tmpL[L++];
        }
        else if (toCelcius(tmpL[L]) == toCelcius(tmpR[R])){
            if (strcmp(tmpL[L].name, tmpR[R].name) > 0){
                data[index++] = tmpR[R++];
            }
            else {
                data[index++] = tmpL[L++];
            }
        }
        else {
            data[index++] = tmpR[R++];
        }
    }
    while (L < leftLength) data[index++] = tmpL[L++];
    while (R < rightLength) data[index++] = tmpR[R++];
}

void mergeSort(city data[], int start, int end){
    if (start >= end) return;

    int mid = start + (end - start)/2;
    mergeSort(data, start, mid);
    mergeSort(data, mid+1, end);

    merge(data, start, mid, end);
}

int main(){
    FILE *fptr = fopen("testdata.in", "r");
    // FILE *fptr = fopen("testDataE.txt", "r");

    city data[100];
    int index = 0;
    while (!feof(fptr)){
        fscanf(fptr, "%[^#]#%lf#%c\n",
            data[index].name, &data[index].temperature, &data[index].metric);
        index++;
    }

    mergeSort(data, 0, index-1);

    for (int i = 0; i < index; i++){
        printf("%s is %.2lf%c\n",
            data[i].name, data[i].temperature, data[i].metric);
    }
    fclose(fptr);
}