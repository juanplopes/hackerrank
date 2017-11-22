#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> G[110];

bool dfs(int p, int v, int &cnt) {
    int odd = 0;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i];
        if (u == p) continue;
        if (dfs(v, u, cnt)) cnt++;
        else odd++;
    }
    return odd % 2 == 1;
}

int main() {
    long long N, M;
    while(cin >> N >> M) {
        for(int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        int count = 0;
        dfs(-1, 1, count);
        cout << count << endl;
       
    }
}
