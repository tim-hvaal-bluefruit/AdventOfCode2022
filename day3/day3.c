// QUICK CHECK
// NGvdqJmJvpNb GRMGQgRsfgfn   - G - priority 33
// WlHTHShlLwSWj FRsncfbcwsgQc - w - priority 23
// answer 56 with this input

// PSEUDO
// loop file read line at a time
//     check line length
//     loop through first half (searchterm)
//         loop through second half (comparisson)
//             if line[searchterm] == line[comparisson]
//                 item == search term prioritised (function)
//                 total += item
//                 break out of line loops

// star 2
// store three lines
// check each letter one by one against second line
// if letter in second check third
// if item in third that's the badge
// prioritise the item and add to total

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

const int lowercase_to_num = 96;
const int uppercase_to_num = 38;

int prioritise(char item);

int main(void)
{
    printf("Advent Of Code - day3\n");
    FILE* file = fopen("day3/input.txt", "r");
    perror("open text file");

    char line[50], line2[50], line3[50];
    size_t line_len = 0, halfway = 0, search_pos = 0, compare_pos = 0, item_total = 0;
    char item;

    while(!feof(file))
    {
        fgets(line, 50, file);

        while(line[line_len] != '\n')
            line_len++;

        halfway = line_len / 2; // always whole num

        for(search_pos = 0; search_pos < halfway; search_pos++)
        {
            for(compare_pos = halfway; compare_pos < line_len; compare_pos++)
            {
                if (line[compare_pos] == line[search_pos])
                {
                    item = line[search_pos];
                    item_total += prioritise(item);
                    break;
                }
            }

            if (line[compare_pos] == line[search_pos])
                break;
        }
        line_len = 0;
        halfway = 0;
    }

    printf("item_total: %d\n", item_total);
    item_total = 0;

    // star 2
    fseek(file, 0, SEEK_SET);
    while(!feof(file))
    {
        item = '\0';
        fgets(line, 50, file);
        fgets(line2, 50, file);
        fgets(line3, 50, file);

        for (int i = 0; line[i] != '\n'; i++)
        {
            for (int j = 0; line2[j] != '\n'; j++)
            {
                if(line[i] == line2[j])
                {
                    for(int k = 0; line3[k] != '\n'; k++)
                    {
                        if(line[i] == line3[k])
                        {
                            item = line[i];
                            item_total += prioritise(item);
                            item = '!';
                            break;
                        }
                    }

                    if(item == '!')
                        break;
                }
            }

            if (item == '!')
                break;
        }
    }
    printf("star2_total: %d\n", item_total);
}



int prioritise(char item)
{
    int priority = 0;

    if (item >= 'a' && item <= 'z')
        priority = item - lowercase_to_num;
    else if (item >= 'A' && item <= 'Z')
        priority = item - uppercase_to_num;
    else
        printf("item invalid %d\n", item);

    return priority;
}
