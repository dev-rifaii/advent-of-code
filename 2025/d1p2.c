#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
    FILE *file = fopen("./input/d1-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char line_buffer[6];
    const char subtraction_sign = 'L';
    int dial = 50;
    int zero_count = 0;
    int previous_dial;
    while (fgets(line_buffer, sizeof line_buffer, file) != NULL) {
        char sign;
        int number;
        sscanf(line_buffer, "%c%d", &sign, &number);

        previous_dial = dial;

        dial = (sign == subtraction_sign ? dial - number : dial + number);

        if (dial == 0 || (previous_dial > 0 && dial < 0) || (previous_dial < 0 && dial > 0))
            zero_count += 1;

        int remainder = dial % 100;
        int to_add = (number - remainder) / 100;

        zero_count += to_add;
        dial = remainder;
        printf("%d (%c%d) %d, %d\n", previous_dial, sign, number, dial, zero_count);
    }

    printf("%d\n", zero_count);

    return 0;
}
