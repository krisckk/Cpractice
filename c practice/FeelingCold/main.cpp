#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<long long> SET;
vector<long long> arrayA;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while(testcase--){
        string type;
        cin >> type;
        if(type == "insert"){
            long long num;
            cin >> num;
            SET.insert(num);
            arrayA.push_back(num);
        }
        else if (type == "min"){
            if(!SET.empty()) cout << *SET.begin() << endl;
        }
        else if (type == "max"){
            if(!SET.empty()) cout << *SET.rbegin() << endl;
        }
        else if (type == "find"){
            long long idx;
            cin >> idx;
            if(idx > arrayA.size()){}
            else cout << arrayA[idx - 1] << endl;
        }
        else if (type == "amount"){
            long long num;
            cin >> num;
            long long ans = count(arrayA.begin(), arrayA.end(), num);
            cout << ans << endl;
        }
    }
    return 0;
}