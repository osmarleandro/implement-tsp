#ifndef BRUTE_H_INCLUDED
#define BRUTE_H_INCLUDED

int *bruteForce(double **adj, int n, int *currentSolution);
double cost(int *path, int dimension, double **matrix);

#endif