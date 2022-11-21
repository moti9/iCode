/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(void)
{
    int speed;
    printf("\n Enter your speed as an integer: ");
    scanf("%d",& speed);
    
    speed= ( speed<=65)? (65) : (speed<=70) ? (70): (90);
    switch(speed)
    {
        case 65: printf("\n No speeding Ticket\n\n"); break;
        case 70: printf("\n Speeding Ticket: \n\n"); break;
        case 90: printf("\n Expensive Speeding\n\n"); break;
        degault: printf("\n Incorrect Speed\n\n"); //unneeded
    }
}
