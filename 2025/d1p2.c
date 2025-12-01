#include<stdio.h>
#include<stdlib.h>

int main(void) {
    FILE *file = fopen("./input/d1-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char line_buffer[8];
    const char subtraction_sign = 'L';
    int dial = 50;
    int zero_count = 0;
    int previous_dial;
    while (fgets(line_buffer, sizeof line_buffer, file) != NULL) {
        char sign;
        int number;
        sscanf(line_buffer, "%c%d", &sign, &number);

        number = (sign == subtraction_sign ? number * -1 : number);
        previous_dial = dial;
        dial += number;

        int remainder = dial % 100;
        zero_count+= abs(dial / 100);

        if (dial == 0 || ((previous_dial > 0 && dial < 0) || (previous_dial < 0 && dial > 0)))
            zero_count += 1;

        dial = remainder;
    }

    printf("%d\n", zero_count); //6738

    return 0;
}
