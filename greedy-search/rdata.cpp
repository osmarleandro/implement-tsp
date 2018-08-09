#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::stoi;
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cmath>
using std::pow;

#include <array>
using std::array;

int **reading();
void see(int **adj, int n);
int *brute_force(int **adj, int n);
int cost(int **adj, int *sol, int n);
int *swap(int *sol, int i, int j);

int main()
{
  int **adj = reading();

  return 0;
}

int **reading()
{
  string::size_type sz;
  ifstream instance;
  string line;
  int **adj, n;

  instance.open("instance.tsp");
  if (instance.is_open())
  {
    getline(instance, line);
    n = stoi(line, &sz);
    adj = new int *[n];

    for (int i = 0; i < n; i++)
    {
      adj[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        getline(instance, line);
        adj[i][j] = stoi(line, &sz);
      }
    }
    instance.close();
  }

  else
    cout << "Unable to open file";

  see(adj, n);
  brute_force(adj, n);

  return adj;
}

void see(int **adj, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << adj[i][j] << "\t";
    }
    cout << endl;
  }
}

int *brute_force(int **adj, int n)
{
  // initial solution and cost
  int bestSol[] = { 0, 1, 2, 3, 4 };
  
  int bestCost = 17;

  // calculing cycle cost
  int total = cost(adj, bestSol, n);
  cout << "Solution cost: " << total << endl;

  // swapping every city and calculating cost
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int *current = swap(bestSol, i, j);
      if (cost(adj, current, n) < bestCost)
        bestSol = *current;
    }
  }
  return bestSol;
}

int cost(int **adj, int *sol, int n)
{
  int total_cost = 0;
  for (int i = 0; i <= n - 1; i++)
  {
    // if i is the last index, j equals to first: cost of first city return
    int j = (i == n - 1) ? 0 : (i + 1);

    total_cost = total_cost + adj[sol[i]][sol[j]];
    cout << "From " << sol[i] << " To " << sol[j] << " = " << adj[sol[i]][sol[j]] << endl;
  }
  return total_cost;
}

int *swap(int *sol, int i, int j)
{
  int tmp = sol[i];
  sol[i] = sol[j];
  sol[j] = tmp;
  return sol;
}