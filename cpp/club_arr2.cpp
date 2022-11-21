#include <stdio.h>

int main()
{
    int n = 7, i = 0, j = 6, sum = 0, a[7] = {1, 5, 8, 11, 14, 17, 19};
    scanf("%d", &sum);

    while (i < n & j >=i)
    {
        if (a[i] + a[j] == sum)
        {
            printf("(%d,%d)", a[i], a[j]);
            i++;
        }
        else if (a[i] + a[j] > sum)
        {
            j--;
        }
        else if (a[i] + a[j] < sum)
        {
            i++;
            j++;
        }
    }

    return main();
}
