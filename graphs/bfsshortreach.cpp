#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

int V[100100];
vector<int> G[100100];
queue<Edge> Q;

int main() {
    int test; cin >> test;
    long long N, M;
    while(cin >> N >> M) {
        for(int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        int start; cin >> start;
        
        memset(V, -1, sizeof V);
       
        Q.push(Edge(start, 0));
        while(!Q.empty()) {
            Edge e = Q.front(); Q.pop();
            for(int i=0; i<G[e.v].size(); i++) {
                int u = G[e.v][i];
                if (V[u] == -1) {
                    V[u] = e.w + 6;
                    Q.push(Edge(u, e.w+6));
                }
            }
        }
       
        for(int i=1; i<=N; i++) {
            G[i].clear();
            if (i!=start)
                cout << (i==1 || start==1 and i==2 ? "" : " ")  << V[i];
        }
        cout << endl;
       
    }
}
