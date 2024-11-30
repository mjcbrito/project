#ifndef TEAM_H
#define TEAM_H

#include "archaeologist.h"

typedef struct Team* Team;

// Creates a new team
Team createTeam(const char* name);

// Destroys a team
void destroyTeam(Team team);

// Adds an archaeologist to the team
int addArchaeologist(Team team, Archaeologist archaeologist);

// Gets the team name
const char* getTeamName(const Team team);

// Calculates the team's score
int calculateTeamScore(const Team team);

// Gets the star archaeologist
Archaeologist getStarArchaeologist(const Team team);

#endif // TEAM_H
