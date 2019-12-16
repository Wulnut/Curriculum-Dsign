#include<iostream>
using namespace std;
long long a[1000005];

int slo(int n){
        long long sum = 0;
        sum = n*n*5;
        return sum;
}

int main(){
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int sum = 0;
       sum = slo(a[i]*10);
       cout<<sum<<endl;     
    }
    return 0;
}//???