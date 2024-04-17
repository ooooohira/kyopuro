#include <stdio.h>
#include<iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> re;
void fuck(vector<int> p,int ka,int kai){
	
	int x=0;
	x=p.back();
	p.pop_back();
	if(x==2){
		return;
	}
	if(x==1){
	int y=(2^(kai))+ka;
	re.push_back(y);
    fuck(p, ka, kai+1);
	fuck(p, y, kai+1);
	}
} 
 
int main()
{
int N;
cin>>N;
vector<int> h;

h.push_back(2);

int i=0;
while(N==0){
i=N%2;
N=N/2;
h.push_back(i);
}
re.push_back(0);
fuck(h, 0, 0);

sort(re.begin(), re.end());

for (size_t i = 0; i < re.size(); ++i) {
        cout << re.at(i) << endl;
}

return 0;
}