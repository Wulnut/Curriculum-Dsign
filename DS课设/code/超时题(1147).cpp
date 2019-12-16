#include<iostream>
using namespace std;
int main(){
    int n, i;
    int count1 = 0, key, count2 = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &key);
        if(key == 1){
            count1++;
        }
        else{
            count2++;
        }
    }
    cout<<abs(count1-count2);
    return 0;
}