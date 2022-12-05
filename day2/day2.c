// a x  rock rock         draw 3 + 1 = 4
// a y  rock paper        win  6 + 2 = 8
// a z  rock scissors     loss 0 + 3 = 3
// b x  paper rock        loss 0 + 1 = 1
// b y  paper paper       draw 3 + 2 = 5
// b z  paper scissors    win  6 + 3 = 9
// c x  scissors rock     win  6 + 1 = 7
// c y  scissors paper    loss 0 + 2 = 2
// c z  scissors scissors draw 3 + 3 = 6

// convert abc and xyz to 123
// work out winner - assign points
// add points for xyz
// sum each round for grand total

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

int main(void)
{
    FILE* file = fopen("day2/input.txt", "r");
    perror("\nfile IO error: \n");

    char line[5];
    int round_score = 0;
    int total_score = 0;
    char elf_hand_char[2];
    long elf_hand = 0;
    char my_hand_char[2];
    int my_hand = 0;
    char* endptr;
    uint8_t ascii_Ato1 = 16;
    int ascii_Xto1 = 39;

    int round2_score = 0;
    int total2_score = 0;

    while (!feof(file))
    {
        fgets(line, 5, file);

        elf_hand_char[0] = line[0] - ascii_Ato1;
        elf_hand_char[1] - '\0';
        elf_hand = strtol(elf_hand_char, &endptr, 10);
        printf("%d: %d\n", line[0], elf_hand);

        my_hand_char[0] = line[2] - ascii_Xto1;
        my_hand_char[1] - '\0';
        my_hand = strtol(my_hand_char, &endptr, 10);
        printf("%d: %d\n", line[2], my_hand);

        // if (elf_hand == my_hand)
        //     round_score += 3; // draw

        // else if ((elf_hand == 1 && my_hand == 3) || (elf_hand == 2 && my_hand == 1) || (elf_hand == 3 && my_hand == 2))
        //     round_score += 0; // loss

        // else
        //     round_score += 6; // thus a win

        // printf("win pts: %d\n", round_score);

        // round_score += my_hand;
        // printf("round pts: %d\n", round_score);

        // total_score += round_score;
        // round_score = 0;

    // star 2

        if (my_hand == 2) // draw
        {
            round2_score += 3;
            round2_score += elf_hand; // (i choose the same)
        }

        else if (my_hand == 1) // lose
        {
            round2_score += 0;

            if (elf_hand == 1) // elf = rock, me = scissors
                round2_score += 3;

            else if (elf_hand == 2) // elf = paper, me = rock
                round2_score += 1;

            else // elf = scissors. me = paper
                round2_score += 2;
        }

        else // win
        {
            round2_score += 6;

            if (elf_hand == 1) // elf = rock, me = paper
                round2_score += 2;

            else if (elf_hand == 2) // elf = paper, me = scissors
                round2_score += 3;

            else // elf = scissors. me = rock
                round2_score += 1;
        }

        printf("round2 pts: %d\n", round2_score);
        total2_score += round2_score;
        round2_score = 0;
    }
    printf("total score %d\n", total_score);
    printf("total score %d\n", total2_score);
}
