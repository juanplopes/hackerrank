#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#define ull unsigned long long
using namespace std;

struct Guess {
    int a, b;
    Guess(int a, int b) : a(a), b(b) { }
    
    inline bool operator<(const Guess &that) const {
        if (a != that.a) return a < that.a;
        return b < that.b;
    }
};

vector<int> G[100100];
map<Guess, int> D;

int dfs1(int p, int v) {
    int total = D[Guess(p, v)];    
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        total += dfs1(v, u);
    }
    return total;
}

int dfs2(int p, int v, int K, int points) {
    points += D[Guess(v, p)] - D[Guess(p, v)];
    int total = points >= K ? 1 : 0;
    
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        total += dfs2(v, u, K, points);
    }
    return total;
}

int gcd(int a, int b) {
    while(b) {
        int c = a%b; a = b; b = c;
    }
    return a;
}

int main() {
    int test; cin >> test;
    int N, GE, K;
    while(cin >> N) {
        D.clear();
        for(int i=1; i<=N; i++) G[i].clear();
        
        for(int i=0; i<N-1; i++) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cin >> GE >> K;
        for(int i=0; i<GE; i++) {
            int a, b; cin >> a >> b;
            D[Guess(a, b)]++;
        }
        
        int points = dfs1(-1, 1);
        int success = dfs2(-1, 1, K, points);
        
        int D = gcd(success, N);
        if (success == 0)
            cout << "0/1" << endl;
        else
            cout << success/D << "/" << N/D << endl;
    }
}
