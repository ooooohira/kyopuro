#include<iostream>
#include<algorithm>
#include<bitset>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<bitset<3001>> edge(N);
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      char c;
      cin >> c;
      if(c == '1')
	edge[i].set(j);      //j桁目に1をセット。ll とかつかってのちにbitsetに変換するのはやめとけ
    }
  }
  long long ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = i+1;j < N;j++){
      if(!edge[i][j])continue;
      ans += (edge[i] & edge[j]).count(); //1が立っているbitの数を数える
    }
  }
  cout << ans / 3 << endl;
}
