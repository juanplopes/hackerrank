#include<iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        double a = 0, b = 0, c = 0;
        for(int i=0; i<n; i++) {
            int temp; cin >> temp;
            if (temp > 0) a++;
            if (temp < 0) b++;
            if (temp == 0) c++;
        }
        cout << a/n << endl;
        cout << b/n << endl;
        cout << c/n << endl;
    }
}
