#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/* 5.10 Command-line Arguments */
/* echo command-line arguments; 1st version */
/*
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        printf("%s", " ");
    }
    // the expression in the for loop is the same as the expression below.
    //    printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");
    return 0;
}
*/

/* echo command-line arguments; 2nd version */
/*
main(int argc, char *argv[])
{
    printf("%s\n", *(argv+0));
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}
*/

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

main11()
{
    int x = 1;
    int i;
    int *ip;
    int a[3];
    char as[10] = "abc";
    char *p;
    p = as;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    char *pp[1000];
/* ip = &x;
    printf("*ip = %d\n", *ip);
    printf("ip = %d\n", ip);
    printf("&x = %d\n", &x);
*/
/*    printf("&p = %d, p = %d, *p = %d \n", &p, p, *p);
    printf("&as = %d, &as[0] = %d,\n", &as, &as[0]);
    printf("as = %s, as[0] = %d,\n", as, as[0]);
    //printf("pp[0] = %c, \n",pp[0]);
    ip = a;
*/
/*
    for (i = 0; i <= 5; ++i)
    {
        printf("i = %d,\t&a[i] = %d\n", i, &a[i]);
        printf("i = %d,\tip + i = %d\n", i, ip + i);
        printf("i = %d,\ta[i] = %d\n", i, a[i]);
        printf("i = %d,\t*(ip + i) = %d\n", i, *(ip + i));
    }
    printf("ip");
*/
    char *name[] = {
        "Illegal month",
        "Ganuary", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    //printf("name = %d\n", name);
    printf("name[0][1] = %p\n", name[0][1]);
    printf("name = %p, *name = %p, name[0] = %p, &name[0] = %p, &name[0][0] = %p\n", name, *name, name[0], &name[0],&name[0][0]);
    printf("name = %lu, *name = %d", name, *name);
    printf("\n\n\n");


    printf("name+1 = %p, *(name+1) = %p, name[0]+1 = %p, &name[0][0]+1 = %p\n", name+1, *(name+1), name[0]+1, &name[0][0]+1);
    printf("*(name+1) = %p, *name+1 = %p, name[1] = %p\n", *(name+1),*name+1, name[1]);
    printf("name = %d, &name = %d, &name[0] = %d\n", name, &name, &name[0]);
    printf("name = %p, &name = %d, &name[0] = %d\n", name, &name, &name[0]);
    printf("name+1 = %d, &(name+1) = NotDoable, &name+1 = %d, &name[0]+1 = %d\n", name+1, &name+1, &name[0]+1);
    printf("(*name)[0] = %c, *(name[0]) = %c\n", (*name)[0], *(name[0]));
    printf("*name[0] = %c, name[0] = %c, *name = %c\n", *name[0], name[0], *name);
    printf("*name[0] = %c, name[0] = %s, *name = %s\n", *name[0], name[0], *name);
    printf("*(name[0]+1) = %c, name[0]+1 = %s, *(name+1) = %s\n", *(name[0]+1), name[0]+1, *(name+1));
    printf("*(name+1) = %s, &(name+1) = NotDoable, *(&name+1) = %c, *(&name[0]+1)[0] = %c\n", *(name+1), *(&name+1), *(&name[0]+1)[0]);

}
