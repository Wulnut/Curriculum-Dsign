#include<iostream>
#include<algorithm>

using namespace std;

#define N 10005

typedef struct {
    int x;//x代表龙的攻击力
    int y;//y代表这条龙的奖励攻击力。

}Arry;
int a[100005];
Arry arr[N];

void quick_sort(int l,int r){
	int i=l;
	int j=r;
	int x=a[(i+j)/2];
	while(i<j){
		while(a[j]<x){
			j--;
		}
		while(a[i]>x){
			i++;
		}
	}
	if(i<=j){
		swap(a[i],a[j]);
		i++;
		j--;
	}
	if(l<j){
		quick_sort(l,j);
	}
	
	if(r<i){
		quick_sort(r,i);
	}

}

int fuc(int a, int n){
    for(int i=0; i<n; ++i){
        if(a > arr[i].x){
            a += arr[i].y;
        }
        if(a > arr[n-1].x){
            return 1;
        }
    }
    return 0;
}

int main(){
    int b;
    int a;//代表攻击力
    int n;//代表饿龙数量
    cin>>a>>n;
    for(int i = 0; i < n; ++i){
        cin>>arr[i].x>>arr[i].y;
    }
    quick_sort(arr[1].x, arr[n-1].x);
    if(fuc(a,n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}