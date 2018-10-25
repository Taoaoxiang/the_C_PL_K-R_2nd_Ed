#include <stdio.h>
#include <string.h>

/* TEST
main(){
    char msg[] = "hahaha???";
    printf("%s\n", (msg));	// Ok
    printf("%d\n", strlen(msg));	// Ok
    printf("%c\n", msg[0]); 	// Ok

}
*/
/*    Chapter2.7 
 *   Exercise 2-3 
 */
/*
#define MAXLINE 1000
long long int conv_hex2int(char hx[], int maxline);

main()
{
    long long int c;
    unsigned long long int a;
    char c_hex[MAXLINE];
    printf("Type your hexadecimal number here. \n");
    printf("Example:0x123456789abcdef, or 0X123456789ABCDEF. case insensitive.\n");
    printf("Maximum hexadecimal number is 7fffffffffffffff!!!\n");
    while ((a = conv_hex2int(c_hex, MAXLINE)) > 0 ) {
        //printf("\a"); // This beep sound really varies, depending on your machine and operation system.
        printf("[Hexa] %s = [Int] %llu.\n", c_hex, a);
    }
} 

long long int conv_hex2int(char hx[], int lim)
{
    unsigned long long int i, c, m;
    unsigned long long int n;
    m = n = 0;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c!='\n' ; ++i ){
        hx[i] = c ;
        m = i;
    }
    if (c == '\n') {
        hx[i] = '\0';
    }
    if (hx[0]=='0' && (hx[1]=='x' || hx[1]=='X')){
        for (i = 2; i <= m; i++){
            if (hx[i] >= '0' && hx[i] <= '9'){
                n = 16 * n + (hx[i] - '0');
                printf("hx[%d] = %c, n = %llu\n", i, hx[i], n);
            }
            else if (hx[i] >= 'A' && hx[i] <= 'F'){
                n = 16 * n + (hx[i] - 'A' + 10);
                printf("hx[%d] = %c, n = %llu\n", i, hx[i], n);
            }
            else if (hx[i] >= 'a' && hx[i] <= 'f'){
                n = 16 * n + (hx[i] - 'a' + 10);
                printf("hx[%d] = %c, n = %llu\n", i, hx[i], n);
            }
        }
    }
    return n;
} 
*/
/*    Chapter2.8
 *   Exercise 2-4 and 2-5
*/
/*
void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);

main()
{
    int i, a, b;
    char m1[] = "1234abcdefghijklmn";
    char m2[] = "bck000003";
    printf("Initial:\t %s\n", m1);
    printf("Match: %s\n", m2);
    a = any(m1, m2);
    printf("First location is: %d\n", a);
    squeeze(m1, m2);
    printf("After:  \t %s\n", m1);

    

}

int any(char s1[], char s2[])
{
    int i, j, a, b;
    j = 30000;
    for (a = 0; s2[a] != '\0'; ++a) {
        for (i = 0; s1[i] != '\0'; i++) {
            if (s1[i] == s2[a]) {
                if (j > (i + 1)) {
                    j = i + 1;
                }
            }
        }
    }
    return j;
}

void squeeze(char s1[], char s2[])
{
    int i, j, a;
    for (a = 0; s2[a] != '\0'; ++a){
        for (i = j = 0; s1[i] != '\0'; i++){
            if (s1[i] != s2[a])
                s1[j++] = s1[i];
        }
        s1[j] = '\0';
    }
} 
*/
/* Chapter2.9
 * Exercise 2-6 
 */
unsigned setbits(unsigned x, int p, int n, unsigned y);
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 16; i > 0; i = i / 2){
        //printf("%d\n",i);
        (n & i)? printf("1"): printf("0");
    }
}

main()
{
    printf("Warning: maximum n = p + 1!!!\n");
    printf("11 = \n");
    bin(11);
    printf("\n");
    printf("592 = \n");
    bin(592);
    printf("\n");
    printf("6 = \n");
    bin(6);
    printf("\n");
    printf("setbits(2044, 8, 9, 592) -> %u\n", setbits(2044, 8, 9, 592));
    printf("setbits(2044, 6, 1, 592) -> %u\n", setbits(2044, 6, 1, 592));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned int a1, a2, a3, b ;
    a1 = a2 = a3 = 0;
    if (p + 1 - n > 0) {
        a3 = x & ~(~0 << (p - n + 1));
        printf("a3 = %u\n", a3);
        a2 = y & ~(~0 << n);
        printf("a2 = %u\n", a2);
        a1 = x >> (p + 1 );
        printf("a1 = %u\n", a1);
        b = (a1 << (p + 1 )) | (a2 << (p + 1 - n)) | a3 ;
    }
    else if (p + 1 - n == 0 ) {
        a2 = y & ~(~0 << n);
        printf("a2 = %u\n", a2);
        a1 = x >> (p + 1 );
        printf("a1 = %u\n", a1);
        b = (a1 << (p + 1 )) | (a2 << (p + 1 - n));
    }
    return b;
} 

