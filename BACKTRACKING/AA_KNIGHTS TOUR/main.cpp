/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on March 26, 2025, 7:02 PM
 */

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define N 8

bool knightCanJump(int matrix[N][N], int rows, int columns) {
    return (rows >= 0 && rows < N &&
            columns >= 0 && columns < N &&
            matrix[rows][columns] == 0);
}

bool knightTour(int matrix[N][N], int movements[8][2], int rows, int columns, int number) {
    if (number == N * N) {
        return true;
    }
    for (int i = 0; i < 8; i++) {
        int newRow = rows + movements[i][0];
        int newCol = columns + movements[i][1];
        if (knightCanJump(matrix, newRow, newCol)) {
            matrix[newRow][newCol] = number + 1;
            if (knightTour(matrix, movements, newRow, newCol, number + 1)) return true;
            matrix[newRow][newCol] = 0;
        }
    }
    return false;
}

int main() {
    int matrix[N][N] = {0};
    int movements[8][2] = {
        {2, 1},
        {2, -1},
        {-1, 2},
        {1, 2},
        {-1, -2},
        {1, -2},
        {-2, 1},
        {-2, -1}
    };

    matrix[0][0] = 1;
    knightTour(matrix, movements, 0, 0, 1);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
