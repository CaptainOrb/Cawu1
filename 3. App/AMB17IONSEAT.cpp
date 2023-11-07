#include <bits/stdc++.h>
using namespace std;

// Made by Wesley Aldrich from PPTI 17 //

// PPTI 17 DATA
int femaleStudent[15] = {1, 6, 7, 9, 10, 14, 18, 19, 20, 22, 24, 26, 29, 30, 31};
int maleStudent[20] = {2, 3, 4, 5, 8, 11, 12, 13, 15, 16, 17, 21, 23, 25, 27, 28, 32, 33, 34, 35};

// INDEX POINTERS
int femaleIndex;
int maleIndex;

void startingHeader(){
    system("cls");
    cout << "================================================" << endl;
    cout << "    AMB17ION SEAT RANDOMIZER for WARRIORS!" << endl;
    cout << "================================================" << endl;
    cout << "Tomorrow's Seat: ";
}

void generateSeat(){
    // Print empty space
    cout << endl;
    cout << endl;

    femaleIndex = 0, maleIndex = 0;

    for (int i = 0; i < 5; i++){
        // baris selain 3 dan 4 gada pulau
        if (i < 3){
            if (i == 0){
                for (int k = 0; k < 4; k++){
                    printf("\t");
                }
                for (int j = 0; j < 7; j++){
                    // kursi 6 7 harus kosong
                    if (j >= 5){
                        cout << "00";
                        printf("\t");
                        continue;
                    }
                    printf("%02d", maleStudent[maleIndex]);
                    printf("\t");
                    maleIndex++;
                }
            }
            else {
                for (int k = 0; k < 4; k++){
                    printf("\t");
                }
                for (int j = 0; j < 7; j++){
                    // kursi 6 7 harus kosong
                    if (j == 6){
                        cout << "00";
                        printf("\t");
                    }
                    else if ((j + 1) % 2 == 1){
                        printf("%02d", femaleStudent[femaleIndex]);
                        printf("\t");
                        femaleIndex++;
                    }
                    else if ((j + 1) % 2 == 0){
                        printf("%02d", maleStudent[maleIndex]);
                        printf("\t");
                        maleIndex++;
                    }
                }
            }
        }
        else { // baris yang ada pulau
            if (i == 3){
                // baris terpencil cowo
                for (int k = 0; k < 3; k++){
                    printf("%02d", maleStudent[maleIndex]);
                    printf("\t");
                    maleIndex++;
                }
                printf("\t");
            }
            else {
                // baris terpencil cewe
                for (int k = 0; k < 3; k++){
                    printf("%02d", femaleStudent[femaleIndex]);
                    printf("\t");
                    femaleIndex++;
                }
                printf("\t");
            }
            for (int j = 0; j < 8; j++){
                if (j > 5){
                    cout << "00";
                    printf("\t");
                }
                else if ((j + 1) % 2 == 1){
                    printf("%02d", femaleStudent[femaleIndex]);
                    printf("\t");
                    femaleIndex++;
                }
                else if ((j + 1) % 2 == 0){
                    printf("%02d", maleStudent[maleIndex]);
                    printf("\t");
                    maleIndex++;
                }
            }
        }
        // Move to next row
        cout << endl;
    }

    // Print empty space
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\t|[MEJA DOSEN]|\n\n\n";
}

int main(){
    srand(time(NULL));

    while (true){
        startingHeader();
        shuffle(femaleStudent, femaleStudent + 15, default_random_engine(rand()));
        shuffle(maleStudent, maleStudent + 20, default_random_engine(rand()));
        generateSeat();

        cout << "Press enter to continue..."; getchar();
    }
}