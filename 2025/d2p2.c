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

        char buffer[20];
        for (lower_bound = lower_bound; lower_bound <= upper_bound; lower_bound++) {
            sprintf(buffer, "%lu", lower_bound);
            const unsigned int len = strlen(buffer);


            //Find all numbers our current lower_bound is divisible by
            //starting from 2 till the length of lower_bound
            
            //The number lower_bound is divisible by = x
            //split lower_bound into x parts and compare the parts
            
            //If part does not equal all other parts, skip everything and go to next iteration
            //If all parts are equal then add lower_bound to sum and go to next lower_bound number
            for (unsigned int i = 2; i <= len; i++) {
                if (len % i != 0)
                    continue;

                const unsigned int part_size = len / i;
                const unsigned int parts_count = i;

                //extra byte for null terminator
                char parts[parts_count][part_size + 1];
                for (unsigned int j = 0; j < parts_count; j++) {
                    char part[part_size + 1];
                    strncpy(part, buffer + j * part_size, part_size);
                    part[part_size] = '\0';
                    strcpy(parts[j], part);
                }

                char *first_part = parts[0];
                for (unsigned int j = 1; j < parts_count; j++) {
                    char *part_to_compare = parts[j];
                    for (unsigned int target_idx = 0; target_idx < part_size; target_idx++) {
                        if (first_part[target_idx] != part_to_compare[target_idx]) {
                            goto next_itr;
                        }
                    }
                }

                sum += lower_bound;
                break;

                next_itr:;
            }
        }
    }

    printf("%lu", sum); //38262920235

    return 0;
}
