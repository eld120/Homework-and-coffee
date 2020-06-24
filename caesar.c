#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int key;
int j;
int i;
int k;
int temp;
char cipher[300];
string str;
string plainTxt;

//determine that the correct arguments are passed throught he main function
int main(int argc, string argv[1])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else if (argv[1] <= 0)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    str = argv[1];

    for (k = 0; str[k]; k++)
    {
        if (isdigit(str[k]))
        {


        }
        else
        {
            printf("Please use an integar as a key!\n");
            return 1;
        }
    }
    {
        plainTxt = get_string("Plain text: ");
    }


    key = atoi(argv[1]);

    //cipertext generation
    for (i = 0; plainTxt[i] != '\0'; i++)
    {
        if (plainTxt[i] >= 'a' && plainTxt[i] <= 'z')
        {
            temp = (plainTxt[i] + key - 97) % 26;
            cipher[i] = temp + 97;
            //printf("%i" , cipher[i]);
        }
        else if (plainTxt[i] >= 'A' && plainTxt[i] <= 'Z')
        {
            temp = (plainTxt[i] + key - 65) % 26;
            cipher[i] = temp + 65;
            //printf("%i" , cipher[i]);
        }
        else
        {
            cipher[i] = plainTxt[i] + 0;
            printf("%i", plainTxt[i]);
        }

    }

    printf("ciphertext: %s\n", cipher);
    return 0;


}