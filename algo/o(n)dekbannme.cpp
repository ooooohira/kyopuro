
int rec(a, k) {
    // 終端条件
    if (a.size() <= 100) {
         sort(a.begin(), a.end());
         return a[k];
    }
  
    // a の要素を 5 個ずつ切り出して、各グループのメディアンを集める
    vector<int> a2;
    for (int i = 0; i < a.size(); i += 5) {
        a2.push_back(a[i:i+5] のメディアン); 
    }
  
    // a2 のメディアンを求める
    int m = rec(a2, a.size()/10);
  
    // a を 3 つのグループに分ける
    vector<int> p, q, r;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < m) p.push_back(a[i]);
        else if (a[i] == m) q.push_back(a[i]);
        else r.push_back(a[i]);
    }

    // 再帰的に解く
    int res;
    if (k <= p.size()) return rec(p, k);
    else if (k <= p.size() + q.size()) return m;
    else return rec(r, k - p.size() - q.size());
}