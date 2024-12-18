#include <iostream>
#include <array>
#include <string>
using namespace std;
constexpr int MAX_N = 2000;

int n;
array<bool, MAX_N> visited;
array<array<bool, 26>, MAX_N> hasLetter; 

bool connected(int x, int y){
    for(int i = 0; i < 26; ++i){
        if(hasLetter[x][i] && hasLetter[y][i]) return true;
    }
    return false;
}

void dfs(int now){
    visited[now] = true;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        if(connected(now, i)) dfs(i);
    }
}
void solve() {
    visited.fill(false);
    hasLetter.fill({false});
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        for(const char & c : str){
            hasLetter[i][c - 'a'] = true;
        }
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            dfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase;
    cin >> testcase;
    while(testcase--) solve();
    return 0;
}