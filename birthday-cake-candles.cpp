#include<iostream>
using namespace std;

int T[100100];

int main() {
    int N;
    while(cin >> N) {
        int maxx = -1;
        int count = 0;
        for(int i=0; i<N; i++) {
            cin >> T[i];
            maxx = max(maxx, T[i]);
        }
        for(int i=0; i<N; i++) {
            if (T[i] == maxx) 
                count++;
        }
        cout << count << endl;
    }
}
