#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

//Definitions
#define CH_DELAY 10000
#define V_ARRAY 34
#define H_ARRAY 12
#define N_PASSWORDS 14
#define RAND_MAX 65535
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

//Functions
void setFont(int ptSz);

void slowType(int row, int col, char * string, int delay);

char ** genArray();

int printLogin(char ** array, int highy, int highx, int line, int usedelay);

int robcoLogin();