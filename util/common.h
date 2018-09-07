#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <time.h>
#include <list>
using std::list;


int *listToArray(list<int> list);
int nearestNeighborEdge(double **adj, int dimension, list<int> path, int city);

void see(double **matrix, int dimension);
void see(int *vector, int dimension);
void see(list<int> route, int dimension);

double timeExecution(clock_t startTime);

#endif