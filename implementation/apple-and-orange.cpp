n#include <iostream>
using namespace std;

int main() {
    int S, T, A, B, N, M;
    while(cin >> S >> T >> A >> B >> N >> M) {
        int ca = 0, cb = 0;
        for(int i=0; i<N; i++) {
            int temp; cin >> temp;
            if (S <= A+temp and A+temp <= T)
                ca++;
        }
        for(int i=0; i<M; i++) {
            int temp; cin >> temp;
            if (S <= B+temp and B+temp <= T)
                cb++;
        }
        cout << ca << endl;
        cout << cb << endl;
    }
}
