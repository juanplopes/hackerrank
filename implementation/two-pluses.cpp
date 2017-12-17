#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 100100
using namespace std;

int N, M;
int T[20][20];

bool inter(int x, int y, int z, int i, int j) {
    if (y == j and x-z <= i and i <= x+z) return true;
    if (x == i and y-z <= j and j <= y+z) return true;
    return false;
}

int second(int x, int y, int z) {
    int best = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int maxx = min(min(i+1, j+1), min(N-i, M-j)); 
            for(int k=0; k<maxx; k++) {
                if (T[i+k][j]) break;
                if (T[i-k][j]) break;
                if (T[i][j+k]) break;
                if (T[i][j-k]) break;
                if (inter(x, y, z, i+k, j)) break;
                if (inter(x, y, z, i-k, j)) break;
                if (inter(x, y, z, i, j+k)) break;
                if (inter(x, y, z, i, j-k)) break;
               
                best = max(best, k*4+1);
            }
        }
    }
    return best;
}

int first() {
    int best = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int maxx = min(min(i+1, j+1), min(N-i, M-j)); 
            for(int k=0; k<maxx; k++) {
                if (T[i+k][j]) break;
                if (T[i-k][j]) break;
                if (T[i][j+k]) break;
                if (T[i][j-k]) break;
                //cout << "    >" << k << " " <<  T[i+k][j] << " " << T[i-k][j] << " " << T[i][j+k] << " " << T[i][j-k] << endl;
                int sec = second(i, j, k);
                //cout << " " << i << " " << j << " " << (k*4+1) << " " << sec << endl;
                best = max(best, (k*4+1) * sec);
            }
        }
    }
    return best;
}

int main() {
    while(cin >> N >> M) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                char temp; cin >> temp;
                T[i][j] = temp == 'G' ? 0 : 1;
                //cout << " " << T[i][j];
            }
            //cout << endl;
        }    
        cout << first() << endl;
    }
}
