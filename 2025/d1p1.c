#include<stdio.h>

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
    while (fgets(line_buffer, sizeof line_buffer, file) != NULL) {
        char sign;
        int number;
        sscanf(line_buffer, "%c%d", &sign, &number);

        number = (sign == subtraction_sign ? number * -1 : number);
        dial += number;

        if (dial % 100 == 0)
            zero_count++;
    }

    printf("%d\n", zero_count); //1150

    return 0;
}
