#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	system("g++ -std=c++11 -o e E.cpp");
	system("g++ -std=c++11 -o gen generator.cpp");
	system("g++ -std=c++11 -o check checker.cpp");

	int i = 0;
	while(true){
		cout << (++i) << endl;

		system("gen > input.txt");
		system("e < input.txt > output.txt");
		system("check > final.txt");

		ifstream in("final.txt");
		string line;

		getline(in, line);
		if(line != "OK"){
			cout << line << endl;
			return 0;
		}
	}
}