//注意！！！！！！！！！！！！！！！！！！
compositionの順番に気をつけろ！！！！、
f⚪︎gの順だよ








区間加算・区間最大値取得
using S = long long;
using F = long long;

const S INF = 8e18;
//1, 伝搬
//2, 追加
//3, 再計算
//どれも追加で辿るところしか1,3は行われないので、明らかに計算量はo(logN)
//要求、(xy)^a=x^ay^a,  x^(ab)=(x^a)^bが成立すればOK

S op(S a, S b){ return std::max(a, b); }//乗る値の演算
S e(){ return -INF; }//乗る値の単位元
S mapping(F f, S x){ return f+x; }//写像適用
F composition(F f, F g){ return f+g; }//合成写像、gが先で次にfが作用する場合ね
F id(){ return 0; }//恒等写像

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}


区間加算・区間最大値取得
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

区間加算・区間和取得
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}


区間変更・区間最小値取得
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

区間変更・区間最大値取得
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}

区間変更・区間和取得
struct S{
    long long value;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){
    int N;
    std::vector<S> v(N, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
}