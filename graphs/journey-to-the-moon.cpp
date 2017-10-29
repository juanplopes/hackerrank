//union-find
#include<iostream>
#include<cstring>
using namespace std;

int P[100100];
int C[100100];

inline int findset(int v) {
    if (P[v] == v) return v;
    return P[v] = findset(P[v]);
}

inline void unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return;
    if (a<b) swap(a,b);
    P[b] = a;
    C[a] += C[b];
}

int main() {
    int N, M;
    while(cin >> N >> M) {
        for(int i=0; i<N; i++) {
            P[i] = i;
            C[i] = 1;
        }
       
        for(int i=0; i<M; i++) {
            int a, b;
            cin >> a >> b;
            unionset(a, b);
        }
    
        long long result = 0;
        long long sum = 0;
        for(int i=0; i<N; i++) {
            if (P[i] == i) {
                //cout << " " << i << " " << findset(i) << " " << C[i] << endl;
                result += C[i] * sum;
                sum += C[i];
            }
        }
        cout << result << endl;
    }
}
