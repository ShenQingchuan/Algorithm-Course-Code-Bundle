#include <iostream>
#include <cstring>
using namespace std;

void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


//��list�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������
bool IsSwap(char *pStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pStr[i] == pStr[nEnd])
            return false;
    return true;
}


// k��ʾ��ǰѡȡ���ڼ�������m��ʾ�����й��ж�������(k��m��Ӧ���������е��±�)
void AllRange(char *pStr, int k, int m)
{
    if (k == m)
    {
        cout << pStr << endl;
    }
    else
    {
        for (int i = k; i <= m; i++) // ��i�����ֱ�������������ֽ������ܵõ��µ�����
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

    char str[] = "212"; // �����ʼʱ�����������ַ�����ʽ��
    Permutation(str);    
    return 0;
}

