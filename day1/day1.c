#include "stdlib.h"
#include "stdio.h"
#include "errno.h"

int main(void)
{
    FILE* file = fopen("day1/input.txt", "r");
    perror("file I/O check");

    char line[10];
    char* endptr;
    char* string;
    int temp_num, count, first_sum, second_sum, third_sum = 0;
 
    while(!feof(file))
    {
        string = fgets(line, 10, file);
        temp_num = strtol(string, &endptr, 10);
        count += temp_num;

        if (temp_num == 0)
        {
            if (count >= first_sum)
            {
                third_sum = second_sum;
                second_sum = first_sum;
                first_sum = count;
            }

            else if (count >= second_sum)
            {
                third_sum = second_sum;
                second_sum = count;
            }

            else if (count >= third_sum)
                third_sum = count;

            count = 0;
        }
    }

    printf("first elf sum = %d\n", first_sum);
    printf("second elf sum = %d\n", second_sum);
    printf("third elf sum = %d\n", third_sum);
    printf("total cals: %d\n", first_sum + second_sum + third_sum);
}
