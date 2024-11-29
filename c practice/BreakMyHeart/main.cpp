#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
using namespace std;

void print(){}
int main(){
    long long integer;
    cin >> integer;
    set<long long> SET;
    while (integer--)
    {
        string type;
        cin >> type;
        if (type == "print")
        {
            if(SET.begin() != SET.end()){
                // Each number in the set is seperated by a single blank(No blank at the end!)
                for(auto it = SET.begin(); it != SET.end(); it++){
                    if(it != SET.begin()) cout << " ";
                    cout << *it;
                }
                cout << endl;
            }
        }
        else if(type == "range_erase"){
            long long a, b;
            cin >> a >> b;
            SET.erase(SET.lower_bound(a), SET.upper_bound(b));
        }
        else if(type == "min"){
            auto i = SET.begin();
            if(i != SET.end()) cout << *i << endl;
        }
        else if(type == "insert"){
            long long INT;
            cin >> INT;
            SET.insert(INT);
        }
        else if(type == "sum"){
            long long SUM = accumulate(SET.begin(), SET.end(), 0);
            cout << SUM << endl;
        }
        
    }
    return 0;
}