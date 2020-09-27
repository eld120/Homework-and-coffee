'''#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float x = 0; //number of characters in the string
    float y = 1; // number of words in the string
    float z = 0;//number of sentences in the string
    int i;


    //get user input
    string name = get_string("Gimme ur text:\n");


    //counts characters returns number of a-z chars in string
    for(i = 0;  name[i] != '\0'; i++)
    {

        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
        {
            x++;
        }

    }


    //determines the number of words based on the presence of spaces in a string
    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            y++;
        }

    }

    //determines the number of sentences based on the presence of punctuation
    for (i = 0;  name[i] != '\0'; i++)
    {
        if (name[i] == '.' || name[i] == '!' || name[i] == '?')
        {
            z++;
        }

    }

    //determine the average number of letters per 100 words
    float l = (x / y) * 100;

    //determines the number of sentences per 100 words.
    float s = (z / y) * 100;

    // L = avg number of letters per 100 words S = avg number of sentences per 100 words
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);
    //The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text.



    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 16 && index > 1)
    {
        printf("Grade %i\n", index);
    }
}'''

chars = 0 #number of characters in the string
words = 1 #number of words in the string
sentences = 0 #number of sentences in the string
stuff = input('Gimme ur text: ')

#counts characters returns number of a-z chars in string
for i in range(len(stuff)):
    temp = stuff[i]
    if temp.isalpha() == True:
        chars += 1
    if temp == ' ':
        words += 1
    if temp == '.' or temp == '?' or temp == '!':
        sentences += 1

#determine the average number of letters per 100 words
l = (chars / words) * 100

#determines the number of sentences per 100 words.
s = (sentences / words) * 100

#L = avg number of letters per 100 words S = avg number of sentences per 100 words
index = round((0.0588 * l) - (0.296 * s) - 15.8)
#The Coleman-Liau index of a text is designed to output what (U.S.) grade 
# level is needed to understand the text.

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
elif index < 16 and index > 1:
    print("Grade " +  str(index))
    