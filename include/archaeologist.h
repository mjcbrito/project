#ifndef ARCHAEOLOGIST_H
#define ARCHAEOLOGIST_H

typedef struct Archaeologist* Archaeologist;

// Creates a new archaeologist
Archaeologist createArchaeologist(const char* name);

// Destroys an archaeologist
void destroyArchaeologist(Archaeologist archaeologist);

// Updates archaeologist's merit and penalties
void updateMerit(Archaeologist archaeologist, int change);
void incrementPenalties(Archaeologist archaeologist);

// Gets the archaeologist's merit and penalties
int getMerit(const Archaeologist archaeologist);
int getPenalties(const Archaeologist archaeologist);

// Gets the archaeologist's name
const char* getName(const Archaeologist archaeologist);

#endif // ARCHAEOLOGIST_H
