#include <bits/stdc++.h>

using namespace std;

int main(){
    for(int i = 1; true; ++i){
        cout << i << endl;

        system("generator > input.txt");
        system("D < input.txt > output_1.txt");
        system("D_bruteforce < input.txt > output_2.txt");
    }
}