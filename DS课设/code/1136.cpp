#include <iostream>
using namespace std;
/*int f(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;
	return f(n - 1) + f(n - 2);
}*/


long long  fibo(int n)
{
    long long nFirst = 0;
    long long nSecond = 1;
    long long  nThird = 0;
    for(int i = 2 ; i <= n; i++){
        nThird = nFirst + nSecond;
        nFirst = nSecond;
        nSecond = nThird;
    }
    return nThird;
}

long long f(int n){
    long long count = 1;
    if(n == 1){
        return 1;
    }
    for (int i = 1; i < n; i++)
    {
        count += fibo(i);
    }
    return count+1;
}

int main()
{    
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}