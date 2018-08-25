#ifndef GREEDY_H_INCLUDED
#define GREEDY_H_INCLUDED

int *greedy(double **adj, int dimension, int start);
int bestNeighbor(double **adj, int dimension, int *path, int city);
bool visited(const int *begin, const int *end, int city);

#endif