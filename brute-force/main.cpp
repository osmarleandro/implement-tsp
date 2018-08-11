#include <iostream>
#include <string>

using namespace std;

void see(string param[], int size)
{
	for (int i = 0; i < size; i++)
		cout << param[i] << "*";
	cout << endl;
}

int main()
{
	int n;
	cout << "Informe quantas cidades: ";
	cin >> n;

	string cities[n];
	int matrizAdj[n][n];

	for (int i = 0; i < n; i++)
	{
		string name;
		cout << i + 1 << "ª cidade: ";
		cin >> cities[i];
	}
	see(cities, n);
	return 0;
}
