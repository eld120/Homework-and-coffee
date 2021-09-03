// Write a program to copy its input to its output, replacing
// each tab by \t, each backspace by \b, and each backslash by \\.
// This makes tabs and backspaces visible in an unambiguous 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){

    int c;
    int last = 0;
    char *out = malloc(256);

    while((c = getchar()) != EOF)
    {
        
        if (c == '\t')
        {
            out = "tab";
            for (int i = 0; i < strlen(out); i++)
            {
                putchar(out[i]);
            }
                
        }
        else if (c == '\b')
        {
            out = "backspace";
            for (int i = 0; i < strlen(out); i++)
            {
                putchar(out[i]);
                
            }
            
        }
        else if (c == '\\')
        {
            out = "backslash";
            for (int i = 0; i < strlen(out); i++)
            {
                putchar(out[i]);
            }
           
        }
        else{
            putchar(c);
        }
        }
    //free(out);
        printf("\n");
        return 0;
}