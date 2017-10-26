#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

long long T[100010], A[100010];

int main() { 
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> T[i];
        }
        
        A[0] = 1;
        for(int i=1; i<N; i++) {
            if (T[i] > T[i-1]) 
                A[i] = A[i-1]+1;
            else
                A[i] = 1;
        }
        for(int i=N-2; i>=0; i--) {
            if (T[i] > T[i+1])
                A[i] = max(A[i], A[i+1]+1);
        }
        
        long long value = 0;
        for(int i=0; i<N; i++) {
            value += A[i];
          //  cout << " " << A[i];
        }
        //cout << endl;
   
        cout << value << endl;
    }
}   
