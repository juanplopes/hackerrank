#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int H[100010], L[100010];
int B[100010];

int abs(int a) {
    if (a<0) return -a;
    return a;
}

int main() { 
    int test; cin >> test;
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> B[i];
        }
        L[0] = H[0] = 0;
    
        for(int i=1; i<N; i++) {
            L[i] = max(L[i-1], H[i-1] + abs(B[i-1]-1));
            H[i] = max(L[i-1] + abs(B[i]-1), H[i-1] + abs(B[i]-B[i-1]));
        }
    
        cout << max(H[N-1], L[N-1]) << endl;
    }
}   
