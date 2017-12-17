#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100100
using namespace std;

int T[1010], B[1010], V[1010];

int pos(int N, int v) {
    return lower_bound(B, B+N, v) - B;
}

int main() {
    int tests; cin >> tests;
    int N;
    while(cin >> N) {
        memset(V, 0, sizeof V);
        for(int i=0; i<N; i++) {
            cin >> T[i];
            B[i] = T[i];
        }    
        sort(B, B+N);
        int total = 0;
        for(int i=0; i<N; i++) {
            if (V[i]) continue;
            
            //cout << " :" << i;
            int cnt = 0;
            while(!V[i]) {
                V[i] = true;
                i = pos(N, T[i]);
                //cout << " " << i;
                cnt++;
            }
            total += cnt-1;
            //cout << endl;
        }
        cout << (total%2==0 ? "YES" : "NO") << endl;        
    }
}
