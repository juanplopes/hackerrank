#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;


struct Edge {
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

vector<int> G[110];
map<int, int> T;
int V[110];
queue<Edge> Q;

int main() {
    int test; cin >> test;
    long long N, M;
    while(cin >> N) {
        T.clear();
        for(int i=1; i<=100; i++) G[i].clear();
        
        for(int i=0; i<N; i++) {
            int a, b; cin >> a >> b;
            T[a] = b;
        }
        cin >> N;
        for(int i=0; i<N; i++) {
            int a, b; cin >> a >> b;
            T[a] = b;
        }
                
        for(int i=1; i<100; i++) {
            for(int j=1; j<=6 and i+j <= 100; j++) {
                int target = i+j;
                if (T[target]) target = T[target];
                G[i].push_back(target);
            }
        }
       
        memset(V, -1, sizeof V);
       
        Q.push(Edge(1, 0));
        while(!Q.empty()) {
            Edge e = Q.front(); Q.pop();
            for(int i=0; i<G[e.v].size(); i++) {
                int u = G[e.v][i];
                if (V[u] == -1) {
                    V[u] = e.w + 1;
                    Q.push(Edge(u, e.w+1));
                }
            }
        }
        
        cout << V[100] << endl;
              
    }
}
