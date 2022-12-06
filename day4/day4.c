// PSEUDO
// go through input line by line
//   use strtok to split by symbol '-' and ','
//   store the numbers in a variable

// check elf 1 within elf 2
//   pair++
//   break loop
// elf 2 within elf 1?
//   pair ++
//   break loop

// elf comparisson
//  elfA low higher than elfB low
//  elfA high lower than elfB high

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

struct ElfPairLimits
{
    int A_Low;
    int A_High;
    int B_Low;
    int B_High;
};

bool isAreaWithinArea(struct ElfPairLimits elf_pair);
bool isOverlapping(struct ElfPairLimits elf_pair);

int main (void)
{
    char line[20];
    char* token;
    struct ElfPairLimits elf_pair;
    int total_full_coverage_elves = 0;
    int total_overlapping_elves = 0;

    printf("Advent Of Code - day 4\n");
    FILE* file = fopen("day4/input.txt", "r");
    perror("open file check");

    while(!feof(file))
    {
        fgets(line, 20, file);

        elf_pair.A_Low = atoi(strtok(line, "-,"));
        elf_pair.A_High = atoi(strtok(NULL, "-,"));
        elf_pair.B_Low = atoi(strtok(NULL, "-,"));
        elf_pair.B_High = atoi(strtok(NULL, "-,"));

        // printf("elf A low: %d    elf A  high: %d   elf B low: %d    elf B high: %d   \n",
        //          elf_pair.A_Low, elf_pair.A_High, elf_pair.B_Low, elf_pair.B_High);

        total_full_coverage_elves += (int)isAreaWithinArea(elf_pair);
        total_overlapping_elves += (int)isOverlapping(elf_pair);
    }

    printf("total fully covered elves: %d\n", total_full_coverage_elves);
    printf("total overlapping elves: %d\n", total_overlapping_elves);
}

bool isAreaWithinArea(struct ElfPairLimits elf_pair)
{
    if (elf_pair.A_Low >= elf_pair.B_Low &&
            elf_pair.A_High <= elf_pair.B_High)
        return true;

    else if (elf_pair.B_Low >= elf_pair.A_Low &&
            elf_pair.B_High <= elf_pair.A_High)
        return true;

    else
        return false;
}

// star 2

bool isOverlapping(struct ElfPairLimits elf_pair)
{
    // low within range OR high within range
    if ((elf_pair.A_Low >= elf_pair.B_Low && elf_pair.A_Low <= elf_pair.B_High) ||
        (elf_pair.A_High <= elf_pair.B_High && elf_pair.A_High >= elf_pair.B_Low))
        return true;

    // limits don't overlap but area does
    else if(isAreaWithinArea(elf_pair))
        return true;

    else
        return false;
}
