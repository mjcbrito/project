#include <stdio.h>
#include <stdlib.h>
#include "contest.h"
#include "terrain.h"
#include "team.h"
#include "interpreter.h"

#define MAX_TEAM_NAME 40
#define MAX_TEAMS 10

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
            setTerrainValue(terrain, i, j, value); // Use setter function
        }
    }

    // Initialize contest
    Contest contest = createContest(terrain);

    // Add teams to the contest
    printf("Enter the number of teams: ");
    int teamCount;
    if (scanf("%d", &teamCount) != 1 || teamCount <= 0 || teamCount > MAX_TEAMS) {
        fprintf(stderr, "Invalid number of teams.\n");
        destroyContest(contest);
        destroyTerrain(terrain);
        return 1;
    }

    char teamName[MAX_TEAM_NAME];
    for (int i = 0; i < teamCount; i++) {
        printf("Enter team name: ");
        scanf("%s", teamName);

        Team team = createTeam(teamName);
        addTeamToContest(contest, team);

        printf("Enter the number of archaeologists for %s: ", teamName);
        int archaeologistCount;
        if (scanf("%d", &archaeologistCount) != 1 || archaeologistCount <= 0) {
            fprintf(stderr, "Invalid number of archaeologists.\n");
            destroyContest(contest);
            destroyTerrain(terrain);
            return 1;
        }

        for (int j = 0; j < archaeologistCount; j++) {
            printf("Enter archaeologist name: ");
            char archaeologistName[MAX_TEAM_NAME];
            scanf("%s", archaeologistName);

            Archaeologist archaeologist = createArchaeologist(archaeologistName);
            addArchaeologist(team, archaeologist);
        }
    }

    // Run interpreter to process commands
    runInterpreter(contest);

    // Clean up
    destroyContest(contest);
    destroyTerrain(terrain);

    return 0;
}
