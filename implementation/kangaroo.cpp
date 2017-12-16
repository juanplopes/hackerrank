#include <iostream>
using namespace std;

int main() {
    int x1, v1, x2, v2;
    while(cin >> x1 >> v1 >> x2 >> v2) {
        cout << (v1 != v2 and (x1 - x2) % (v2 - v1) == 0 and (x1 - x2) / (v2 - v1) >= 0 ? "YES" : "NO") << endl;
    }
}
