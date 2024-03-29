/*
Airport Authority

Constraints:

1 <= N <= 10^5
1 <= weights[i] <= 10^5
1 <= T <= 10^5
Input Format for Custom Testing:

The first line contains an integer, N, denoting the number of luggage.
Each line i of the N subsequent lines (where 0 <= i <n) contains an integer describing the weight of ith luggage.
The next line contains an integer, T, denoting the threshold weight of the boundary wall.
Sample Cases:

Sample Input 1
4
1
2
3
4
3
Sample Output 1
5

*/

#include <stdio.h>
long int weightMachine(long int N, long int weights[], long int T)
{
    long int amount = 0, i;
    for (i = 0; i < N; i++)
    {
        amount++;
        if (weights[i] > T)
        {
            amount++;
        }
    }
    return amount;
}
int main()
{
    long int N, i, T;
    scanf("%ld", &N);
    long int weights[N];
    for (i = 0; i < N; i++)
    {
        scanf("%ld", &weights[i]);
    }
    scanf("%ld", &T);
    printf("%ld", weightMachine(N, weights, T));
    return 0;
}