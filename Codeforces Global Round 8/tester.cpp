#include <bits/stdc++.h>

using namespace std;

int main(){
    system("g++ -std=c++17 -o generator generator.cpp");
    system("g++ -std=c++17 -o E E.cpp");

    int i = 0;
    while(true){
        cout << i++ << endl;
        system("generator > input.txt");
        system("E < input.txt > output.txt");

        ifstream in1("input.txt"), in2("output.txt");
        int t, n;
        in1 >> t >> n;
        int k;
        in2 >> k;

        if(7 * k > 4 * n){
            cout << "WRONG" << "\n";
            cout << n << " " << k << endl;
            return 0;
        }
    }
}