#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;//apple number
    cin >> n;
    long long ai[n];//apple KG
    long long m;
    bool flag = true;
    for(int i = 0; i < n; ++i){
        cin >> ai[i];
    }

    cin >> m;
    sort(ai, ai + n);

    for(int i = n - 1; i < n; i++){
        m = m - ai[i];
        count++;
    }

    return 0;
}