#include <stdio.h>

int main(void)
{
    int nl = 0;
    int sp = 0;
    int tb = 0;
    int c;

    while ((c = getchar()) != EOF )
    {
        if (c == '\t')
            ++tb;
        else if (c == ' ')
            ++sp;
        else if (c == '\n')
            ++nl;
       
    }

    printf("We had %d Newlines, %d Tabs and %d Spaces.\n", nl, tb, sp);
    return 0;
}
