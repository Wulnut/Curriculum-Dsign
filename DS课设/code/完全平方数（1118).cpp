/*#include<iostream>
#include<cmath>
using namespace std;
#define N 10005
long long fuc(long long a, long long b){
    int count1 = 1, count2 = 1, m = 1, n = 1;
    for(int i = 1; i <= a; i += m){
        count1 ++;
        m += 2;
    }
    for(int i = 1; i <= b; i += n){
        count2 ++;
        n += 2;
    }
    return count1 - count2;
}

int main(){
    int i = 0;
    long long a, b, c, d[N];
    cin>>a;
    for(i = 0; i < a; i++){
        cin>>b>>c;
        d[i] = fuc(b, c);
    }
    for(i = 0; i < a; i++){
        cout<<d[i]<<endl;
    }
    return 0;
}*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int a,b,t;
	double c,d;
    int m;
    scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
        scanf("%d%d", &a, &b);
	    c=sqrt(a);
	    a=(int)c;//强制转换，方便得到大小关系 
	    d=sqrt(b);
	    b=(int)d;
	    if(c==d&&(c-a==0))
	      t=1;
	    else
	    {
	    	t=b-a;
	    	if(c-a==0)//判断a是否是完全平方数 
	    	  t=t+1;
	    }
	    printf("%d\n",t);
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int a,b,t;
	double c,d;
	while(scanf("%d%d",&a,&b)!=EOF)//数据由至多100组测试用例组成，请你处理至文件末尾。此为处理方式
	{
	    c=sqrt(a);
	    a=(int)c;//强制转换，方便得到大小关系 
	    d=sqrt(b);
	    b=(int)d;
	    if(c==d&&(c-a==0))
	      t=1;
	    else
	    {
	    	t=b-a;
	    	if(c-a==0)//判断a是否是完全平方数 
	    	  t=t+1;
	    }
	    printf("%d\n",t);
	}
	return 0;
}

*/