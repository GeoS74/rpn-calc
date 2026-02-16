#include<stdio.h>

#define MAXVAL 100 /*максимальная глубина стека*/

double stack[MAXVAL];
int sp = 0; /*следующая свободная позиция*/

double ans = 0.0; /*последний вычисленный результат*/
double lastp = 0.0; /*последний выведенный командой print**/

void push(double n) {
    if(sp < MAXVAL) 
        stack[sp++] = n;
    else
        printf("error: stack full, can't push\n");
}

double pop(void) {
    if(sp > 0)
        return stack[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print(void) {
    if(sp > 0)
        printf("%.8g\n", stack[sp - 1]);
    else
        printf("error: stack empty\n");
}

void duplicate(void) {
    if(sp > 0)
        push(stack[sp - 1]);
    else
        printf("error: stack empty\n");
}

void swap(void) {
    if(sp - 1 > 0) {
        double f1 = pop();
        double f2 = pop();
        push(f1);
        push(f2);
    }
    else
        printf("error: not enough arguments\n");
}

void clear(void) {
    sp = 0;
}

void set_ans(double f) {
    ans = f;
}

double get_ans(void) {
    return ans;
}

void set_lastp(double f) {
    lastp = f;
}

double get_lastp(void) {
    return lastp;
}