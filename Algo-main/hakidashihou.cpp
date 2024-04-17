#include <iostream>//計算量は行数を R、列数を C とすると O(R(C)^^2) となります。
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl


using D = double;
const D EPS = 1e-10;

// matrix
template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n, int m, T x = 0) : val(n, vector<T>(m, x)) {}
    void init(int n, int m, T x = 0) {val.assign(n, vector<T>(m, x));}
    size_t size() const {return val.size();}
    inline vector<T>& operator [] (int i) {return val[i];}
};

template<class T> int GaussJordan(Matrix<T> &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        // 拡大係数行列の場合は最後の列は掃き出ししない
        if (is_extended && col == n-1) break;

        // ピボットを探す
        int pivot = -1;
        T ma = EPS;
        for (int row = rank; row < m; ++row) {
            if (abs(A[row][col]) > ma) {
                ma = abs(A[row][col]);
                pivot = row;
            }
        }
        // ピボットがなかったら次の列へ
        if (pivot == -1) continue;

        // まずは行を swap
        swap(A[pivot], A[rank]);

        // ピボットの値を 1 にする
        auto fac = A[rank][col];
        for (int col2 = 0; col2 < n; ++col2) A[rank][col2] /= fac;

        // ピボットのある列の値がすべて 0 になるように掃き出す
        for (int row = 0; row < m; ++row) {
            if (row != rank && abs(A[row][col]) > EPS) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; ++col2) {
                    A[row][col2] -= A[rank][col2] * fac;
                }
            }
        }
        ++rank;
    }
    return rank;
}

template<class T> vector<T> linear_equation(Matrix<T> A, vector<T> b) {//吐き出し法で連立方程式を解く
    // extended
    int m = A.size(), n = A[0].size();
    Matrix<T> M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);
    
    // check if it has no solutionもし解なしだったら、ゴミを返す。
    vector<T> res;
    for (int row = rank; row < m; ++row) if (abs(M[row][n]) > EPS) return res;

    // answer解ある場合は自由が利く後半は0として返す。
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return res;
}