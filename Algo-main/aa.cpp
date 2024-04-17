#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	// Step #1. Input
	ll R, C;
	cin >> R>>C;
    vector<vector<char>> S(R, vector<char>(C));
    vector<vector<char>> SS(R, vector<char>(C, '#'));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>S[i][j];
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(S[i][j]!='.'&&S[i][j]!='#'){
                int a=S[i][j]-'0';
                for(int p=0;p<=a;p++){
                    for(int y=0;y<=p;y++){
                        if(i+y<R&&j+p-y<C){
                            SS[i+y][j+p-y]='.';
                        }
                        if(i+y<R&&j-p+y>=0){
                            SS[i+y][j-p+y]='.';
                        }
                        if(i-y>=0&&j+p-y<C){
                            SS[i-y][j+p-y]='.';
                        }
                        if(i-y>=0&&j-p+y>=0){
                            SS[i-y][j-p+y]='.';
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(SS[i][j]=='.'){
                S[i][j]='.';
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){

            cout<<S[i][j];
        }
        if(i!=R-1)
        cout<<endl;
    }
}