#include<iostream>
using namespace std;

long long  fibo(long long n)
{
    long long nFirst = 0;
    long long nSecond = 1;
    long long  nThird = 0;
    for(int i = 2 ; i <= n; i++){
        nThird = nFirst + nSecond;
        nFirst = nSecond;
        nSecond = nThird;
    }
    return nThird;
}

int main(){
    long long a;
    cin>>a;
    long long m, n;
    long long s1, s2;
    for(int i=0; i<a; ++i){
        cin>>n>>m;
        m = fibo(m);
        n = fibo(n);
        cout<<m<<endl;
        s1 = 2*m + (m - 1) - 1;
        s2 = 2*n + (n - 1) - 1;
        cout<<s1<<endl;
    }
    return 0;
}//NO AC... 注意看题