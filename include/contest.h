#ifndef CONTEST_H
#define CONTEST_H

#include "terrain.h"
#include "team.h"

typedef struct Contest* Contest;

// Creates a new contest
Contest createContest(Terrain terrain);

// Destroys the contest
void destroyContest(Contest contest);

// Adds a team to the contest
void addTeamToContest(Contest contest, Team team);

// Processes commands like "riqueza", "terreno", etc.
void processCommand(Contest contest, const char* command);

#endif // CONTEST_H
