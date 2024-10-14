//Name: Daniel Harris
//Matrix Manipulation

#include <stdio.h>

#define SIZE 5

//function inits
void add(int m1[SIZE][SIZE],int m2[SIZE][SIZE]);
void mult(int m1[SIZE][SIZE],int m2[SIZE][SIZE]);
void transpose(int m1[SIZE][SIZE],int m2[SIZE][SIZE]);
void print(int m1[SIZE][SIZE],int m2[SIZE][SIZE]);

int main() {
    int option = 0;

    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    printf("What would you like to do? (1-add, 2-multiply, 3-transpose, 4-print): ");
    scanf("%d", &option);

    if (option == 1) {

    }
}

void add(int m1[SIZE][SIZE],int m2[SIZE][SIZE]) {
    int m3;

}

void mult(int m1[SIZE][SIZE],int m2[SIZE][SIZE]) {
    int m3;

}

void transpose(int m1[SIZE][SIZE],int m2[SIZE][SIZE]) {
        int option;
    printf("Which matrix would you like to transpose?: ");
    scanf("%d", &option);
    if (option == 1) {
        for (int i = 0; i < SIZE; i++) {
            printf("\n");
            for (int j = 0; j < SIZE; j++) {
                printf("%d\t", m1[i][j]);
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            printf("\n");
            for (int j = 0; j < SIZE; j++) {
                printf("%d\t", m2[j][i]);
            }
        }
    }

}

void print(int m1[SIZE][SIZE],int m2[SIZE][SIZE]) {
    int option;
    printf("Which matrix would you like to print?: ");
    scanf("%d", &option);
    if (option == 1) {
        for (int i = 0; i < SIZE; i++) {
            printf("\n");
            for (int j = 0; j < SIZE; j++) {
                printf("%d\t", m1[i][j]);
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            printf("\n");
            for (int j = 0; j < SIZE; j++) {
                printf("%d\t", m2[i][j]);
            }
        }
    }

}