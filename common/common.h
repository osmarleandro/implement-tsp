#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <list>
using std::list;

int *listToArray(list<int> list);
int nearestNeighborEdge(double **adj, int dimension, list<int> path, int city);

#endif