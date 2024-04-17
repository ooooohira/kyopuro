int sub=sup;//supの部分集合を全列挙
do{
    //部分集合に対する処理
    sub=(sub-1)&sup;
}while(sub!=sup);


int comb=(1<<k)-1;//n個からk個取り出す組み合わせを全列挙
while(comb<1<<n){
    //組み合わせに対する処理
    int x=comb&-comb, y=comb+x;
    comb=((comb&~y)/x>>1)|y;
}