#include "../so_long.h"
#include <stdio.h>
#include <stdlib.h>

char **read_map(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return NULL;
    }

    char **map = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row_count = 0;

    // First pass: count the number of rows
    while ((read = getline(&line, &len, file)) != -1)
    {
        row_count++;
    }

    // Allocate memory for the map (row_count + 1 for the NULL terminator)
    map = (char **)malloc((row_count + 1) * sizeof(char *));
    if (!map)
    {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Reset the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Second pass: read the map and store it in the map array
    int row = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        map[row] = (char *)malloc((read + 1) * sizeof(char)); // +1 for the null terminator
        if (!map[row])
        {
            perror("Memory allocation failed");
            fclose(file);
            return NULL;
        }
        // Remove the newline character from the end of the line
        line[read - 1] = '\0';
        // Copy the line into the map
        strcpy(map[row], line);
        row++;
    }

    map[row] = NULL; // Null-terminate the map

    fclose(file);
    free(line); // Free the buffer used by getline

    return map;
}

void free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

