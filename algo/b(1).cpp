#include<bits/stdc++.h>
 
using namespace std;
long long inf=100000000000000000;//これ以上0増やすと-かけた時バグる。これが限界の大きさ
int main(){
  long long l,r;
  cin >> l >> r;
  long long res=0;
  vector<int> cnt(1048576,0);
  for(long long i=2;i<=r;i++){
    if(cnt[i]!=0){continue;}
    for(long long j=i;j<=r;j+=i){cnt[j]++;}
    for(long long j=i*i;j<=r;j+=i*i){cnt[j]=-inf;}//同じ素因数を持つものを無効化
  }


  for(long long i=2;i<=r;i++){
    if(cnt[i]<0){continue;}
    long long cc=(r/i)-((l-1)/i);
    if(cnt[i]%2){res+=(cc*(cc-1))/2;}
    else{res-=(cc*(cc-1))/2;}
  }
  for(long long i=max(2ll,l);i<=r;i++){res-=(r/i-1);}
  cout << 2*res << '\n';
  return 0;
}
