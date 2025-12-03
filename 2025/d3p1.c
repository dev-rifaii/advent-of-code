#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE *file = fopen("./input/d3-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char buffer[120];

    unsigned int sum = 0;

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        unsigned int left_hand_highest = 0;
        unsigned int right_hand_highest = 0;

        char current_char = buffer[0];
        unsigned int index = 0;
        while (current_char != '\0' && current_char != '\n') {
            if (current_char - '0' > left_hand_highest && (buffer[index + 1] != '\n' && buffer[index + 1] != '\0')) {
                left_hand_highest = current_char - '0';
                right_hand_highest = buffer[index + 1] - '0';
                goto add;
            } else if (current_char - '0' > right_hand_highest) {
                right_hand_highest = current_char - '0';
            }

            add:
                current_char = buffer[++index];
        }


        char str[4];
        sprintf(str, "%d%d", left_hand_highest, right_hand_highest);
        const unsigned int result = strtol(str, NULL, 10);
        sum += result;
    }

    printf("%d\n", sum); //17359

    return 0;
}
