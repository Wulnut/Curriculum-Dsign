#include<iostream>
#include<cmath>
using namespace std;
#define N 10005

long long fuc(int a, int b){
    long long count = 0;
    for(int i = a; i <= b; i++){
        long long m = floor(sqrt(i) + 0.5); 
    if(m*m == i){
        count++;
    }
    }
    return count;
}

int main(){
    int i=0;
    long long a, b, c, d[N];
    cin>>a;
    for(i=0; i<a; i++){
        cin>>b>>c;
        d[i] = fuc(b, c);
    }
    for(i=0; i<a; i++){
        cout<<d[i]<<endl;
    }
    return 0;
}