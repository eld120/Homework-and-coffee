#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CANDIDATES 9

int voter_count = 5;
int candidate_count = 3;


typedef struct
{
    char *name;
    int votes;
    bool eliminated;
}

candidate;
candidate candidates =
{
    ["Alice";
    0;
    false;];
    ["Bob",
    0,
    false];
    ["Mark",
    0,
    false];
}


void main(candidates)
{
  int preferences[5][3] =
  {[1,0,2],
  [0,1,2],
  [2,1,0],
  [1,0,2],
  [0,1,2]
  };
  for(int i = 0; i < voter_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
            if(j == preferences[i][j])
            {
                if(candidates[j].eliminated == false)
                {
                    candidates[j].votes += 1;
                    break;
                }

            }

    }
    return;
}

main(candidates)
