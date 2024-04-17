#include<bits/stdc++.h>
using namespace std;
long long kaizyou(long long N){
    long long ans=1;
    for(int i=1;i<=N;i++){
        ans*=i;
    }
    return ans;
};


double logteira(double x){
    return x-pow(x,2)/2+pow(x,3)/3-pow(x,4)/4+pow(x,5)/5-pow(x,6)/6;
}

int main() {
double ans=0;
double gosa=0;
double kaiseki=0;
double x=-0.5*M_PI;
while(x<=0.5*M_PI){
    ans=logteira(x);
    kaiseki=log(x+1);
    cout<<"x:"<<x<<" ";
    cout<<"kinzikai:"<<ans<<" ";
    cout<<"log(x+1):"<<kaiseki<<" ";
    cout<<"gosa:"<<ans-x<<endl;
    x+=0.1;
}

}