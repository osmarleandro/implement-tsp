#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cmath>
using std::sqrt;

void reading();
void writing();

int main()
{
  //writing();
  reading();
  return 0;
}

void reading()
{
  string line;

  ifstream myfile("example.txt");
  if (myfile.is_open())
  {

    getline(myfile, line);

    std::string::size_type sz;

    int n = std::stoi(line, &sz);
    int madj[n][n];

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        getline(myfile, line);
        madj[i][j] = std::stoi(line, &sz);
      }
    }
    myfile.close();

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << madj[i][j];
      }
      cout << endl;
    }
  }

  else
    cout << "Unable to open file";
}

void writing()
{
  ofstream myfile("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else
    cout << "Unable to open file";
}
