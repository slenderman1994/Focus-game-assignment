//
// Created by Asus on 28/04/2020.
//
#include<stdio.h>
#define size 8

void update_board(char myboard[size][size], int a, int b, int c){


    // updates board if you move up
    if ( c != 5 ) {
        switch (c) {
            case 1:
                myboard[a - 1][b] = myboard[a][b];
                myboard[a][b] = '0';
                printf("    0.1.2.3.4.5.6.7. \n");
                for (int i = 0; i < 8; ++i) {
                    printf("%d. ", i);
                    for (int j = 0; j < 8; ++j)

                        printf(" %c", myboard[i][j]);
                    printf("\n");
                }

                // updates board if you move down
            case 2:
                myboard[a + 1][b] = myboard[a][b];
                myboard[a][b] = '0';
                printf("    0.1.2.3.4.5.6.7. \n");
                for (int i = 0; i < 8; ++i) {
                    printf("%d. ", i);
                    for (int j = 0; j < 8; ++j)

                        printf(" %c", myboard[i][j]);
                    printf("\n");
                }
                // updates board if you move left
            case 3:
                myboard[a][b - 1] = myboard[a][b];
                myboard[a][b] = '0';
                printf("    0.1.2.3.4.5.6.7. \n");
                for (int i = 0; i < 8; ++i) {
                    printf("%d. ", i);
                    for (int j = 0; j < 8; ++j)

                        printf(" %c", myboard[i][j]);
                    printf("\n");
                }
                // updates board if you move righr
            case 4:
                myboard[a][b + 1] = myboard[a][b];
                myboard[a][b] = '0';
                printf("    0.1.2.3.4.5.6.7. \n");
                for (int i = 0; i < 8; ++i) {
                    printf("%d. ", i);
                    for (int j = 0; j < 8; ++j)

                        printf(" %c", myboard[i][j]);
                    printf("\n");
                }

        }
    }

}