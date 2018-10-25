#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Exercise 5-10 *
 * This is my version of Reverse Polish Notation
 * Kind of crappy, but works
 */
main(int argc, char *argv[])
{
    /* Copy *argv[] to *cp_argv[] */
    int i, cp_argc;
    cp_argc = argc;
    double OP1, OP2, TOT;
    char *cp_argv[argc];
    double a_st[1000];
    double *ar_st;
    ar_st = a_st;
    for (i = 0; i < cp_argc; i++) {
        cp_argv[i] = malloc(sizeof(argv[i]));
        strcpy(cp_argv[i], argv[i]);
    }
    /* Using pointer **pp point to *cp_argv[] */
    char **pp;
    pp = cp_argv;
    while (--cp_argc > 0){
        /*printf("%d\n", cp_argc);
        printf("%s\n", *++pp);*/
        *++pp;
        if (strlen(*pp)>1){
            TOT = atof(*pp);
            *ar_st++ = TOT;
        } else if (strlen(*pp)==1 && isdigit(**pp)) {
            TOT = atof(*pp);
            *ar_st++ = TOT;
        } else if (strlen(*pp)==1) {
            switch(**pp) {
                case '+':
                    OP2 = *--ar_st;
                    OP1 = *--ar_st;
                    TOT = OP1 + OP2;
                    *ar_st++ = TOT;
                    break;
                case '-':
                    OP2 = *--ar_st;
                    OP1 = *--ar_st;
                    TOT = OP1 - OP2;
                    *ar_st++ = TOT;
                    break;
                case '*':
                    OP2 = *--ar_st;
                    OP1 = *--ar_st;
                    TOT = OP1 * OP2;
                    *ar_st++ = TOT;
                    break;
                case '/':
                    OP2 = *--ar_st;
                    OP1 = *--ar_st;
                    TOT = OP1 / OP2;
                    *ar_st++ = TOT;
                    break;
                default:
                    printf("ERROR: not operator\n");
                    break;
            }
        }
        //printf("Result: %.8f\n", TOT);
    }
    printf("Result: %.8f\n", *--ar_st);
    return 0;
}
