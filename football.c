#include <stdio.h>
#include <stdlib.h>

int my_rand(int abs_range);
 
int main(void)
{
   printf("Enter number of teams to play this match: ");
   int num_teams = 0;
   scanf("%d", &num_teams);
   
   int* team_scores = (int*)malloc( (((num_teams - 1) * num_teams) / 2) * sizeof(int) );
   for (int i = 0; i < ((num_teams - 1) * num_teams) / 2; i++)
    {
         team_scores[i] = my_rand(10);
    }


    for (int y = 2; y <= num_teams; y++)
    {
        for (int x = 0; x < y - 1; x++)
        {
            printf("%5d ", *(team_scores + ((y - 2) * (y - 1)) / 2 + x));
        }
        printf("\n");
    }
    free(team_scores);
}

int my_rand(int abs_range)
{
    static int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % abs_range;
}