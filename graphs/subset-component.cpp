#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#define ull unsigned long long
using namespace std;

ull D[30];
set<ull> S;

int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++)
            cin >> D[i];
        
        ull total = 0;
        for(int i=0; i<(1<<N); i++) {
            S.clear();
            for(int j=0; j<N; j++) {
                if (i&(1<<j)) {
                    ull x = D[j];
                    for(set<ull>::iterator it = S.begin(); it != S.end(); it++) {
                        if ((*it) & x) {
                            x |= *it;
                            S.erase(it);
                        } 
                    }
                    S.insert(x);
                }
            }
            
            int count = 64;
            for(set<ull>::iterator it = S.begin(); it != S.end(); it++) {
                 
                //cout << " " << *it;
                int c = __builtin_popcountll(*it);
                count -= max(c - 1, 0);
            }
            total += count;
            //cout << ": " << count << endl;
        }
        cout << total << endl;
    }
}
