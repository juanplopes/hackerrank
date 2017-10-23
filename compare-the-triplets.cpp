#include<iostream>
using namespace std;

int main() {
    int a1, a2, a3, b1, b2, b3;
    while(cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3) {
        int x = (a1 > b1) + (a2 > b2) + (a3 > b3); 
        int y = (a1 < b1) + (a2 < b2) + (a3 < b3);
        cout << x << " " << y << endl;
    }
}
