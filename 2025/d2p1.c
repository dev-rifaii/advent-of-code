#include<stdio.h>
#include<string.h>

int main(void) {
    FILE *file = fopen("./input/d2-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }


    unsigned long lower_bound;
    unsigned long upper_bound;

    unsigned long sum = 0;

    while (fscanf(file, "%lu-%lu", &lower_bound, &upper_bound) == 2) {
        //eat the comma
        int c = fgetc(file);

        printf("processing [%lu] - [%lu]\n", lower_bound, upper_bound);

        char buffer[20];
        for (lower_bound = lower_bound; lower_bound <= upper_bound; lower_bound++) {
            sprintf(buffer, "%lu", lower_bound);
            const unsigned int len = strlen(buffer);

            if (len % 2 != 0) {
                continue;
            }
            

            const unsigned int half_len = len / 2;

            //extra byte for null terminator
            char first_half[half_len + 1];
            char second_half[half_len + 1];
            strncpy(first_half, buffer, half_len);
            strncpy(second_half, buffer + half_len, half_len);
            first_half[half_len] = '\0';
            second_half[half_len] = '\0';

            for (unsigned int i = 0; i < half_len; i++) {
                if (first_half[i] != second_half[i]) {
                    goto end_early;
                }
            }

            sum += lower_bound;

            end_early:
                ;
        }


    }

    printf("%lu", sum); 

    return 0;
}
