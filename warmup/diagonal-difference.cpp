#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int x = 0, y = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int temp;
                cin >> temp;
                if (i==j) x+=temp;
                if (i+j == n-1) y+=temp;
            }
        }
        cout << abs(y-x) << endl;
    }
}
