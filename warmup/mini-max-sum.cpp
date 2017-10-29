#include<iostream>
using namespace std;

int main() {
    long long a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e) {
       long long ma = max(a, max(b, max(c, max(d, e))));
       long long mi = min(a, min(b, min(c, min(d, e))));
       long long su = a+b+c+d+e;
       cout << su - ma << " " << su - mi << endl;
    }
}
