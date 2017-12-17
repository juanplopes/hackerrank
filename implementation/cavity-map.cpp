#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 100100
using namespace std;

string T[300];

int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> T[i];
        }    
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if (i>0 and j>0 and i<N-1 and j<N-1 and 
                   T[i-1][j] < T[i][j] and T[i+1][j] < T[i][j] and 
                   T[i][j-1] < T[i][j] and T[i][j+1] < T[i][j])
                    cout << 'X';
                else
                    cout << T[i][j];
            }
            cout << endl;
        }
    }
}
