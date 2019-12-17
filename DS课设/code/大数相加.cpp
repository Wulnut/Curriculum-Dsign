#include <iostream>
#include <string>
using namespace std;

// 实现大数相加  结果存放在num中 

void bigIntergerAdd(string &num, string add) {
    
    int goBit = 0; // 存放进位
    
    // 先交换下顺序  加数的位数要比较少
    if (num.length() < add.length()) {
    
        string tmp = num;
        num = add;
        add = tmp;
    } 
    
    string tmp (num.length() - add.length(), '0');
    add = tmp + add; 
    
    // 利用string的+号特性  不采用逆序相加法 
    int len1 = num.length(), len2 = add.length();
    for (int i = len1 -1 ; i>= 0; --i) {
        
        int tmp =  ((num[i] - '0') + (add[i] - '0') + goBit) ;
        
        num[i] = tmp% 10 + '0';
        
        goBit = tmp/10;
    }

    // 特殊情况处理
    if (goBit != 0) 
        num.insert(0, string(1, (char)goBit +'0')); 
} 


int main() {

    string s1;
    string result;
    int i =0;
    int n=0;
    cin>>n;
    for(int a =0; a < n; a++) {
        cin>> s1>>result;
        if (s1 == "0") {
            
            cout<< result<< endl;
            break;
        } 
        
        /*if (i ==0) {
            
            i=1;
            result = s1;
        } else*/ 
        bigIntergerAdd(result, s1);//非eof结束
        cout<<result<<endl;
    } 

    /*while (cin>> s1) {
    
        if (s1 == "0") {
            
            cout<< result<< endl;
            break;
        } 
        
        if (i ==0) {
            
            i=1;
            result = s1;
        } else 
            bigIntergerAdd(result, s1);
        
        count<< result<< endl;
    } */
    //eof结束
    
    return 0;
}//AC!!