#include<iostream>
#include<cstdio>
#include<cmath>
#include <fstream>
using namespace std;
/* 计算Number的Times次方*/
int Power(int Number, int Times)
{
         int result = 1;
                    while(Times--)
                            result *= Number;
         return result;
}
/* 统计1-Number之间的数字中以Digit为尾数的个数*/
int GetLastDigitTimes(unsigned Number, int Digit)
{
                    if(Number % 10 >= Digit)
                            return Number / 10 + 1;
         return Number / 10;
}

/*计算对Number!做因子分解后Factor因子的个数并返回*/
int GetFactorNumber(unsigned Number, unsigned Factor)
{
         int result = 0;
                    if(Factor < 2 || Number < 1)
                            return -1;
         while(Number >= Factor)
                            result += Number /= Factor;
         return result;
}
/* 计算Number!的最右非零位并输出方法2 */
int GetLastDigitB(unsigned Number)
{
         int result = 1;/*这是连乘法的基础值，也是最后要返回的结果*/
         int i;/*循环变量*/
         int tmp;/*循环中用到的临时值*/
         int Count = 0;/*记录找到的因子2的个数，直到和因子5的个数相等*/
int TotalFactors = GetFactorNumber(Number, 5);/*因子5的总数*/
         int T2, T3, T4, T7, T8, T9;/*指示以2,3,4,7,8,9为尾数的个数*/
                    /*下面依旧是排除因子2的过程*/
         for(i = Number; i >= 1; i--)
         {
                            tmp = i;
                 while(tmp % 2 == 0 && Count < TotalFactors)
                            {
                                    tmp /= 2;
                                    Count++;
                            }
                 while(tmp % 5 == 0)
                                    tmp /= 5;
                            tmp %= 10;
                            result *= tmp;
                            result %= 10;
                            if(Count == TotalFactors && i % 5 == 1)
                         break;
         }
                    i--;

                    /*因子2排除完毕，开始使用新方法统计各尾数出现次数并对自身的周期取模*/
                    T2 = GetLastDigitTimes(i, 2) % 4;
                    T3 = GetLastDigitTimes(i, 3) % 4;
                    T4 = GetLastDigitTimes(i, 4) % 2;
                    T7 = GetLastDigitTimes(i, 7) % 4;
                    T8 = GetLastDigitTimes(i, 8) % 4;
                    T9 = GetLastDigitTimes(i, 9) % 2;

                    /*处理余下数据中的所有因子5*/
         for(; i >= 1; i -= 5)
         {
                            tmp = i;
                 while(tmp % 5 == 0)
                                    tmp /= 5;
                            tmp %= 10;
                            result *= tmp;
                            result %= 10;
          }

                    /*处理得到的不同尾数的出现次数*/
                    result *= Power(2, T2);
                    result *= Power(3, T3);
                    result *= Power(4, T4);
                    result %= 10;
                    result *= Power(7, T7);
                    result %= 10;
                    result *= Power(8, T8);
                    result %= 10;
                    result *= Power(9, T9);
                    result %= 10;
         return result;
}
int main(){
	int a;
	int b;
	while(cin>>a){
        b = GetLastDigitB(a);
	cout<<b<<endl;
	}

	/* scanf("%d", &a);
	b = GetLastDigitB(a);
	cout<<b<<endl;*/
        //scanf("%d", &a) != EOF 使用试用于C
        //while(!(cin>>n>>m).eof()) 试用于C++

	return 0;
}
//https://www.cnblogs.com/iacocca/archive/2011/10/17/2215804.html
//想复杂了
