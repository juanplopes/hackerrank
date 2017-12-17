#include <iostream>
#include <algorithm>
#define MAX 100100
using namespace std;

int A[MAX], B[MAX], C[MAX];

int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        //cout << endl << N << endl;
        sort(B, B+N);
        
        int count = 0, a1, b1, a2, b2;
        for(int i=0; i<N; i++) {
            if (A[i] != B[i]) {
                C[i] = 1;
                count++;
                if (count == 1) 
                    a1 = i+1;
                else if (count == 2)
                    b1 = i+1;
            } else {
                C[i] = 0;
            }
        }
        
        bool inside = false, invalid = false;
        int invCount = 0;        
        for(int i=0; i<N; i++) {
            if (!inside and i+1 < N and A[i+1] < A[i]) {
                invCount++;
                a2 = i+1;
                inside = true;
            } if (inside and i+1 < N and A[i+1] > A[i]) {
                b2 = i+1;
                inside = false;
            } else {
                if (!inside and A[i] != B[i]) invalid = true;
            }
        }
        if (inside) b2 = N;
        
        //cout << invCount << endl;
        if (count == 0) {
            cout << "yes" << endl;
        } else if (count == 2) {
            cout << "yes" << endl << "swap " << a1 << " " << b1 << endl;
        } else if (invCount == 1 and not invalid) {
            cout << "yes" << endl << "reverse " << a2 << " " << b2 << endl;
        } else {
            cout << "no" << endl;
        }
        
    }
}
