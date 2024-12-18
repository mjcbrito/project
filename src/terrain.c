#include <stdlib.h>
#include <stdio.h>
#include "terrain.h"

struct Terrain {
    int rows;
    int cols;
    int* grid;
};

Terrain createTerrain(int rows, int cols) {
    Terrain t = malloc(sizeof(struct Terrain));
    if (!t) return NULL;
    t->rows = rows;
    t->cols = cols;
    t->grid = malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows * cols; i++) {
        t->grid[i] = 0; // Initialize grid with zeros
    }
    return t;
}

void destroyTerrain(Terrain terrain) {
    free(terrain->grid);
    free(terrain);
}

int getBuriedTreasure(const Terrain terrain) {
    int total = 0;
    for (int i = 0; i < terrain->rows * terrain->cols; i++) {
        if (terrain->grid[i] > 0) total += terrain->grid[i];
    }
    return total;
}

int excavate(Terrain terrain, int row, int col) {
    if (row < 0 || row >= terrain->rows || col < 0 || col >= terrain->cols) {
        return -1; // Invalid coordinates
    }
    int index = row * terrain->cols + col;
    int value = terrain->grid[index];
    terrain->grid[index] = 0; // Excavated cells are set to zero
    return value;
}

void printTerrainState(const Terrain terrain) {
    for (int i = 0; i < terrain->rows; i++) {
        for (int j = 0; j < terrain->cols; j++) {
            printf("%c", terrain->grid[i * terrain->cols + j] > 0 ? '*' : '-');
        }
        printf("\n");
    }
}

void setTerrainValue(Terrain terrain, int row, int col, int value) {
    if (row < 0 || row >= terrain->rows || col < 0 || col >= terrain->cols) {
        fprintf(stderr, "Invalid coordinates: (%d, %d)\n", row, col);
        return;
    }
    terrain->grid[row * terrain->cols + col] = value;
}
