#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int T[10010];

int main() { 
    int test; cin >> test;
    int N;
    while(cin >> N) {
        int minn = 1000000;
        for(int i=0; i<N; i++) {
            cin >> T[i];
            minn = min(minn, T[i]);
        }
    
        long long result = 1000000000000ll;
        for(int bias=0; bias<6 && minn-bias >= 0; bias++) {
            long long total = 0;
            for(int i=0; i<N; i++) {
                int v = T[i] - minn + bias;
                total += v/5 + (v%5/2) + (v%5%2);
            }
            result = min(result, total);
        }
        cout << result << endl;
    }
}
