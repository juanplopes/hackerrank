#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

long long turan(long long N, long long K) {
    return (N*N - N%K*pow(ceil(N/(double)K), 2) - (K - N%K)*pow(floor(N/(double)K), 2))/2;
}

int main() {
    int test; cin >> test;
    long long N, M;
//    cout << turan(19, 13) << endl;
    while(cin >> N >> M) {
        long long first = 2, count = N-1;
       /* for(int i=1; i<=N; i++) {
            cout << " " << N << " " << M << ": " << i << " " << turan(N, i) << endl;
        }*/
        
        while (count>0) {
            long long step = count/2; 
            long long it = first+step; 

            if (turan(N, it) < M) { 
                first = ++it; 
                count -= step+1;  
            } else count = step;
        }
        cout << first << endl;
    }
}
