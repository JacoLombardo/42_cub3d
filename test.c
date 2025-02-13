#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100  // Maximum number of lines (adjust as needed)
#define MAX_WIDTH 1024 // Maximum possible width of a single line

// Function to read the map from a file and store it in a dynamically allocated char**
char** read_map_from_file(const char* filename, int* height) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char** map = (char**)malloc(MAX_LINES * sizeof(char*));
    if (!map) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WIDTH]; // Temporary buffer for reading lines
    int row = 0;

    while (fgets(buffer, MAX_WIDTH, file) && row < MAX_LINES) {
        int len = strlen(buffer);

        // Remove newline character if present
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Allocate memory for the row
        map[row] = (char*)malloc((len + 1) * sizeof(char));
        if (!map[row]) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        strcpy(map[row], buffer); // Copy line into allocated memory
        row++;
    }

    fclose(file);
    *height = row; // Store the number of lines read
    return map;
}

// Function to print the parsed map
void print_map(char** map, int height) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", map[i]);
    }
}

// Function to free allocated memory
void free_map(char** map, int height) {
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

int main() {
    const char* filename = "test.text"; // Name of the file containing the map
    int height;
    
    // Read the map from the file
    char** map = read_map_from_file(filename, &height);

    // Print the parsed map
    print_map(map, height);

    // Free allocated memory
    free_map(map, height);

    return 0;
}
