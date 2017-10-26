#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define M 1000000007
using namespace std;

int main() { 
    string s;
    while(cin >> s) {
        long long V1 = 0, V2 = 0;
        for(int i=0; i<s.size(); i++) {
            V2 += V1;
            V1 = V1 * 10 + (i+1) * (s[i] - '0');
            
            V1 %= M;
            V2 %= M;
        }
   
        cout << (V1 + V2) % M << endl;
    }
}   
