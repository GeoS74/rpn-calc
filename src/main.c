#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "calc.h"

/*
Калькулятор с обратной записью
*/

#define MAXOP 100

int main(void){
    int type;
    double op2;
    char s[MAXOP];

    printf("RPN-Calc:\n");
    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divizor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divizor\n");
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case ANS:
                push(get_ans());
                break;
            case PRINT:
                print();
                op2 = pop();
                set_lastp(op2);
                push(op2);
                break;
            case '_':
                push(get_lastp());
                break;
            case '\n':
                op2 = pop();
                set_ans(op2);
                printf("result = %.8g\n", op2);
                break;
            default:
                printf("error: unknown command\n");
                break;
        }
    }
    return 0;
}
