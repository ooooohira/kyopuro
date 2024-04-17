#include <iostream>
using namespace std;

//参照で解を得る
int extgcd(int a, int b, int& x, int& y){//ax+by=gcd(a,b)を求めるo(logmax(a,b))
    int d=a;
    if(b!=0){
        d=extgcd(b, a%b, y, x);
        y-=(a/b)*x;
    }
    else{
        x=1;
        y=0;
    }
    return d;//ここではgcdをかえす、特に意味はないが
}


int main(){
    int a, b;
    a=5;
    b=3;
    int &x=a;
    int &y=b;
    extgcd(a,b,x,y);
    cout<<x<<endl<<y;

}