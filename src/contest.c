#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contest.h"
#include "team.h"
#include "terrain.h"

struct Contest {
    Terrain terrain;
    Team* teams;
    int teamCount;
    int teamCapacity;
};

Contest createContest(Terrain terrain) {
    Contest contest = malloc(sizeof(struct Contest));
    if (!contest) return NULL;

    contest->terrain = terrain;
    contest->teamCount = 0;
    contest->teamCapacity = 10;
    contest->teams = malloc(contest->teamCapacity * sizeof(Team));
    return contest;
}

void destroyContest(Contest contest) {
    for (int i = 0; i < contest->teamCount; i++) {
        destroyTeam(contest->teams[i]);
    }
    free(contest->teams);
    free(contest);
}

void addTeamToContest(Contest contest, Team team) {
    if (contest->teamCount == contest->teamCapacity) {
        contest->teamCapacity *= 2;
        contest->teams = realloc(contest->teams, contest->teamCapacity * sizeof(Team));
    }
    contest->teams[contest->teamCount++] = team;
}

void processCommand(Contest contest, const char* command) {
    if (strcmp(command, "riqueza") == 0) {
        int buriedTreasure = getBuriedTreasure(contest->terrain);
        printf("Riqueza enterrada: %d\n", buriedTreasure);
    } else if (strcmp(command, "terreno") == 0) {
        printTerrainState(contest->terrain);
    } else if (strncmp(command, "estrela ", 8) == 0) {
        const char* teamName = command + 8;
        for (int i = 0; i < contest->teamCount; i++) {
            if (strcmp(getTeamName(contest->teams[i]), teamName) == 0) {
                Archaeologist star = getStarArchaeologist(contest->teams[i]);
                if (star) {
                    printf("Estrela de %s: %s\n", teamName, getName(star));
                } else {
                    printf("Equipa invalida\n");
                }
                return;
            }
        }
        printf("Equipa invalida\n");
    } else {
        printf("Comando invalido\n");
    }
}
