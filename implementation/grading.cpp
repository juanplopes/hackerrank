#include <iostream>
using namespace std;

int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            int temp; cin >> temp;
            int rounded = (temp%5 >= 3) ? temp + (5 - temp%5) : temp;
            cout << (rounded >= 40 ? rounded : temp) << endl;
        }
    }
}
