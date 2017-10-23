#include<iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        long long sum = 0;
        for(int i=0; i<n; i++) {
            long long temp;
            cin >> temp;
            sum += temp;
        }
        cout << sum << endl;
    }
}
