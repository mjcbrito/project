#include <stdlib.h>
#include <string.h>
#include "team.h"

struct Team {
    char* name;
    Archaeologist* archaeologists; // Single pointer for a dynamic array
    int archaeologistCount;
    int archaeologistCapacity;
};

Team createTeam(const char* name) {
    Team team = malloc(sizeof(struct Team));
    if (!team) return NULL;

    team->name = strdup(name);
    team->archaeologistCount = 0;
    team->archaeologistCapacity = 10;
    team->archaeologists = malloc(team->archaeologistCapacity * sizeof(Archaeologist));
    return team;
}

void destroyTeam(Team team) {
    if (team) {
        free(team->name);
        for (int i = 0; i < team->archaeologistCount; i++) {
            destroyArchaeologist(team->archaeologists[i]); // Fixed argument type
        }
        free(team->archaeologists);
        free(team);
    }
}

int addArchaeologist(Team team, Archaeologist archaeologist) {
    if (team->archaeologistCount == team->archaeologistCapacity) {
        team->archaeologistCapacity *= 2;
        team->archaeologists = realloc(team->archaeologists, team->archaeologistCapacity * sizeof(Archaeologist));
    }
    team->archaeologists[team->archaeologistCount++] = archaeologist; // Fixed assignment
    return 1;
}

int calculateTeamScore(const Team team) {
    int score = 0;
    for (int i = 0; i < team->archaeologistCount; i++) {
        score += getMerit(team->archaeologists[i]); // Fixed argument type
    }
    return score;
}

Archaeologist getStarArchaeologist(const Team team) {
    Archaeologist star = NULL;
    for (int i = 0; i < team->archaeologistCount; i++) {
        Archaeologist current = team->archaeologists[i]; // Fixed type
        if (!star || getMerit(current) > getMerit(star)) {
            star = current;
        }
    }
    return star;
}

const char* getTeamName(const Team team) {
    return team->name;
}
