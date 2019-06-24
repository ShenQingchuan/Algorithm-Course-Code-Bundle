#include <iostream>
#include <string.h>

using namespace std;

/* 最长公共子序列。
题目：如果字符串一的所有字符按其在字符串中的顺序出现在另外一个字符串二中，
则字符串一称之为字符串二的子串。

注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。
请编写一个函数，输入两个字符串，求它们的最长公共子串，并打印出最长公共子串。
例如：输入两个字符串BDCABA和ABCBDAB，字符串BCBA和BDAB都是是它们的最长公共子序列，则输出它们的长度4，并打印任意一个子序列。
*/

#define MAXLEN 50

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 1; j <= n; j++)
        c[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1; // 如果使用'↖'、'↑'、'←'字符，会有警告，也能正确执行。
            }                // 我这里采用1,3,2三个整形作为标记
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 3;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        PrintLCS(b, x, i - 1, j - 1);
        cout << x[i - 1] << " " ;
    }
    else if (b[i][j] == 3)
        PrintLCS(b, x, i - 1, j);
    else
        PrintLCS(b, x, i, j - 1);
}

int main(){
    cout << "请输入一个不超过50个字符的序列：";
    char x[MAXLEN];
    cin >> x;

    cout << "请再输入一个不超过50个字符的序列：";
    char y[MAXLEN];
    cin >> y;  

    int b[MAXLEN][MAXLEN]; //传递二维数组必须知道列数，所以使用MAXLEN这个确定的数
    int c[MAXLEN][MAXLEN];

    int m, n;

    m = strlen(x);
    n = strlen(y);

    LCSLength(x, y, m, n, c, b);
    PrintLCS(b, x, m, n);
    // 末尾输出换行符
    cout << endl;

    return 0;
}
