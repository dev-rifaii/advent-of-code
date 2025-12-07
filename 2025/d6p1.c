#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
    FILE *file = fopen("./input/d6-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char buffer[100000];
    unsigned int numbers_lines_count = 0;
    unsigned int numbers_count_on_line = 0;

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        numbers_lines_count++;
    }

    rewind(file);

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        char *c;
        c = strtok(buffer, " ");
        while ((c = strtok(NULL, " ")) != NULL) {
            numbers_count_on_line++;
        }

        numbers_count_on_line++;

        break;
    }


    rewind(file);

    unsigned int lines_tokens[numbers_lines_count][numbers_count_on_line];

    char operations[numbers_count_on_line];


    unsigned int line = 0;
    while(line < numbers_lines_count) {
        fgets(buffer, sizeof buffer, file);
        char *c;

        fflush(stdout);
        c = strtok(buffer, " ");
        int token = 1;
        if (line == numbers_lines_count - 1) {
            operations[0] = c[0];
            while ((c = strtok(NULL, " ")) != NULL) {
                operations[token] = c[0];
                token++;
            }

            break;
        }

        unsigned int token_value;
        sscanf(c, "%d", &token_value);
        lines_tokens[line][0] = token_value;
        while ((c = strtok(NULL, " ")) != NULL) {
            sscanf(c, "%d", &token_value);
            lines_tokens[line][token] = token_value;
            token++;
        }
        line++;
    }

    unsigned long long total_sum = 0;
    unsigned int column = 0;
    while (column < numbers_count_on_line) {
        unsigned long long current_problem_sum = lines_tokens[0][column];
        for (unsigned int row = 1; row < numbers_lines_count - 1; row++) {
            int multiply = operations[column] == '*' ? 1 : 0;
            if (multiply == 1) {
                //printf("%d * %llu = %llu\n", lines_tokens[row][column], current_problem_sum, lines_tokens[row][column] * current_problem_sum);
                current_problem_sum *= lines_tokens[row][column];
            } else {
                //printf("%d + %llu = %llu\n", lines_tokens[row][column], current_problem_sum, lines_tokens[row][column] + current_problem_sum);
                current_problem_sum += lines_tokens[row][column];
            }
        }
        total_sum += current_problem_sum;
        column++;
        //printf("----------------------------------\n");
    }

    printf("%llu\n", total_sum); //6343365546996
    return 0;
}
