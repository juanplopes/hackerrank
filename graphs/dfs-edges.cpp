#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void solve(int N, int X, int &s1, int &s2) {
    s1 = 0;
    for(int i=1; X - i >= N; i++) {
        X -= i;
        N--;
        s1 = i;
    }
    s2 = X-N+1;
}

vector<int> G[100100];

void edges(string t, int v, int& var, int a, int b) {
    for(int i=a; i<=b and var; i++) {
        //cout << " " << t << " " << v << " " << i << endl;
        G[v].push_back(i);
        var--;
    } 
}

int main() {
    int T, B, F, C;
    while(cin >> T >> B >> F >> C) {
        int N = T+1;
        int X = max(T+F, B);
        int Y = C;
        if (2*X+Y > N*(N-1)) {
            cout << -1 << endl;
            continue;
        }
        
        int s1, s2;
        solve(T, X, s1, s2);
        
        int M1 = 2, M2 = 1+s1;
        int AP1 = s2, AP2 = M2 + 1;
        
        //cout << " " << X << " " << T << " " << s1 << " " << s2 << "| " << M1 << " " << M2 << " " << AP1 << " " << AP2 << endl;
        
        for(int i=1; i<=N; i++)
            G[i].clear();
        
        //first node
        edges("T", 1, T, 2, min(2,AP2-1));
        edges("F", 1, F, 3, M2);
        if (AP1 == 1)
            edges("T", 1, T, AP2, AP2);
        else
            edges("F", 1, F, AP2, AP2);
        
        edges("T", 1, T, M2+2, N);
        
        //mainline
        for(int i=M1; i<=M2; i++) {
            edges("B", i, B, 1, i-1);              
            
            if (i<M2)
                edges("T", i, T, i+1, i+1);
            
            edges("F", i, F, i+2, M2);
            
            if (i<AP1)
                edges("F", i, F, AP2, AP2);
            else if (i==AP1)
                edges("T", i, T, AP2, AP2);
        }
        //appendix
        edges("B", AP2, B, 1, AP1);
        edges("C", AP2, C, AP1+1, M2);
        
        for(int i=AP2+1; i<=N; i++) {
            edges("B", i, B, 1, 1);
            edges("C", i, C, 2, i-1);
        }

        if (T|B|C|F) {
            //cout << " " << T << " " << B << " " << C << " " << F << endl;
            cout << -1 << endl;
        } else {
            cout << N << endl;
            for(int i=1; i<=N; i++) {
                cout << G[i].size();
                for(int j=0; j<G[i].size(); j++) {
                    cout << " " << G[i][j];
                }
                cout << endl;
            }
        }
        
        
    }

}
