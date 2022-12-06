#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ElfPairLimits
{
    int A_Low, A_High;
    int B_Low, B_High;
};

bool isAreaWithinArea(struct ElfPairLimits elf_pair);
bool isOverlapping(struct ElfPairLimits elf_pair);

int main (void)
{
    char line[20];
    struct ElfPairLimits elf_pair;
    char* token;
    int total_full_coverage_elves = 0; // star 1
    int total_overlapping_elves = 0; // star 2

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

        // DEBUG
        // printf("elf A low: %d    elf A  high: %d   elf B low: %d    elf B high: %d   \n",
        //          elf_pair.A_Low, elf_pair.A_High, elf_pair.B_Low, elf_pair.B_High);

        total_full_coverage_elves += (int)isAreaWithinArea(elf_pair);
        total_overlapping_elves += (int)isOverlapping(elf_pair);
    }

    printf("Star 1 - total fully covered elves: %d\n", total_full_coverage_elves);
    printf("Star 2 - total overlapping elves: %d\n", total_overlapping_elves);
}

bool isAreaWithinArea(struct ElfPairLimits elf_pair)
{
    // A fully in B
    if (elf_pair.A_Low >= elf_pair.B_Low &&
            elf_pair.A_High <= elf_pair.B_High)
        return true;

    // B fully in A
    else if (elf_pair.B_Low >= elf_pair.A_Low &&
            elf_pair.B_High <= elf_pair.A_High)
        return true;

    return false;
}

bool isOverlapping(struct ElfPairLimits elf_pair)
{
    // low within range OR high within range
    if ((elf_pair.A_Low >= elf_pair.B_Low && elf_pair.A_Low <= elf_pair.B_High) ||
        (elf_pair.A_High <= elf_pair.B_High && elf_pair.A_High >= elf_pair.B_Low))
        return true;

    // limits don't overlap but area does
    else if(isAreaWithinArea(elf_pair))
        return true;

    return false;
}
