#include <iostream>
#include <algorithm>
using namespace std;
typedef struct activity
{
    int start;
    int finish;
} A;

bool cmp(A a1,A a2)
{
    return a1.finish<a2.finish;
}
int main()
{
 
    int n ;
    cin>>n;
    int s[100];//记录每个会场的结束时间
    A a[100];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i].start;
        cin>>a[i].finish;
    }
    sort(a,a+n,cmp);
    s[1] = a[0].finish;//第一个会场的结束时间就是最早结束的时间
    int j = 1;
 
    for(int i = 1;i < n;i++)
    {
        int flag = 0;//标记
        for(int q = 1;q <= j;q++)//遍历每个会场，看当前活动是否可以插入其中一个会场( 即当前活动的开始时间大于等于其中一个会场的结束时间
            if(a[i].start >= s[q])
            {
                flag = 1;
                s[q] = a[i].finish;//找到了就将这个会场的结束时间换成当前活动的结束时间（表示可以插入）
                break;
            }
        if(!flag)//找不到就在s中开辟一个会场
        {
            j++;
            s[j] = a[i].finish;
        }
 
    }
    cout<<j;
 
}