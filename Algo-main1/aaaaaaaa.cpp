#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
set<int> dp1;
vector<vector<double>> eq(3, vector<double> (4, 0));
vector<int> zyunzyo(3);
vector<double> kai={0.0,0.0,0.0};
void gausu(int n){
for(int i=0; i<n; i++){//後退代入
int t=0;
for(int k=0;k<n;k++){
if(dp1.find(k)!=dp1.end())continue;
if(i==n-1){
t=k;
continue;
}
if(eq[i][t]<eq[i][k]){
t=k;
}
}
zyunzyo.push_back(t);
for(int j=i+1;j<n;j++){//前進消去
double b=eq[j][t]/eq[i][t];
for(int l=0;l<n;l++){
eq[j][l]=eq[j][l]-(eq[i][l]*b);
}
eq[j][n]=eq[j][n]-(eq[i][n]*b);
}
}
reverse(zyunzyo.begin(), zyunzyo.end());

for(int h=1;h<=n;h++){
int a=zyunzyo[h-1];
int u=n-h;
kai[a]=eq[u][n]/eq[u][a];
if(h==1)continue;
for(int y=1;y<h;y++){
int x=zyunzyo[y-1];
kai[a]=kai[a]-(kai[x]*eq[u][x])/eq[u][a];
}
}
for(auto a : kai){
cout<<a<<" ";
}
cout<<endl;
};

vector<double> Dg(3,0.5);
vector<vector<double>> G(3, vector<double> (3, 0.0));
vector<double> b={5.0,-4.0,3.0};
vector<double> kai1={1,-2,3};
vector<double> kai2(3, 0.0);
void yakobi(int n){
int res=0;
while(true){
for(int i=0;i<n;i++){
double x=0;
for(int j=0;j<n;j++){
x=x+G[i][j]*kai1[j];
}
kai2[i]=Dg[i]*(b[i]-x);
}
for(int y=0; y<n;y++){
kai1[y]=kai2[y];
}
res++;

if(abs(kai1[0]-1)<1e-6&&abs(kai1[1]+2)<1e-6&&abs(kai1[2]-3)<1e-6)break;

if(res>1000)break;
}
for(auto a : kai1){
cout<<a<<" ";
}
cout<<endl;
cout<<res;
cout<<endl;
};

vector<vector<double>> U(3,vector<double>(3,0.0));
vector<vector<double>> DL(3, vector<double> (3, 0.0));
vector<double> b1={5.0,-4.0,3.0};
vector<double> kai3={1.1,-2.1,2.9};
vector<double> kai4(3, 0.0);
void gausuzaidel(int n){
int res=0;
while(true){
for(int i=0;i<n;i++){
double x=0;
for(int j=0;j<n;j++){
x=x+U[i][j]*kai3[j];
}
kai4[i]=(b[i]-x);
}
for(int j=0;j<n;j++){
double x=0;
for(int d=0;d<n;d++){
x=x+DL[j][d]*kai4[d];
}
kai3[j]=x;
}
res++;

if(abs(kai3[0]-1)<1e-6&&abs(kai3[1]+2)<1e-6&&abs(kai3[2]-3)<1e-6)break;

if(res>1000)break;
}
for(auto a : kai3){
cout<<a<<" ";
}
cout<<endl;
cout<<res;
cout<<endl;
};

int main() {
eq[0]={2.0,3.0,3.0,5.0};//2x+3y+3z=5,3x+2y-z=-4,5x+4y+2z=3
eq[1]={3.0,2.0,-1.0,-4.0};
eq[2]={5.0,4.0,2.0,3.0};
gausu(3);
G[0]={0,3.0,3.0};//2x+3y+3z=5,3x+2y-z=-4,5x+4y+2z=3
G[1]={3.0,0,-1.0};
G[2]={5.0,4.0,0};
yakobi(3);
U[0]={0,3.0,3.0};//2x+3y+3z=5,3x+2y-z=-4,5x+4y+2z=3
U[1]={0,0,-1.0};
U[2]={0,0,0};
DL[0]={0.5,0,0};//2x+3y+3z=5,3x+2y-z=-4,5x+4y+2z=3
DL[1]={-3.0/4.0,0.5,0};
DL[2]={0.25,-1.0,0.5};
gausuzaidel(3);
}