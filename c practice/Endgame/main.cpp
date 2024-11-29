#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX_N = 1000;
int n, m;
int ans;
int d;
char table[MAX_N + 1][MAX_N + 1];
queue<tuple<int, int, int>> q;

int bfs(){
    while(!q.empty()){
        // position(x, y) and distance s
        auto [x, y, dis] = q.front();
        q.pop();
        if(x < 0 || n <= x) continue;
        if(y < 0 || m <= y) continue;
        if(table[x][y] == 'C') continue;
        if(table[x][y] == 'T'){
            ans = max(ans, dis);
            --d;
        }
        //set (x, y) as visted
        table[x][y] = 'C';
        q.push({x + 1, y, dis + 1});
        q.push({x - 1, y, dis + 1});
        q.push({x, y + 1, dis + 1});
        q.push({x, y - 1, dis + 1});
    }
    return ans;
}

int main(){
    d = ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> table[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(table[i][j] == 'I') q.push({i, j, 0});
            else if (table[i][j] == 'T') d++;
        }
    }
    bfs();
    if(d != 0) cout << "-1" << endl;
    else cout << ans << endl;
}