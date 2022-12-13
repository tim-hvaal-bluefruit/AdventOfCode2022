#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#define MAX_CRATES 8*9
#define STACKS 10

char all_crates[STACKS][MAX_CRATES] =
{
    "",
    "BLDTWCFM", // 1
    "NBL",
    "JCHTLV",
    "SPJW",
    "ZSCFTLR",
    "WDGBHNZ",
    "FMSPVGCN",
    "WQRJFVCZ",
    "RPMLH"     // 9
};

void move9001(size_t to_move, size_t src, size_t dest);

int main(void)
{
    printf("Advent of Code - day 5\n");
    FILE* file = fopen("day5/input.txt", "r");
    perror("open file check");

    size_t to_move = 0, from = 0, to = 0;
    char line[25] = {0};

    while(!feof(file))
    {
        fgets(line, sizeof(line), file);
        if (3 == sscanf(line, "%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d", &to_move, &from, &to))
            move9001(to_move, from, to);
    }

    printf("STAR 2 - top crates with crane 9001: ");
    for (int i = 1; i <= STACKS; i++)
        printf("%c", all_crates[i][strlen(all_crates[i]) - 1]);
}

void move9001(size_t to_move, size_t from, size_t to)
{
    char crate;
    size_t from_top, to_top, crate_pos;
    from_top = strlen(all_crates[from]);

    for (int i = to_move; i > 0; i--)
    {
        // get crate
        crate_pos = (from_top - i);
        crate = all_crates[from][crate_pos];

        // label crate to remove
        all_crates[from][crate_pos] = '!';

        // add crate
        to_top = strlen(all_crates[to]); // keep checking new height
        all_crates[to][to_top] = crate; //add crate
    }

    // delete crate after removal
    for (int i = 0; i < from_top; i++)
    {
        if (all_crates[from][i] == '!')
            all_crates[from][i] = '\0';
    }
}
