#include <stdio.h>

/*    Chapter1.1 Hello World
main()
{
    printf("hello, world\n");
} */

/*    Chapter1.2 Fahrenheit-Celsius 
    for fahr: 0 to 300 
main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("This is a conversion table between Fahrenheit & Celsius:\n");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f,%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
} */

/*    Chapter1.3 The for Statement
main()
{
    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 20)
        printf("%3d F = %6.1f C\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
} */

/*    Chapter1.5 */
/*    copy input to output 
main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
} */
/*    count characters in input 
main()
{
    double nc;

    for (nc = 0 ; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
} */
/* Chapter1.5.2 Character Counting */
/*main()
{
    long nc;
    nc = 0;
    while (getchar() != EOF){
        ++nc;
        //printf("%d", nc);
    }
    printf("%ld",nc);
}*/


/* Chapter1.5.3 Line Counting */
/*
main()
{
    int c, nl, nb, nt;
    int c_last;
    nl = 0;
    nb = 0;
    nt = 0;
    c_last = 10000;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
            c_last = c;
        }
        else if (c == ' ') {
            if (c_last != c) {
                printf("0");
                c_last = c;
            }
            ++nb;
            c_last = c;
        }
        else if (c == '\t') {
            ++nt;
            c_last = c;
            putchar('\\');
            putchar('t');
        }
        else {
            c_last = c;
            putchar(c);
        }
    }
    printf("\nLines: %d.\nBlanks: %d.\nTabs: %d.\n", nl, nb, nt); 
} 
*/

/* Chapter1.5.4 Word Counting: Exercise1-12 
 * print one word per line from input
 */
/*
#define IN 1
#define OUT 0    

main()
{
    int c, nl, nw, nc, state, nb, nt;
    state = OUT;
    nl = 0;
    nb = 0;
    nt = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            printf("\n");
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
            putchar(c);
        }
        else {
            putchar(c);
        }
    }
    printf("\nLine: %d.\nWord: %d.\n", nl, nw);
} 
*/

/* Chapter1.7 Functions 
 * Exercise1.15 */
/*
float t_c(float f)
{
    float c;
    c = (5.0 / 9.0) * (f - 32.0);
    return c;
} 
main()
{
    float fahr;
    for (fahr = 0; fahr <= 300; fahr+=20)
        printf("%3.0f, %6.1f\n", fahr, t_c(fahr));
    return 0;
} 
*/

/*    Chapter 1.9 
#define MAXLINE 1000

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];
    max = 0;
    while ((len = getline1(line, MAXLINE)) > 0) { 
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0){
        len = getline1(line, MAXLINE);
        printf("%s", longest);
        printf("%d\n", max-1);
    }
    
    return 0;
}

int getline1(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c =='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
} */
/*      Chapter 1.9
    Exercise 1-19 */

#define MAXLINE 1000
void rev_copy(char to[], char from[]);
main()
{
    int len, max;
    char afrom[MAXLINE], ato[MAXLINE];
    while (afrom[0] != '\0') {
        rev_copy(ato, afrom);
        printf("%s\n", ato);
        printf("%c\n", ato[3]); // When output is character, it must be %c instead of %s otherwise error will be occured.
    }
    return 0;

}
void rev_copy(char to[], char from[])
{
    int i, c, a, b, d;
    c = 0;
    d = 0;
    while(to[d] != '\0' || from[d] != '\0'){
        to[d] = from[d] = '\0';
        d++;
    }
    for (i = 0; (c=getchar())!=EOF && c!='\n' && c!= '\0'; ++i)
        from[i] = c;
        a = i - 1;
    for (b = 0; b <= a ; ++b){
        to[b] = from[a-b];
    }
}    

