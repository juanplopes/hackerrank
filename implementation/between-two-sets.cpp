#include <iostream>
using namespace std;

int A[110], B[110];

int main() {
    int N, M;
    while(cin >> N >> M) {
        for(int i=0; i<N; i++) cin >> A[i];
        for(int i=0; i<M; i++) cin >> B[i];
        
        int count = 0;
        for(int i=1; i<=100; i++) {
            bool ok = true;
            for(int j=0; j<N and ok; j++) 
                if (i % A[j] != 0)
                    ok = false;
            for(int j=0; j<M and ok; j++) 
                if (B[j] % i != 0)
                    ok = false;
            if (ok) count++;
        }
        cout << count << endl;
    }
}
