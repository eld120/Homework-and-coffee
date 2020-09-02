#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
//data structure of user input

// Candidates have name, vote count, eliminated status
typedef struct
{
    char *name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
float percentage;




// Function prototypes
bool vote(int voter, int rank, char *name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);


int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;

    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("Winner: %s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {

        if (strcmp(name, candidates[i].name) == 0)
        {
            // record preference in struct
            preferences[voter][rank] = i;
            return true;
        }

    }

    return false;
}

// Tabulate votes for non-eliminated candidates
//needs to count only one vote per voter
void tabulate(void)
{

    for (int row = 0; row < voter_count; row++)
    {
        int cand = 0; //candidate
        int col = 0; //column/ preference or position
        while (cand < candidate_count)
        {
            if (cand == preferences[row][col] && candidates[cand].eliminated == true)
            {
                //if candidate.eliminated is false then take next pref
                //check next pref if eliminated
                //vote for next pref
                int m = col;
                while (candidates[(preferences[row][col])].eliminated == true && m < candidate_count)
                {

                    m++;
                    if (candidates[(preferences[row][m])].eliminated == false)
                    {
                        candidates[(preferences[row][m])].votes++;
                        break;
                    }
                }
            }
            else if (cand == preferences[row][col] && candidates[cand].eliminated == false)
            {
                candidates[cand].votes++;
                break;
            }
            cand++;
        }

    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //algorithm
    //if candidate has over 50% of the votes and then print winner


    //iterate through the list of non-eliminatee candidates
    for (int i = 0; i < candidate_count; i++)
    {
        percentage = ((float)candidates[i].votes / (float)voter_count);

        if (percentage > 0.5 && candidates[i].eliminated == false)
        {
            printf("Winner is %s\n", candidates[i].name);
            return true;
        }
        //if 50% threshold is not met return false
        //if 50% threshold is met return true
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int lowest = candidate_count;




    if (lowest > 0)
    {
        for (int i = 0; i < candidate_count; i++)
        {

            if (candidates[i].eliminated == false)
            {
                if (lowest >= candidates[i].votes)
                {
                    lowest = candidates[i].votes;

                }
            }
        }

    }



    return lowest;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int check[MAX_CANDIDATES];
    int counter = 0;
    int second = 0;
    int third = 0;
    int tied[MAX_CANDIDATES];

    //checks if all votes are equal to min
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min && candidates[j].eliminated == false)
        {
            counter++;
        }
    }

    //checks for number of non-eliminated candidates
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].eliminated == false)
        {
            second++;
        }
    }
    //returns true if a tie exists with candidates who have the min vote
    if (counter == second)
    {
        return true;
    }

    counter = 0;


    //populates list of votes greater than min that are not eliminated
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes > min)
        {
            check[i] = candidates[i].votes;
            tied[i] = candidates[i].votes;
            counter++;
        }
    }

    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter; j++)
        {
            if (check[i] == tied[j])
            {
                third++;
            }
        }
    }

    if (third == (sizeof(check) * sizeof(tied)))
    {
        return true;
    }



    return false;
}



// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}

