#include <iostream>
#include <algorithm>

using namespace std;

/* 最优装载问题。给出 n 个物体，第i个物体重量为 wi ,选择尽量多的物体，使得总重量不超过 C 。 */

// https://blog.csdn.net/q547550831/article/details/51548518
// 贪心法
void optionalLoad(int *a, int n, int C)
{
    sort(a, a + n);
    int retain = C;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= retain)
        {
            cout << a[i] << " ";
            retain -= a[i];
        }
    }
    cout << endl;
}

int main() {
    // n个物体
    int n;
    cout << "请输入物体总数(0退出)：";
    cin >> n;
    
    int C;
    cout << "请输入不超过的总重量：";
    cin >> C;

    int a[n];
    cout << "分别输入" << n << "个物体的重量： ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "最优装载为：" << endl;
    optionalLoad(a, n, C);

    return 0;
}