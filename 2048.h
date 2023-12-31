#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void displayGame(int *, int, int);
bool changeGame(int *, int, int *);
void generateValues(int *);
int checkGame(int *,int *,int *);
int play2048(void);

