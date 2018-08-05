#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

int main()
{
  string anyword;
  while (anyword.compare("sair") != 0)
  {

    cout << "Digite uma palavra: ";
    getline(cin, anyword);

    for (int i = 0; i < anyword.length(); i++)
    {
      cout << anyword[i] << "-" << (int)anyword[i] << endl;
    }
    cout << endl;
  }
  return 0;
}