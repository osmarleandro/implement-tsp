#include "rdata.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::find;

void see(double **matrix, int n);
void see(int *vector, int n);

int *greedy(double **adj, int dimension, int start);
bool visited(const int *begin, const int *end, int city);

int main(int argc, char **argv)
{

  double **matrixAdj;
  int dimension;

  readData(argc, argv, &dimension, &matrixAdj);
  see(matrixAdj, dimension);

  // Deallocate memory
  delete[] matrixAdj;
  return 0;
}

void see(double **matrix, int dimension)
{
  cout << "The Matrix of " << dimension << " dimensions" << endl;
  for (size_t i = 1; i <= dimension; i++)
  {
    for (size_t j = 1; j <= dimension; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
}

void see(int *vector, int dimension)
{
  for (int i = 0; i < dimension; i++)
    cout << vector[i] << "\t";
  cout << endl;
}

int *greedy(double **adj, int dimension, int start)
{
  int *path = new int[dimension];
  int *end = path + dimension;
  int current = start;

  do
  {
    *path = current;
    int next = nextCloser(adj, dimension, current, path);

    current = next;
    ++path;

  } while (path != end);

  return path;
}

bool visited(const int *begin, const int *end, int city)
{
  return find(begin, end, city) != end;
}

int nextCloser(double **adj, int dimension, int city, int *path)
{
  int neighbor = dimension + 1;
  while (!visited(path, path + dimension, adj[city][neighbor]))
  {

    neighbor++;
  }

  return neighbor;
}