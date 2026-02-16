#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "calc.h"

/*извлекает следующий операнд или знак операции*/
int getop(char s[]) {
    int c, i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(isalpha(c)) {
        i = 0;
        while(isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if(c != EOF)
            ungetch(c);

        if(strcmp(s, "sin") == 0)
            return SIN;
        else if(strcmp(s, "cos") == 0)
            return COS;
        else if(strcmp(s, "exp") == 0)
            return EXP;
        else if(strcmp(s, "pow") == 0)
            return POW;
        else if(strcmp(s, "ans") == 0)
            return ANS;
        else if(strcmp(s, "print") == 0)
            return PRINT;
        else 
            return 0;
    }

    if(!isdigit(c) && c != '.') // не число
        return c;
    
    i = 0;
    if(isdigit(c)) // накопление целой части
        while(isdigit(s[++i] = c = getch()))
            ;
    
    if(c == '.') // накопление дробной части
        while(isdigit(s[++i] = c = getch()))
            ;
     
    s[i] = '\0';

    if(c != EOF)
        ungetch(c);

    return NUMBER;
}
