#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define ull long long

using namespace std;

bool T[1010][1010];

char low(char c) {
    if (c >= 'A' and c <= 'Z')
        return c-'A'+'a';
    return c;
}

int main() { 
    int test; cin >> test;
    string a, b;
    while(cin >> a >> b) {
        memset(T, 0, sizeof T);
    
        T[0][0] = true;
        
        for(int i=0; i<a.size() and a[i] >= 'a' and a[i] <= 'z'; i++)
            T[i+1][0] = true;
        
        for(int i=0; i<a.size(); i++) {
            for(int j=0; j<b.size(); j++) {
                bool upper = low(a[i]) != a[i];
                if (upper) {
                    if (a[i] == b[j])
                        T[i+1][j+1] = T[i][j]; 
                    else
                        T[i+1][j+1] = false;
                } else if (low(a[i]) == low(b[j])) {
                    T[i+1][j+1] = T[i][j] or T[i][j+1];
                } else {
                    T[i+1][j+1] = T[i][j+1];
                }
                //cout << " " << T[i+1][j+1];
            }
            //cout << endl;
        }
        
        
        cout << (T[a.size()][b.size()] ? "YES" : "NO") << endl;
            
    }
}   
