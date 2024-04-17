#include <iostream>
using namespace std;

ll GCD(ll a, ll b){
  if(a==0)return b;
  if(b==0)return a;
  if(a%b == 0){
    return b;
  }else{
    return GCD(b, a%b);
  }
}

int main() {
    cout << GCD(51, 15) << endl; // 3 が出力される
    cout << GCD(15, 51) << endl; // 3 が出力される
}