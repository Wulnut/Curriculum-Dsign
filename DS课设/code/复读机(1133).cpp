#include<iostream>
#include<string>
using namespace std;
int main() {
    int count = 0;
    int n=0;
    string a , b, c ;
    cin>> n;
    for (int i = 0; i < n; ++i){
        cin>>b;
        if(a == b ){
            count++;
        }
        else{
            a = b;
        }
    }
    cout<<count;
    return 0;
}
