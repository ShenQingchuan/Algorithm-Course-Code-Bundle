#include <iostream>
#include <cstring>
using namespace std;

void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


//在list数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等
bool IsSwap(char *pStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pStr[i] == pStr[nEnd])
            return false;
    return true;
}


// k表示当前选取到第几个数，m表示数组中共有多少数。(k，m对应的是数组中的下标)
void AllRange(char *pStr, int k, int m)
{
    if (k == m)
    {
        cout << pStr << endl;
    }
    else
    {
        for (int i = k; i <= m; i++) // 第i个数分别与它后面的数字交换就能得到新的排列
        {
            if (IsSwap(pStr, k, i))
            {
                Swap(pStr + k, pStr + i);
                AllRange(pStr, k + 1, m);
                Swap(pStr + k, pStr + i);
            }
        }
    }
}


void Permutation(char *pStr)
{
    if (pStr == NULL)
        return;

    AllRange(pStr, 0, (int)strlen(pStr) - 1);
}


int main(int argc, const char * argv[]) {

    char str[] = "212"; // 如果初始时，给出的是字符串形式。
    Permutation(str);    
    return 0;
}

