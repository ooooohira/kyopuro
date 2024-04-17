string S;//o(|S|)で計算可能(i+jの値がmax2＊|S|回であることからo(|S|))
cin >> S;
vector<int> Z(S.size());
Z[0] = S.size();
int i = 1, j = 0;
while(i < S.size()){
    while(i + j < S.size() && S[j] == S[i + j]) j++;
    Z[i] = j;

    if(j == 0){
        i++;
        continue;
    }
    int k = 1;
    while(k < j && k + Z[k] < j){
        Z[i + k] = Z[k];
        k++;
    }
    i += k;
    j -= k;
}
//rep(i, S.size()) cout << Z[i] << " ";
//cout << endl;