#include "./util/common.h"
#include "./rdata/rdata.h"
#include "./brute-force/brute.h"
#include "./greedy-algorithm/nearest-neighbor/nearest.h"
#include "./greedy-algorithm/bellmore-nemhauser/bn-heuristic.h"
#include "./greedy-algorithm/cheaper-insertion/cheaper.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  double **matrixAdj;
  int dimension, startCity = 1;
  // Reading the data of instance passed by parameter
  readData(argc, argv, &dimension, &matrixAdj);

  /** 
   * Starting the greedy algorithm looking for the best neighbor 
   * */
  clock_t startTime = clock();
  int *path = solveNearest(matrixAdj, dimension, startCity);
  double totalTime = timeExecution(startTime);
  double totalCost = cost(path, dimension, matrixAdj);
  // See the greedy solution
  cout << "\nThe nearest neighbor algorithm cost was: " << totalCost << endl;
  see(path, dimension);
  cout << "Execution time: " << totalTime << " s" << endl;

  /** 
   * Starting the bellmore-nemhauser algorithm 
   * */
  startTime = clock();
  int *bnPath = solveNearestEdge(matrixAdj, dimension, startCity);
  totalTime = timeExecution(startTime);
  double costBn = cost(bnPath, dimension, matrixAdj);
  // See the bn-heuristic solution
  cout << "\nThe bellmore-nemhauser cost was: " << costBn << endl;
  see(bnPath, dimension);
  cout << "Execution time: " << totalTime << " s" << endl;

  /**
   * Starting cheaper insertion
  */
  startTime = clock();
  int *ciPath = cheaperInsertion(matrixAdj, dimension, startCity);
  totalTime = timeExecution(startTime);
  double costCi = cost(ciPath, 2, matrixAdj);
  cout << "\nThe cheaper insertion cost was: " << costCi << endl;
  see(ciPath, 2);
  cout << "Execution time: " << totalTime << " s" << endl;
  /*
  /** 
   * Starting the brute force algorithm 
   * 
  clock_t startTimeBrute = clock();
  int *bestPath = bruteForce(matrixAdj, dimension, path);
  totalTime = timeExecution(startTimeBrute);
  double bestCost = cost(bestPath, dimension, matrixAdj);

  // See the best solution
  cout << "The best cost of path is " << bestCost << endl;
  see(bestPath, dimension);
  cout << "Execution time: " << totalTime << " s" << endl;
  */

  // Deallocate memory
  delete[] matrixAdj, path;
  return 0;
}