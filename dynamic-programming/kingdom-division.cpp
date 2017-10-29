#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#define M 1000000007
using namespace std;

vector<int> G[100010];
long long V1[100010], V2[100010];

long long H1(int p, int v);
long long H2(int p, int v);

long long H2(int p, int v) {
    if (V2[v] >= 0) return V2[v];
    long long total = 1;
    long long minus = 1;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        
        total *= (H1(v, u) + H2(v, u)) % M;
        total %= M;
        minus *= H2(v, u);
        minus %= M;
    }
    return V2[v] = ((total - minus) % M + M) % M;

}

long long H1(int p, int v) {
    if (V1[v] >= 0) return V1[v];
    long long total = 1;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        
        total *= (H1(v, u) + H2(v, u)) % M;
        total %= M;
    }
    return V1[v] = total;
}

int main() { 
    int N;
    while(cin >> N) {
        for(int i=0; i<=N; i++) {
            G[i].clear();
            V1[i] = V2[i] = -1;
        }   

        for(int i=0; i<N-1; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }    
        cout << (2*H2(-1, 1))%M << endl;
    }
}   
