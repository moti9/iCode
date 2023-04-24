#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{ int n,guess,nguesses=1;
srand(time(0));
n=rand()%100 +1;
    do{
        printf("Guess the number between 1 to 100: ");
        scanf("%d",&guess);
        if(guess<n)
        printf("\nHigher Number Please!\n");
        else if(guess>n)
        printf("\nLower Number Please!\n");
        else 
        printf("You guess it in %d attempts.\n",nguesses);
        nguesses++;
    }while(guess!=n);

    return 0;
}

