#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

const uint8_t convert_Ato1 = 16;
const uint8_t convert_Zto1 = 39;

int main(void)
{
    // A = X = rock
    // B = Y = paper
    // C = Z = scissors

    printf("Advent of Code - day 2\n");
    FILE* file = fopen("day2/input.txt", "r");
    perror("open file check");

    char line[5];
    int round1_score, round2_score = 0;
    char* string_endptr; // only for strtol to use

    char elf_hand_alpha[2] = {'\0'};
    char my_hand_char[2] = {'\0'};
    int elf_hand, my_hand = 0;

    while (!feof(file))
    {
        fgets(line, 5, file);

    // convert ABC & XYZ to 1 = rock, 2 = paper, 3 = scissors
        elf_hand_alpha[0] = line[0] - convert_Ato1;
        elf_hand = atoi(elf_hand_alpha);

        my_hand_char[0] = line[2] - convert_Zto1;
        my_hand = atoi(my_hand_char);

    // star 1

        round1_score += my_hand; // pts for hand

        if (elf_hand == my_hand) // draw - 3pts
            round1_score += 3;

        else if ((elf_hand == 1 && my_hand == 2) || (elf_hand == 2 && my_hand == 3) || (elf_hand == 3 && my_hand == 1))
            round1_score += 6;   // win - 6pts

        // lose - 0 pts

    // star 2

        if (my_hand == 2) // draw - 3pts + pts for same hand as elf
            round2_score += 3 + elf_hand;

        else if (my_hand == 1) // lose - 0pts + pts for losing hand
        {
            if (elf_hand == 1)
                round2_score += 3;
            else if (elf_hand == 2)
                round2_score += 1;
            else
                round2_score += 2;
        }

        else // win - 6pts + pts for winning hand
        {
            round2_score += 6;

            if (elf_hand == 1)
                round2_score += 2;
            else if (elf_hand == 2)
                round2_score += 3;
            else // elf_hand 3
                round2_score += 1;
        }

    }
    printf("star 1 - total score %d\n", round1_score);
    printf("star 2 - total score %d\n\n", round2_score);
}
