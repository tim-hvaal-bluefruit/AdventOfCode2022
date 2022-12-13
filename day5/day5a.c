// PSEUDO

// Type puzzle input rather than parse vertical stack - do that later

// string array - each string an array of max
// parse instructions - extract three variables in a loop
// function move (moves, src, dest)
    // loop 0 - moves
        // crate = last char from src before \0
        // delete last char from src before \0
        // add crate to first \0 postition of dest
// print string from last char from rows 1-9

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#define MAX_CRATES 8*9
#define STACKS 10

bool move9000(char all_crates[STACKS][MAX_CRATES], size_t moves, size_t src, size_t dest)
{
    char crate;
    size_t src_top, dest_top;

    for (int i = 0; i < moves; i++)
    {
        // get crate
        src_top = strlen(all_crates[src]) - 1;
        crate = all_crates[src][src_top];

        // remove crate
        all_crates[src][src_top] = '\0';

        // add crate
        dest_top = strlen(all_crates[dest]) - 1;
        all_crates[dest][dest_top + 1] = crate; //add crate

        // printf("stack %zu, pos %zu, crate %c\n", src, src_top, crate);
    }
    return true;
}

int main(void)
{
    printf("Advent of Code - day 5\n");

    char all_crates[STACKS][MAX_CRATES] =
    {
        "",
        "BLDTWCFM", // 1
        "NBL",      // 2
        "JCHTLV",   // 3
        "SPJW",     // 4
        "ZSCFTLR",  // 5
        "WDGBHNZ",  // 6
        "FMSPVGCN", // 7
        "WQRJFVCZ", // 8
        "RPMLH"     // 9
    };

    FILE* file = fopen("day5/input.txt", "r");
    perror("open file check");

    size_t moves = 0, from = 0, to = 0;

    char line[25] = {0};

    while(!feof(file))
    {
        fgets(line, sizeof(line), file);
        // const char* p = line;

        // useful snippet to remember... %*[^0123456789]%d 
        if (3 == sscanf(line, "%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d", &moves, &from, &to))
        {
            if (!move9000(all_crates, moves, from, to))
            {
                printf("error on line %s", line);
            }
            // printf("\nmove %d from %d to %d\n", moves, from, to);
        }
    }

    printf("STAR 1 -top crates with crane 9000: ");
    for (int i = 1; i <= STACKS; i++)
    {
        printf("%c", all_crates[i][strlen(all_crates[i]) - 1]);
    }


}


// Visualise crates
    // for (int i = 20; i >= 0; i--)
    // {
    //     for (int j = 0; j < STACKS; j++)
    //     {
    //         printf("[%c]", all_crates[j][i]);
    //     }
    //     printf("\n");
    // }