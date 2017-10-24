#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    int a, b, c; char SEP;
    string s;
    
    while(cin >> a >> SEP >> b >> SEP >> c >> s) {
        if (s == "PM") if (a != 12) a += 12;
        if (s == "AM") if (a == 12) a = 0;
        cout.fill('0');
        cout << setw(2) << a << ":" << setw(2) << b << ":" << setw(2) << c << endl;
    }
}
