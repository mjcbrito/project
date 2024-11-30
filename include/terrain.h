#ifndef TERRAIN_H
#define TERRAIN_H

typedef struct Terrain* Terrain;

// Creates a new terrain
Terrain createTerrain(int rows, int cols);

// Destroys the terrain
void destroyTerrain(Terrain terrain);

// Gets the total buried treasure
int getBuriedTreasure(const Terrain terrain);

// Excavates a cell, returns the treasure value or penalty
int excavate(Terrain terrain, int row, int col);

// Prints the terrain state
void printTerrainState(const Terrain terrain);

// Sets the value of a cell in the terrain
void setTerrainValue(Terrain terrain, int row, int col, int value);

#endif // TERRAIN_H
