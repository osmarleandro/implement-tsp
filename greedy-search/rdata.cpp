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

int **reading();
void see(int **adj, int n);
void brute_force(int **adj, int n);

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

void brute_force(int **adj, int n)
{
  int cost = INFINITY;
  int sol[] = {};

  // calculing cycle cost
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
    }
  }
}

void cost(int **adj, int *sol, int n)
{
  int total_cost = 0;
  for (int i = 0; i < n - 1; i++)
  {
    total_cost = total_cost + adj[sol[i]][sol[i + 1]];
  }
}
