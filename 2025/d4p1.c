#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    FILE *file = fopen("./input/d4-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    char buffer[240];
    unsigned int line_count = 0;
    unsigned int line_length;

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        line_length = strlen(buffer) - 1;
        line_count++;
    }

    rewind(file); //reset file reading pointer

    unsigned int grid[line_count][line_length];

    unsigned int current_line = 0;
    while(fgets(buffer, sizeof buffer, file) != NULL) {
        for (unsigned int i = 0; i < line_length; i++) {
            grid[current_line][i] = (buffer[i] == '@');
        }

        current_line++;
    }

    unsigned int total_accessable = 0;

    for (unsigned int x = 0; x < line_count; x++) {
        for (unsigned int y = 0; y < line_length; y++) {
            unsigned int adjacent_count = 0;
            if (grid[x][y] != 1)
                continue;

            unsigned int left_in_bound = y > 0;
            unsigned int right_in_bound = y < line_length - 1;
            unsigned int up_in_bound = x > 0;
            unsigned int down_in_bound = x < line_count - 1;

            if (left_in_bound) {
                if (grid[x][y - 1] == 1)
                    adjacent_count++;

                //top left
                if (up_in_bound && grid[x - 1][y - 1] == 1) {
                    adjacent_count++;
                }

                //bottom left
                if (down_in_bound && grid[x + 1][y - 1] == 1) {
                    adjacent_count++;
                }
            }

            if (right_in_bound) {
                if (grid[x][y + 1] == 1)
                    adjacent_count++;

                //top right
                if (up_in_bound && grid[x - 1][y + 1] == 1) {
                    adjacent_count++;
                }

                //bottom right
                if (down_in_bound && grid[x + 1][y + 1] == 1) {
                    adjacent_count++;
                }
            }

            if (up_in_bound) {
                if (grid[x - 1][y] == 1)
                    adjacent_count++;

            }

            if (down_in_bound) {
                if (grid[x + 1][y] == 1)
                    adjacent_count++;
            }

            if (adjacent_count < 4)
                total_accessable++;
        }
    }

    printf("%d\n", total_accessable); //1626

    return 0;
}
