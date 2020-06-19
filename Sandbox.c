#include <stdio.h>
#include <stdlib.h>


    int guess;
    int secretNumber = 4;
    int outOfGuesses = 3;
    int guessNo = 0;

int main ()
{
   
    while (guess != secretNumber && guessNo < outOfGuesses)
    {
        printf("Guess a number: \n");
        scanf("%i", &guess);
        guessNo++;
    }

    printf("Winning!\n");
    return 0;

}