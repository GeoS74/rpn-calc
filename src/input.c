#include<stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bp = 0; /*следующая свободная позиция буфера*/

int getch(void) {
    return bp > 0 ? buf[--bp] : getchar();
}

void ungetch(int c) {
    if(bp < BUFSIZE)
        buf[bp++] = c;
    else
        printf("error: too many characters\n");
}
