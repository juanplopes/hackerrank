#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 100100
using namespace std;

string T[300];

int main() {
    int tests; cin >> tests;
    int N, A, B;
    while(cin >> N >> A >> B) {
        if (A == B) {
            cout << (N-1) * A << endl;
            continue;
        }
        int temp = min(A, B);
        B = max(A, B);
        A = temp;
        
        int value = (N-1)*A;
        for(int i=0; i<N; i++) {
            cout << (i>0? " " : "") << value;
            value += B-A;
        }
        cout << endl;
    }
}
