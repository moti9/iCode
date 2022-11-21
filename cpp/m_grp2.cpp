#include <stdio.h>
int main() {
    int i, n, k1 = 1, k2 = 2, NT;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        printf("%d", k1);
        if( i<n)
        printf("+");
        
        NT= k1 + k2;
        k1 = k2;
        k2 = NT;
    }

    return 0;
}

