#ifndef CALC_H
#define CALC_H

enum SPEC {
    NUMBER='0',
    SIN, 
    COS, 
    EXP, 
    POW, 
    ANS, 
    PRINT
};

int getch(void);
void ungetch(int);
int getop(char s[]);
void push(double);
double pop(void);
void print(void);
void set_ans(double);
double get_ans(void);
void set_lastp(double);
double get_lastp(void);

#endif