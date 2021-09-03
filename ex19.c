//Write a program to copy its input to its output, 
//replacing each string of one or more blanks by a single blank

#include <stdio.h>
#include <stdlib.h>




int main(void)
{
    int c;
    int last = 0;
    while ((c = getchar()) != EOF)
    {

        if (c == ' ' && last == ' ')
        {
            ;
        }
        else{
            putchar(c);
        }
        last = c;
    }
    printf("\n");
    return 0;
}
