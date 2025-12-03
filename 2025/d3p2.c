#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    FILE *file = fopen("./input/d3-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char buffer[120];
    unsigned long long sum = 0;

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        char full_number[13];
        const unsigned int len = strlen(buffer);
        unsigned int current_target_index = 0;

        int used_index = -1;
        int max_reachable_index = 0;
        for (int i = 0; i < 12; i++) {
            int current_highest_number = 0;
            int starting_index = ((len - 11) - 2) + i;
            for (int j = starting_index; j >= max_reachable_index; j--) {
                int current_number = buffer[j] - '0';
                if (current_number >= current_highest_number) {
                    current_highest_number = current_number;
                    used_index = j;
                }
            }

            if (used_index != -1) {
                max_reachable_index = used_index + 1;
                used_index = -1;
            }

            full_number[i] = current_highest_number + '0';
        }

        full_number[12] = '\0';
        unsigned long as_long = strtol(full_number, NULL, 10);
        sum += as_long;
    }

    printf("%llu\n", sum); //172787336861064

    return 0;
}
