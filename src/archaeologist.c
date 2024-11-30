#include <stdlib.h>
#include <string.h>
#include "archaeologist.h"

struct Archaeologist {
    char* name;
    int merit;
    int penalties;
};

Archaeologist createArchaeologist(const char* name) {
    Archaeologist a = malloc(sizeof(struct Archaeologist));
    if (!a) return NULL;

    a->name = strdup(name);
    a->merit = 0;
    a->penalties = 0;
    return a;
}

void destroyArchaeologist(Archaeologist archaeologist) {
    if (archaeologist) {
        free(archaeologist->name);
        free(archaeologist);
    }
}

void updateMerit(Archaeologist archaeologist, int change) {
    archaeologist->merit += change;
}

void incrementPenalties(Archaeologist archaeologist) {
    archaeologist->penalties++;
}

int getMerit(const Archaeologist archaeologist) {
    return archaeologist->merit;
}

int getPenalties(const Archaeologist archaeologist) {
    return archaeologist->penalties;
}

const char* getName(const Archaeologist archaeologist) {
    return archaeologist->name;
}
