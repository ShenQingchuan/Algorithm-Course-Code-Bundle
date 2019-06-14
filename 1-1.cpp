#include <iostream>
using namespace std;

long long sumNotZero(int n, int k){
    long long cnt = 0;
    long long factor = 1;
    long long low = 0;
    long long cur = 0; // the center of the sepration.
    long long high = 0;
    while (n / factor)
    {
        low = n - (n / factor) * factor;
        cur = (n / factor) % 10;
        high = n / (factor * 10);
        if (cur < k)
            cnt += high * factor;
        else if ( cur == k )
            cnt += high * factor + low + 1;
        else
            cnt += (high + 1) * factor;
        factor *= 10;
    }
    return cnt;
}

long long sumZero( int n ){
    long long cnt = 0;
    long long factor = 1;
    long long low = 0;
    long long cur = 0;
    long long high = 0;
    while(n / factor){
        low = n - (n / factor) * factor;
        cur = ( n / factor ) % 10;
        high = n / (factor * 10);
        if (!high) {
        factor *= 10;
        continue;
        }
        if (cur == 0)
            cnt += (high -1)* factor + low + 1;
        else
            cnt += high * factor;
        factor *= 10;
    }
    return cnt;
}

int main(){
    // 创建一个结果数组，0~9的单元分别记录 对应的各个数字出现的次数：
    int count[10] = {0};
    
    // 读入页数
    int pagenum;
    cin >> pagenum;
    
    // 单独计算并记录 0 出现的次数：
    count[0] = sumZero(pagenum);
    
    // 1~9，计算并记录其出现的次数：
    for(size_t i = 1; i <= 9; i++)
        count[i] = sumNotZero(pagenum, i);
    
    // 打印 0~9 各个数字出现的次数：
    for(size_t i = 0; i < 10; i++)
        cout << count[i] << endl;
    
    return 0;
}