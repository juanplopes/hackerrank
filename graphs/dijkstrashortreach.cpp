#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    
    inline bool operator <(const Edge& that) const {
        return w>that.w;
    }
};

int V[100100];
int G[3030][3030];
priority_queue<Edge> Q;

int main() {
    std::ios::sync_with_stdio(false);
    int test; cin >> test;
    long long N, M;
    while(cin >> N >> M) {
        memset(G, 0x3f, sizeof G);
        for(int i=0; i<M; i++) {
            int a, b, w; cin >> a >> b >> w;
            G[a][b] = G[b][a] = min(G[a][b], w);
        }
        int start; cin >> start;
        
        memset(V, -1, sizeof V);
       
        Q.push(Edge(start, 0));
        V[start] = 0;
        while(!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            for(int i=1; i<=N; i++) {
                if (G[e.v][i] == 0x3f3f3f3f) continue;
                
                Edge e2 = Edge(i, G[e.v][i]);
                if (e.w+e2.w < V[e2.v] or V[e2.v] == -1) {
                    V[e2.v] = e.w + e2.w;
                    Q.push(Edge(e2.v, e.w+e2.w));
                }
            }
        }
       
        for(int i=1; i<=N; i++) {
            if (i!=start)
                cout << (i==1 || start==1 and i==2 ? "" : " ")  << V[i];
        }
        cout << endl;
       
    }
}
