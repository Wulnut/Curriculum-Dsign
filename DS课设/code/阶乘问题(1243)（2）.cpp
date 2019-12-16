#include <iostream>
using namespace std;
int main()
{
    unsigned m,n,a,r[]={6,2,4,8};
    while(cin>>n){
    	 m=n;
     
    for(a=0;m;m/=5)
        a+=(m%5==2)+(m%5==4)*2+m/5;
    cout<<((n>1)?r[a%4]:1)<<endl;
	}
	return 0;
}//这个题目还是个有名的数学题
//关键是阶乘的尾数是一个周而复始有规律的序列，阶乘末尾问题。
