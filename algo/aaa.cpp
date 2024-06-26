#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <functional>
#include <stack>
#include <string>
#include <iomanip>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <bitset>
#include <bit>
#include <iomanip>
#include <cfloat>
#include <atcoder/segtree>
#include "atcoder/modint.hpp"
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <cmath>
#include <limits>
// using mint = atcoder::modint998244353;
using mint = atcoder::modint1000000007;
// auto a1=make_pair(1,1);
// auto a2=make_pair(-1,1);
// auto a3=make_pair(-1,-1);
// auto a4=make_pair(1,-1);
// auto a1=make_pair(1,0);
// auto a2=make_pair(-1,0);
// auto a3=make_pair(0,1);
// auto a4=make_pair(0,-1);
// vector<pair<ll, ll> > V(0);
// V.push_back(a1);
// V.push_back(a2);
// V.push_back(a3);
// V.push_back(a4);

using namespace std;
using ll = long long;
using llu = unsigned long long;
using dd = double;
using ddl = long double;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define pb push_back
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


// ll op(ll b, ll a){return max(a,b);}
// ll e(){ll k=0;return k;}
ll mo=998244353;
// ll sx,sy;
// ll ex,ey;
// cin>>sx>>sy>>ex>>ey;
// atcoder::segtree<int, op, e> seg();
ll inf=100000000000000000;//これ以上0増やすと-かけた時バグる。これが限界の大きさ,10^17条だよ
// sort(V.rbegin(),V.rend());//逆順ソート
// const long double EPS = 1e-10;
// ll N,M,K,H,W,T,Q;
// bool hantei(ll x, ll y){
//   if(x<H && x>=0 && y>=0 && y<W)return true;
//   return false;
// }

#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<vector>
#include<set>
using namespace std;



//ベクトルとしても使えるよ！
class Point {
    public:
    double x, y;

    Point(double x=0, double y=0): x(x), y(y) {}

    Point operator + (Point p) {return Point(x + p.x, y + p.y);}
    Point operator - (Point p) {return Point(x - p.x, y - p.y);}
    Point operator * (double a) {return Point(x * a, y * a);}
    Point operator / (double a) {return Point(x / a, y / a);}

    double abs() { return sqrt(norm());}
    double norm() {return x*x + y*y;}

    bool operator < (const Point &p) const {
        return x!=p.x ? x<p.x : y<p.y;
    }
    bool operator = (const Point &p) const {
        return fabs(x-p.x)<EPS && fabs(y-p.y) < EPS;
    }
};

double dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
//外積
double cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

//Segmentは線分か直線
class Segment {
    public:
    Point p1, p2;
    Segment(Point p1=Point(), Point p2=Point()): p1(p1), p2(p2) {}
};

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c=Point(), double r=0.0): c(c), r(r) {}
};


bool tyokkou(Point a, Point b){
    return equals(dot(a,b), 0.0);
}

bool heikou(Point a, Point b){
    return equals(cross(a,b), 0.0);
}

//直線への射影
Point project(Segment s, Point p){
    Point base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}



static const int COUNTERCLOCKWISE = 1;//半時計p0p1p2
static const int CLOCKWISE = -1;//時計回りp0p1p2
static const int ONLINE_p2p0p1 = 2;
static const int ONLINE_p0p1p2 = -2;
static const int ONLINE_p0p2p1 = 0;

int ccw(Point p0, Point p1, Point p2){
    Point a=p1-p0;
    Point b=p2-p0;
    if(cross(a,b)>EPS)return COUNTERCLOCKWISE;
    if(cross(a,b)<-EPS)return CLOCKWISE;
    if(dot(a,b)<-EPS)return ONLINE_p0p1p2;
    if(a.norm()<b.norm())return ONLINE_p0p2p1;
    return ONLINE_p0p2p1;
}

double abs(Point a, Point b){
    Point c=a-b;
    return c.abs();
}


//線分の交差判定,a,bは１つめの線分の両端、c,dは２つ目の線分の両端
bool intersect(Point a, Point b, Point c, Point d){
    return ( ccw(a,b,c)*ccw(a,b,d)<=0&&ccw(c,d,a)*ccw(c,d,b)<=0);
}

double getdistance(Point a, Point b){
    return (a-b).abs();
}

//直線と点の距離
double getdistance1(Segment l, Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 , l.p1));
}

//線分と点の距離
double getdistance2(Segment s, Point p){
    if (dot(s.p2-s.p1, p-s.p1) < 0.0) return abs(p,s.p1);
    if (dot(s.p1-s.p2, p-s.p2) < 0.0) return abs(p,s.p2);
    return getdistance1(s,p);
}

//線分と点の距離
double getdistance3(Segment s1, Segment s2){
    if (intersect(s1.p1,s1.p2,s2.p1,s2.p2)) return 0.0;
    return min(min(getdistance2(s1, s2.p1), getdistance2(s1, s2.p2)),min(getdistance2(s2, s1.p1), getdistance2(s2, s1.p2)));
}

//必ず交差する線分同士の交点
Point gtcrosspoint(Segment s1, Segment s2){
    Point base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

//２つの必ず交差する円の交点
double arg(Point p) {return atan2(p.y, p.x);}
Point polar(double a, double r){return Point(cos(r)*a, sin(r)*a);}

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
double d=abs(c1.c , c2.c);
double a=acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2*c1.r*d));
double t=arg(c2.c-c1.c);
return make_pair(c1.c + polar(c1.r, t+a), c1.c + polar(c1.r, t-a));
}

//点の内包
int contain(vector<Point> g, Point p){//gは多角形表す.INは2,ONは1,OUTは0を返す
    int n = g.size();
    bool x=false;
    for(int i=0;i<n;i++){
        Point a=g[i]-p, b=g[(i+1)%n]-p;
        if(abs(cross(a,b))<EPS&&dot(a,b)<EPS)return 1;
        if(a.y>b.y)swap(a,b);
        if(a.y<EPS&&EPS<b.y&&cross(a,b)>EPS)x=!x;
    }
    return (x?2:0);
}


//凸包アルゴリズム
typedef vector<Point> Polygon;
Polygon andrew(Polygon s){
    Polygon u, l;
    if(s.size()<3)return s;
    sort(s.begin(), s.end());
    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[s.size()-1]);
    l.push_back(s[s.size()-2]);

    for(int i=2;i<s.size();i++){
        for(int n=u.size(); n>=2&&ccw(u[n-2], u[n-1], s[i])!=CLOCKWISE;n--){
            u.pop_back();
        }
        u.push_back(s[i]);
    }
    for(int i=s.size()-3;i>=0;i--){
        for(int n=l.size(); n>=2&&ccw(l[n-2], l[n-1], l[i])!=CLOCKWISE;n--){
            l.pop_back();
        }
        l.push_back(s[i]);
    }
    reverse(l.begin(), l.end());
    for(int i=u.size()-2;i>=1;i--)l.push_back(u[i]);
    return l;//出力が左下の点から反時計回りでるようにしている
}



//平面走査
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint{
    public:
    Point p;
    int seg, st;//入力線分のID,端点の種類
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {//yが同一なら下、左、右、上点の順で入れる
        if(p.y == ep.p.y){
            return st < ep.st;
        }else return p.y < ep.p.y;
    }
};

EndPoint EP[2*100000];//端点のリスト

int heimensousa(vector<Segment> S){

    int n=S.size();

    for(int i=0, k=0;i<n;i++){
        if(S[i].p1.y==S[i].p2.y){
            if(S[i].p1.x>S[i].p2.y)swap(S[i].p1,S[i].p2);
        }else if(S[i].p1.y>S[i].p2.y)swap(S[i].p1,S[i].p2);
    if(S[i].p1.y==S[i].p2.y){
        EP[k++]=EndPoint(S[i].p1,i,LEFT);
        EP[k++]=EndPoint(S[i].p2,i,RIGHT);
    }else{
        EP[k++]=EndPoint(S[i].p1,i,BOTTOM);
        EP[k++]=EndPoint(S[i].p2,i,TOP);        
    }
    }
    sort(EP, EP + (2*n));
    set<int> BT;///二分探査木
    BT.insert(1000000001);//番兵を入れとく
    int cnt=0;

    for(int i=0;i<2*n;i++){
        if(EP[i].st==TOP){
            BT.erase(EP[i].p.x);
        }else if (EP[i].st==BOTTOM){
            BT.insert(EP[i].p.x);
        }else if(EP[i].st==LEFT){
            set<int>::iterator b=lower_bound(BT.begin(),BT.end(),S[EP[i].seg].p1.x);
            set<int>::iterator e=upper_bound(BT.begin(),BT.end(),S[EP[i].seg].p2.x);
            cnt+=distance(b,e);
        }
    }
    return cnt;
}



vector<Point> P(0);


double calc_dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double calc_r(Point p) {
    double r = 0;
    for (auto to: P) r = max(r, calc_dist(p, to));
    return r;
}

double calc_y(double x) {
    double low_y = 0;
    double high_y = 1000;
    int cnt = 500;
    while (cnt--) {
        double c1 = (low_y * 2 + high_y) / 3.0;
        double c2 = (low_y + high_y * 2) / 3.0;
        if (calc_r(Point(x, c1)) < calc_r(Point(x, c2))) high_y = c2;
        else low_y = c1;
    }
    return low_y;
}

int main() {
    ll X,Y;
    // ll A,B;
    ll N,M,T,Q,K;
    ll H,W;
    cin>>N;
    P.resize(N);
    rep(i,N){
      ll a,b;cin>>P[i].x>>P[i].y;      
    }

    double low_x = 0;
    double high_x = 1000;
    int cnt = 500;
    while (cnt--) {
        double c1 = (low_x * 2 + high_x) / 3.0;
        double c2 = (low_x + high_x * 2) / 3.0;
        if (calc_r(Point(c1, calc_y(c1))) < calc_r(Point(c2, calc_y(c2)))) high_x = c2;
        else low_x = c1;
    }
cout << fixed << setprecision(20) << calc_r(Point(low_x, calc_y(low_x))) << endl;
}