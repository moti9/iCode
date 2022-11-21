#include <stdio.h>
int main() {
    int n, revNum = 0, remd, orgNum;
    printf("Enter an integer: ");
    scanf("%d", &n);
    orgNum = n;

     
    while (n != 0) {
        remd = n % 10;
        revNum = revNum * 10 + remd;
        n /= 10;
    }

    
    if (orgNum == revNum)
        printf("%d is a palindrome.", orgNum);
    else
        printf("%d is not a palindrome.", orgNum);
printf("\n***************************************\n");
    return main();
}
