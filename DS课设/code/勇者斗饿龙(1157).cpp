#include<iostream>

using namespace std;

int main(){
    int a;//init personal attach level
    int n;//init dargons numbers
    int flag ;
    int i, j;
    cin>>a>>n;

    int D[n][2];
    for(int i = 0; i < n; ++i){
        cin>>D[i][0]>>D[i][1];
    }

        int temp = 0;
        for(int i=0;i<n-1;i++){ 
            for(j=0;j<n-1-i;j++){
                if(D[j][0]>D[j+1][0]){
             temp = D[j][0];
             D[j][0] = D[j+1][0];
             D[j+1][0] = temp;

             temp = D[j][1];
             D[j][1] = D[j+1][1];
             D[j+1][1] = temp;
		     }
            }
          }
    
    for(i = 0; i < n; ++i){
        if(a > D[i][0]){
            a += D[i][1];
        }
        else{
            cout<<"NO";
            flag = 0;
            break;
        }
        if(a > D[n-1][0]){
        	cout<<"YES";
        	flag = 1;
            break;
        }
    }


    return 0;
}//AC!!排序都不会写了！！！复习排序！！
