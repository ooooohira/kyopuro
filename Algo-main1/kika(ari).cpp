#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double EPS=1e-10;

//誤差を考慮した足し算
double add(double a, double b){
    if(abs(a+b)<EPS)return 0;
    else return a+b;
}

struct P{
    double x, y;
    P(){}
    P(double x, double y) : x(x), y(y){
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d){
        return P(x*d, y*d);
    }
    double dot(P p){//内積
        return add(x*p.x,y*p.y);
    }
    double det(P p){//外積
        return add(x*p.y,-y*p.x);
    }
};

