#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct candidates
{
    string name;
    int votes;
}
candidate;
candidate candidates[MAX]; // Array of candidates
int candidate_count; // Number of candidates
string name;
int i;

// Function prototypes
bool vote(string name);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (i = 0; i < voter_count; i++)
    {
        name = get_string("Vote: ");
       printf("%s", candidates[0].name);
       printf("%i\n", candidates[0].votes);
       printf("%s", candidates[1].name);
       printf("%i\n", candidates[1].votes);
       printf("%i", candidates[2].votes);
        printf("%s\n", candidates[2].name);
        printf("%s", name);
        // Check for invalid vote
       // if (vote(name) == false)
       // {
       //     printf("Invalid vote.\n");
       // }
        for (int k = 0; k <= candidate_count; k++)
        {
            if (candidates[k].name == name)
                {
                    candidates[k].votes = candidates[k].votes + 1;
                }
        }



    }

    // Display winner of election
   // print_winner();
}
 // Update vote totals given a new vote
bool vote()
{



    for (i = 0; i <= candidate_count; i++)
        {
            if (name == candidates[i].name)
            {

                return true;
            }

        }
        return false;


}
    // Print the winner (or winners) of the election
void print_winner(void)
    {
        for (i = 0; i == candidate_count; i++)
            if(candidates[i].votes)
            {

            }
       // return;
    }





