#include<iostream>
using namespace std;
int main(){
    int n, i, p = 0, j = 0, count = 0;
    long long m, all = 0;
    cin >> n;
    long long a[n+1];
    for(int i=0; i < n; ++i){
        cin >> a[i];
    }
    cin>>m;
    for(i = 0; i < n; ++i){
        all += a[i];
    }
    if(all >= m){
        while(m > 0){
            p = 1;
            for(i = 0; i < n; ++i){
                if(a[i] >= p){
                    p = a[i];
                }
                j = i;
            }
            m = m - p;
            a[j] = 0;
            count++;
        }
        cout << count;
    }
    else{
        cout << 0;
    }
    return 0;
}