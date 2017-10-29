//counting knapsack
#include<iostream>
#include<cstring>
using namespace std;

unsigned long long T[1000];

int main() {
    int N, M;
    while(cin >> N >> M) {
        memset(T, 0, sizeof T);
               
        T[0] = 1;
        for(int i=0; i<M; i++) {
            int C; cin >> C;
            for(int i=C; i<=N; i++) {
                T[i] += T[i-C];
            }
        }
    
        cout << T[N] << endl;
    }
}
