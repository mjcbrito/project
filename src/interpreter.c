#include <stdio.h>
#include <string.h>
#include "interpreter.h"

void runInterpreter(Contest contest) {
    char command[128];
    printf("Enter commands (type 'sair' to quit):\n");

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
}
