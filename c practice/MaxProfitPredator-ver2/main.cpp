#include <iostream>
using namespace std;
using ll = long long;
const int MAX_N = 1000000;

int d;
ll p[MAX_N];
void solve(){
    ll total = 0;
    cin >> d;
    for(int i = 0; i < d; i++) cin >> p[i];
    for(int i = 1; i < d; i++){
        if(p[i] > p[i - 1]){
            total += p[i] - p[i - 1];
        }
    }
    cout << total << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}