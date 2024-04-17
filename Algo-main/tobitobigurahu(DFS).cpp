#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
int ma=1;
set<int> dp1;//探査済みか
map<int, vector<int>> dp;//
 
void dfs(int tansa){
    dp1.insert(tansa);
    if(ma<tansa)ma=tansa;
    for(auto i : dp[tansa]){
        if(dp1.find(i)!=dp1.end()){
        continue;
        }
        else
        dfs(i);
    }        
};
 
int main() {
    // 入力
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        int a,b;
        cin >> a >> b;
        dp[a].push_back(b);
        dp[b].push_back(a);
    }
    dp[1].push_back(1);
    if(dp[1].size()==1){cout<<1;return 0;}
 
 
    dfs(1);
    cout << ma;
}