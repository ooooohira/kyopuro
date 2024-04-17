#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> A, L;

int lis() {
  L[0] = A[0];
  int length = 1;
  for (int i = 1; i < n; i++) {
    if (L[length - 1] < A[i]) {
      L[length] = A[i];
      length++;
    } else {
      auto iter = lower_bound(L.begin(), L.begin() + length, A[i]);
      L[iter - L.begin()] = A[i];
    }
  }
  return length;
}

int main() {
  cin >> n;
  A.resize(n);
  L.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cout << lis() << "\n";
  return 0;
}