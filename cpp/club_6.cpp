#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n, val;
    scanf("%d %d", &n, &val);
    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            count++;
            a[i] = 0;
        }

        else
        {
            printf("%d\t", a[i]);
        }
    }
    printf("No = %d\n", count);

    return 0;
}
