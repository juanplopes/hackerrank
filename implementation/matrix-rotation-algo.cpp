#include <iostream>
#include <algorithm>
#define MAX 100100
using namespace std;

int T[400][400], V[400][400];

void rotate(int M, int N, int i, int j, int R, int &i2, int &j2) {
    int layer = min(min(i, M-1-i), min(j, N-1-j));
    int top = layer, bottom = M-1-layer, left = layer, right = N-1-layer;
    
    R %= 2*(M-2*layer)+2*(N-2*layer)-4;
    
    for(int k=0; k<R; k++) {
        if (i == top and j>left)
            j--;
        else if (j == left and i<bottom)
            i++;
        else if (i == bottom and j<right)
            j++;
        else if (j == right and i>top)
            i--;
    }
    i2 = i;
    j2 = j;
}

int main() {
    int M, N, R;
    while(cin >> M >> N >> R) {
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cin >> T[i][j];
                int i2, j2;
                rotate(M, N, i, j, R, i2, j2);
                V[i2][j2] = T[i][j];
            }
        }    
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cout << (j>0?" ":"") << V[i][j];
            }    
            cout << endl;
        }   
        
        
        
    }
}
