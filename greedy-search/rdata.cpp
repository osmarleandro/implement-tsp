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

void reading();
void writing();

int main()
{
  writing();
  reading();
  return 0;
}

void reading()
{
  string line;
  ifstream myfile("example.txt");
  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      cout << line << '\n';
    }
    myfile.close();
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
