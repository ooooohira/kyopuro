#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力受け取り
    int N;
    cin >> N;
    vector<int> a(N);
    //for (int i = 0; i < N; ++i) cin >> a[i];
    
    // bit は 2^N 通りの部分集合全体を動く
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        for (int i = 0; i < N; ++i) {
            if(bit & (1<<i)){//ちなみに1<<0は0000000001だよ
                //ここに処理書いてね
            }
        }
    }
}

// #include <iostream>正しい()サイズN全て辞書順だお
// #include <vector>
// using namespace std;

// int main() {
//     // 入力受け取り
//     int N;
//     cin >> N;
//     // bit は 2^N 通りの部分集合全体を動く
//     for (int bit = 0; bit < (1 << N); ++bit)
//     {   char ka[N];
//         for (int i = N-1; i>-1; --i) {
//             int in=N-1-i;

//             if (bit & (1 << in)) {
//                 ka[i]=')';       
//             }
//             else ka[i]='(';
//         }
//             int f=0;
//             for(int k=0;k<N;k++){
//                 if(ka[k]=='(')f++;
//                 else f--;
//                 if(f<0)break;
//             }
//             if(f==0){for(int o=0;o<N;o++){cout<<ka[o];}cout<<endl;}
//     }
// }
