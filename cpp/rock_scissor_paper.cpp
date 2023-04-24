#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genrand_num(int n)
{
    srand(time(NULL)); //srand takes seed as an input and is defined inside stdlib.h
    return rand() % n;
}
int greater(char c1, char c2)
{
    //For rock,paper,scissors- return 1 if c1>c2 and 0 otherwise.if c1==c2 it will return -1.
    if (c1 == c2)
    {
        return 1;
    }
    else if ((c1 == 'r') && (c2 == 's'))
    {
        return 1;
    }
    else if ((c2 == 'r') && (c1 == 's'))
    {
        return 0;
    }
    else if ((c1 == 'p') && (c2 == 'r'))
    {
        return 1;
    }
    else if ((c2 == 'p') && (c1 == 'r'))
    {
        return 0;
    }
    else if ((c1 == 's') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c2 == 's') && (c1 == 'p'))
    {
        return 0;
    }
}
int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("Welcome to the Rock, Paper, Scissors.\n");
    for (int i = 0; i < 3; i++)
    {
        //Take plsyer 1's input
        printf("Player 1's Turn:\n");
        printf("Choose 1 for Rock, 2 for paper and 3 for Scissors\n");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];
        printf("You choosed %c\n\n", playerChar);

        //Generate Computer's input
        printf("Computer's Turn:\n");
        printf("Choose 1 for Rock, 2 for paper and 3 for Scissors\n");
        temp = genrand_num(3) + 1;
        compChar = dict[temp - 1];
        printf("CPU choosed %c\n\n", compChar);

        //Compare the scores
        if (greater(compChar, playerChar) == 1)
        {
            compScore += 1;
            printf("CPU got it.\n");
        }
        else if (greater(compScore, playerChar) == -1)
        {
            compScore += 1;
            playerScore += 1;
            printf("It's a DRAW.\n");
        }
        else
        {
            playerScore += 1;
            printf("You got it.\n");
        }
        printf("YOU: %d \t CPU: %d\n\n", playerScore, compScore);
    }
    if (playerScore > compScore)
        printf("You are the WINNER\n");
    else if (playerScore < compScore)
        printf("CPU is the WINNER.\n");
    else
        printf("Match is DRAW.\n");
    return 0;
}
