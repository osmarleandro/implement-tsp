#include <time.h>

#include "./rdata/rdata.h"
#include "./brute-force/brute.h"
#include "./greedy-algorithm/greedy.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

#include <fstream>
using std::ifstream;
using std::ofstream;

double timeExecution(clock_t startTime);
void see(double **matrix, int dimension);
void see(int *vector, int dimension);

int main(int argc, char **argv)
{
  double **matrixAdj;
  int dimension;
  int startCity = 1;

  // Reading the data of instance passed by parameter
  readData(argc, argv, &dimension, &matrixAdj);

  // Starting the greedy algorithm looking for the best neighbor
  clock_t startTimeGreedy = clock();
  int *path = greedy(matrixAdj, dimension, startCity);
  double totalTime = timeExecution(startTimeGreedy);
  double totalCost = cost(path, dimension, matrixAdj);

  // See the greedy solution
  cout << "The total cost of path was " << totalCost << endl;
  see(path, dimension);
  cout << "Execution time: " << totalTime << " s" << endl;

  // Starting the brute force algorithm
  clock_t startTimeBrute = clock();
  int *bestPath = bruteForce(matrixAdj, dimension, path);
  totalTime = timeExecution(startTimeBrute);
  double bestCost = cost(bestPath, dimension, matrixAdj);

  // See the best solution
  cout << "The best cost of path is " << bestCost << endl;
  see(bestPath, dimension);
  cout << "Execution time: " << totalTime << " s" << endl;

  // Deallocate memory
  delete[] matrixAdj, path;
  return 0;
}

double timeExecution(clock_t startTime)
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
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
  cout << "The path of " << dimension << " cities" << endl;
  for (size_t i = 0; i < dimension; i++)
  {
    cout << i + 1 << ": " << vector[i] << "    ";
    if (((i + 1) % 10) == 0)
      cout << "\n";
  }
  cout << endl;
}