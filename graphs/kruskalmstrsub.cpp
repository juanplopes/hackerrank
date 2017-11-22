#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Edge {
    int a, b, w;
    Edge(int a, int b, int w) : a(a), b(b), w(w) {}
    inline bool operator<(Edge &that) {
        return w<that.w;
    }
};

vector<Edge> E;
int P[4000];

inline int findset(int v) {
    if (P[v] == v) return v;
    return P[v] = findset(P[v]);
}

inline void unionset(int x, int y) {
    int a = findset(x), b = findset(y);
    if (a==b) return;
    if (a<b) swap(a,b);
    P[b] = a;
}

int main() {
//    int test; cin >> test;
    long long N, M;
    while(cin >> N >> M) {
        for(int i=1; i<=N; i++) P[i] = i;
        for(int i=0; i<M; i++) {
            int a, b, w; cin >> a >> b >> w;
            E.push_back(Edge(a, b, w));
        }
        sort(E.begin(), E.end());

        int total = 0, cnt = 0;
        for(int i=0; i<E.size() and cnt+1 != N; i++) {
            int aa = findset(E[i].a), bb = findset(E[i].b);
            if (aa != bb) {
                total += E[i].w;
                unionset(aa, bb);
                cnt++;
            }
        }
        cout << total << endl;
       
    }
}
