#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contest.h"
#include "terrain.h"

#define MAX_COMMAND_LENGTH 128

int main() {
    // Initialize terrain dimensions
    int rows, cols;
    printf("Enter terrain dimensions (rows cols): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid terrain dimensions.\n");
        return 1;
    }

    // Create terrain
    Terrain terrain = createTerrain(rows, cols);
    printf("Enter terrain treasures (row by row):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Invalid terrain value.\n");
                destroyTerrain(terrain);
                return 1;
            }
            terrain->grid[i * cols + j] = value;
        }
    }

    // Create contest
    Contest contest = createContest(terrain);

    // Command processing loop
    printf("Enter commands (type 'sair' to quit):\n");
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        if (!fgets(command, sizeof(command), stdin)) {
            fprintf(stderr, "Error reading input.\n");
            break;
        }

        // Remove trailing newline
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "sair") == 0) {
            printf("Exiting contest...\n");
            break;
        }

        processCommand(contest, command);
    }

    // Clean up
    destroyContest(contest);
    destroyTerrain(terrain);
    return 0;
}
