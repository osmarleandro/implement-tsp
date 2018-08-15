#include "rdata.h"
#include <fstream>
#include <iostream>

using namespace std;

double **matrixAdj; // matriz de adjacencia
int dimension;      // quantidade total de vertices

void see(double **matrix, int n);
void see(int *vector, int n);

int main(int argc, char **argv)
{

  readData(argc, argv, &dimension, &matrixAdj);
  see(matrixAdj, dimension);
  return 0;
}

void see(double **matrix, int n)
{
  cout << "The Matrix of " << n << " dimensions" << endl;
  for (size_t i = 1; i <= n; i++)
  {
    for (size_t j = 1; j <= n; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
}

void see(int *vector, int n)
{
  for (int i = 0; i < n; i++)
    cout << vector[i] << "\t";
  cout << endl;
}
