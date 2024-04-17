#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y){
    return y ? gcd(y, x%y) : x;
}
int main() {
    ll a, b;
    cin>>a>>b;

    ll k=gcd(a, b);
    if(b==a){
        cout<<0;
        return 0;
    }
    else if(k==0){
        if(b>a){
            swap(a,b);
        }
        cout<<a/b-1;
        return 0;
    }
    a/=k;
    b/=k;
    if(b>a){
        swap(a,b);
    }

    ll ans=0;
    while(true){
        if(a%b==0){
            ans+=a/b-1;
            cout<<ans;
            return 0;
        }
        else{
        ans+=a/b;
        a%=b;
        if(a==b){
            cout<<ans;
            return 0;
        }
        if(b>a){
            swap(a,b);
        }
        }
    }
}