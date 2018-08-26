#ifndef NEAREST_H_INCLUDED
#define NEAREST_H_INCLUDED

bool visited(const int *begin, const int *end, int city);
int nearestNeighbor(double **adj, int dimension, int *path, int city);
int *solveNearest(double **adj, int dimension, int start);

#endif