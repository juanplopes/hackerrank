#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int v, mask;
    long long w;
    Edge(int v, long long w) : v(v), w(w), mask(0) {}
    Edge(int v, long long w, int mask) : v(v), w(w), mask(mask) {}
    
    inline bool operator<(const Edge& that) const {
        return w > that.w;
    }
};

int S[1100];
long long T[1100][1100];
priority_queue<Edge> Q;
vector<Edge> G[1100];

int main() {
    int N, M, K;
    while(cin >> N >> M >> K) {
        int KK = 1<<K;
        
        memset(S, 0, sizeof S);
        while(Q.size()) Q.pop();
        
        for(int i=0; i<N; i++) {
            G[i].clear();
            int cnt; cin >> cnt;
            for(int j=0; j<cnt; j++) {
                int temp; cin >> temp;
                S[i] |= 1<<(temp-1);
            }            
        }
        
        for(int i=0; i<M; i++) {
            int a, b, w; cin >> a >> b >> w;
            a--; b--;
            G[a].push_back(Edge(b, w));
            G[b].push_back(Edge(a, w));
        }
        
        for(int i=0; i<N; i++)
            for(int j=0; j<KK; j++) 
                T[i][j] = 1000000000;
            
        Q.push(Edge(0, 0, S[0]));
        T[0][S[0]] = 0;
        int count = 0;
        while(!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            
            for(int i=0; i<G[e.v].size(); i++) {
                Edge e2 = G[e.v][i];
                int u = e2.v;
                long long w = e.w+e2.w;
                int mask = e.mask | S[e2.v];
                
                if (w < T[u][mask]) {
                    //cout << " " << u << " " << mask << " " << w << " " << T[u][mask] << endl;
                    T[u][mask] = w;
                    Q.push(Edge(u, w, mask));
                }
            }
        }

        long long minn = 1000000000000ll;
        for(int i=0; i<KK; i++) {
            for(int j=0; j<KK; j++) {
                if ((i|j) != KK-1) continue;
                //cout << " " << i << " " << j << " " << T[N-1][i] << " " << T[N-1][j] << endl;
                minn = min(minn, max(T[N-1][i], T[N-1][j]));
            }
        }
        //cout << endl;
        cout << minn << endl;
    }
}
