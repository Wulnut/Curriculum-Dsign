#include<iostream>
#include<string>
using namespace std;
int main(){
    int n =0;
    int count = 0;
    cin>>n;
    string a, b, c, d;
    c = "WA";
    d = "AC";
    for(int i = 0; i < n; i++){
        cin>>b;
        if(b == d){
            count++;
        }
        if(i == n-1 && b == c){
        	count++;
		}
    }
    cout<<count;
    return 0;
}
