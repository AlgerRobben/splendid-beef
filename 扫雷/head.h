#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 30

void Initialization(char arr[ROWS][COLS], int rows, int cols, char set);
void Display(char arr[ROWS][COLS], int row, int col);
void SetMine(char arr[ROWS][COLS], int row, int col);
void FindMine(char backstage[ROWS][COLS], char clientside[ROWS][COLS], int row, int col);
int Mindcount(char backstage[ROWS][COLS],int i,int j);