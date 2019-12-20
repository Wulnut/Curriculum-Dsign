#include<iostream>
using namespace std;
int main(){
    int n =0;
    cin >> n;
    int a[n];
    for( int i=0; i < n; ++i){
        cin >> a[i];
    }

    int temp = 0;
    int sum = 0;


    for(int i = 0; i < n-1; ++i){
        for(int j = n - 2; j >= i; --j){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                sum ++;
            }
        }
    }
    
    

    cout << sum;



    return 0;
}
