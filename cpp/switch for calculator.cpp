#include <stdio.h>
int main(void) {
    char choice;
    double a,b;
    printf("Enter a chaice (+, -, * ,/ ): ");
    scanf("%c", &choice);
    printf("Type No1: ");
    scanf("%lf", &a);
    printf("Type No2: ");
    scanf("%lf", &b);

    switch (choice) {
    case '+':
        printf("%.1lf + %.1lf = %.1lf", a, b, a+b);
        break;
    case '-':
        printf("%.1lf - %.1lf = %.1lf",a,b,a-b);
        break;
    case '*':
        printf("%.1lf * %.1lf = %.1lf", a,b,a*b);
        break;
    case '/':
        printf("%.1lf / %.1lf = %.1lf",a,b,a/b);
        break;
        
    default:
        printf("Error! choice is not correct");
    }
}
