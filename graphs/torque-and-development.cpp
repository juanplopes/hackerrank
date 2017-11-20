#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool V[100100];
vector<int> G[100100];

void dfs(int v) {
    V[v] = true;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (V[u]) continue;
        dfs(u);
    }
}

int main() {
    int test; cin >> test;
    long long N, M, CL, CR;
    while(cin >> N >> M >> CL >> CR) {
        for(int i=1; i<=N; i++) G[i].clear();
        
        for(int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        memset(V, 0, sizeof V);
       
        int comps = 0;
        for(int i=1; i<=N; i++) {
            if (!V[i]) {
                comps++;
                dfs(i);            
            }
        }
       
        cout << min(N*CL, comps*CL + (N-comps)*CR) << endl;
    }
}
