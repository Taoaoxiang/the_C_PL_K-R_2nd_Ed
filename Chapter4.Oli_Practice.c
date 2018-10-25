#include <stdio.h>
#include <string.h>

double atof1 (char s[]);
double mul1 (int a, int si);
main(){
    char s1[] = "-123.45e-8";
    //char s1[] = "    123.45";
    printf("String: %s\n", s1); 
    printf("Float:  %.4e\n",atof1(s1));
}

double atof1 (char s[]){
    int i, sign, sig;
    sign = sig = 1;
    double sum0, sum1, sum2, power1, power2;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        i++;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    for (sum1 = 0.0; isdigit(s[i]); i++)
        sum1 = 10.0 * sum1 + (s[i] - '0');
    if (s[i] == '.') {
        i++;
        for (power1 = 1.0; isdigit(s[i]); i++) {
            sum1 = 10.0 * sum1 + (s[i] - '0');
            power1 *= 10;
        }
        sum1 = sum1/power1;
    }
    if (s[i] == 'e' || s[i] == 'E' ) {
        i++;
        if (s[i] == '+' || s[i] == '-') {
            sig = (s[i] == '-') ? -1 : 1;
            i++;
        }
        for (sum2 = 0.0; isdigit(s[i]); i++)
            sum2 = 10.0 * sum2 + (s[i] - '0');
        sum1 *= mul1(sum2, sig);
    }
    return (double) sum1*sign;
}

double mul1 (int a, int si){
    double b = 1.0;
    int i = 1;
    for (i=1; i<=a; i++){
        b *= 10;
    }
    if (si == -1){
        b = 1/b;
    }
    return b;
}

