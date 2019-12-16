#include<iostream>
using namespace std;
long long a[1000005];

int slo(int num){
        long long sum = 0;
        if(num/10 == 0){
            return num;
        }
        else{
         while( num != 0){
              sum += num % 10 ;
               num /= 10 ;
            }
            return slo(sum);
        }
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
}//AC!!
