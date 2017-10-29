#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string S[300000];

bool compare(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for(int i=0; i<a.size(); i++)
        if (a[i] != b[i])
             return a[i] < b[i];
    
    return false;
}

int main() {
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++)
            cin >> S[i];
        sort(S, S+N, compare);
        for(int i=0; i<N; i++)
            cout << S[i] << endl;
    }
}
