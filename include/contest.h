#ifndef CONTEST_H
#define CONTEST_H

#include "terrain.h"
#include "team.h"

// Manages the contest
typedef struct Contest* Contest;

// Creates a new contest
Contest createContest(Terrain terrain);

// Destroys the contest
void destroyContest(Contest contest);

// Processes commands like riqueza, terreno, etc.
void processCommand(Contest contest, const char* command);

#endif // CONTEST_H
