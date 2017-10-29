#include<iostream>
#include<cstring>
#include<cmath>
#define M 1000000007
using namespace std;

long long T[10000], A[10000], B[10000];

bool isPrime(int n) {
    if (n<2) return false;
    for(int i=2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() { 
    int test; cin >> test;
    int N;
    while(cin >> N) {
        memset(T, 0, sizeof T);
        for(int i=0; i<N; i++) {
            int temp; cin >> temp;
            T[temp]++;
        }
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        A[0] = B[0] = 1;
        for(int i=3500; i<=4500; i++) {
            if (T[i] > 0) {
                for(int j=0; j<8192; j++) {
                    int v = i^j; 
                    B[v] += (T[i]+1)/2 * A[j];
                    B[v] %= M;
                    
                    B[j] += T[i]/2 * A[j];
                    B[j] %= M;
                }
                memcpy(A, B, sizeof A);
            }
            
        }
        
        long long total = 0;
        for(int i=0; i<10000; i++) {
            if (A[i] > 0 and isPrime(i)) {
                //cout << " " << i << " " << A[i] << endl;
                total += A[i];
            }
        }
        
        cout << total%M << endl;
    }
}   
