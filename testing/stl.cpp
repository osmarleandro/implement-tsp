#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

string read()
{
	string s = "";
	cout << "Digit to recovery value: ";
	cin >> s;
	return s;
}

void show(map<string,int> param)
{
	map<string,int>::iterator iter;

	for(iter = param.begin(); iter != param.end(); iter++){
		cout << iter->first << " = " << iter->second << endl;
	}
}

int main()
{
	string s;
	map<string,int> digits;

	digits["zero"] = 0;
	digits["one"] = 1;
	digits["two"] = 2;
	digits["three"] = 3;
	digits["four"] = 4;
	digits["five"] = 5;

	s = read();
	while(s.compare("exit") != 0){
		if(s.compare("show") == 0) show(digits);
		else cout << digits[s] << endl;
		
		s = read();
	}

	return 0;
}
