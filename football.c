#include <stdio.h>
#include <stdlib.h>

int my_rand(int abs_range);

const int table_width = 5;
 
int main(void)
{
   printf("Enter number of teams to play this match: ");
   int num_teams = 0;
   scanf("%d", &num_teams);
   
   int* team_scores = (int*)malloc( (((num_teams - 1) * num_teams) / 2) * sizeof(int) );
   for (int i = 0; i < ((num_teams - 1) * num_teams) / 2; i++)
    {
         team_scores[i] = my_rand(5);
    }

    printf("%*s", table_width, " ");
    for (int i = 0; i < num_teams; i++)
    {
        printf ("%*d ", table_width, i + 1);
    }
    printf("\n");

    printf("%*d\n", table_width, 1);
    for (int y = 2; y <= num_teams; y++)
    {
        printf("%*d", table_width, y);
        for (int x = 0; x < y - 1; x++)
        {
            printf("%*d ", table_width, *(team_scores + ((y - 2) * (y - 1)) / 2 + x));
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
