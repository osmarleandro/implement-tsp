#ifndef CHEAPER_H_INCLUDED
#define CHEAPER_H_INCLUDED

#include <list>
using std::list;

list<int> generateSubroute(double **adj, int dimension, int start);
int *cheaperInsertion(double **adj, int dimension, int start);

#endif