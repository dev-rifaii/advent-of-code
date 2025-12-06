#include<stdio.h>
#include<stdlib.h>

typedef struct Range {
    unsigned long lower_bound;
    unsigned long upper_bound;
    unsigned int ignore;
} Range;

int main(void) {
    FILE *file = fopen("./input/d5-input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Input file not found");
        return 1;
    }

    unsigned int ranges_lines_count = 0;
    char buffer[240];

    while(fgets(buffer, sizeof buffer, file) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        ranges_lines_count++;
    }

    rewind(file);

    Range ranges[ranges_lines_count];

    unsigned int index = 0;
    while(fgets(buffer, sizeof buffer, file) != NULL) {
        if (buffer[0] == '\n') {
            break;
        }

        Range range;
        sscanf(buffer, "%lu-%lu",&range.lower_bound, &range.upper_bound);

        ranges[index] = range;
        index++;
    }

    //clean ranges
    for (unsigned int i = 0; i < ranges_lines_count; i++) {
        Range range = ranges[i];
        for (unsigned int j = 0; j < ranges_lines_count; j++) {
            if (j == i) continue;
            Range rangeToCompare = ranges[j];
            if (rangeToCompare.ignore == 1) continue;
            unsigned int rangeLowerOverlaps = range.lower_bound >= rangeToCompare.lower_bound && range.lower_bound <= rangeToCompare.upper_bound;
            unsigned int rangeUpperOverlaps = range.upper_bound >= rangeToCompare.lower_bound && range.upper_bound <= rangeToCompare.upper_bound;

            if (rangeLowerOverlaps && rangeUpperOverlaps) {
                ranges[i].ignore = 1;
                printf("FULL OVERLAP: [%lu], [%lu] is now ignored due to overlap with [%lu], [%lu]\n", range.lower_bound, range.upper_bound, rangeToCompare.lower_bound, rangeToCompare.upper_bound);
                break;
            }

            if (rangeLowerOverlaps) {
                printf("LOWER OVERLAP: [%lu], [%lu] is now ignored due to overlap with [%lu], [%lu]\n", range.lower_bound, range.upper_bound, rangeToCompare.lower_bound, rangeToCompare.upper_bound);
                ranges[j].upper_bound = range.upper_bound;
                ranges[i].ignore = 1;
                continue;
            }

            if (rangeUpperOverlaps) {
                printf("UPPER OVERLAP: [%lu], [%lu] is now ignored due to overlap with [%lu], [%lu]\n", range.lower_bound, range.upper_bound, rangeToCompare.lower_bound, rangeToCompare.upper_bound);
                ranges[j].lower_bound = range.lower_bound;
                ranges[i].ignore = 1;
                continue;
            }
        }
    }

    unsigned long fresh_ingredients_count = 0;
    for (unsigned int i = 0; i < index; i++) {
        Range range = ranges[i];
        if (range.ignore == 1) continue;
        unsigned long sum = range.upper_bound - range.lower_bound + 1;
        fresh_ingredients_count += sum;
    }

    printf("%lu\n", fresh_ingredients_count); //344260049617193

    return 0;
}
