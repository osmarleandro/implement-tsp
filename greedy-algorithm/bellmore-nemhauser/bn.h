#ifndef BN_H_INCLUDED
#define BN_H_INCLUDED

#include <list> 
using std::list;

bool visited(const int *begin, const int *end, int city);
int nextNearestEdge(double **adj, int dimension, int *path, int city);
list<int> solveNextNearestEdge(double **adj, int dimension, int start);

#endif