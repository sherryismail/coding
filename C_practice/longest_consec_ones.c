#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
void longest_consecutive_ones(int n);
void longest_consecutive_ones(int n) {
    int i=0, count =0, num = n;
    while(num)
    {
        num = num & (num  << 1);
        count++;
    }
    printf("Bits : %d\n", count);
    int store = 0;
    count = 0;
    while ( n > 0)
    {
        if (n & 0x01)
        {
            count++;
            if (count > store) {
                store = count;
                printf("--st= %d\t", store);
            }
        }else
            count = 0;
        n = n >> 1;
    }
    printf("Bits : %d\n", store);
}


int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 16);

    printf("num is : %d\n", n);
    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    longest_consecutive_ones(n);
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
