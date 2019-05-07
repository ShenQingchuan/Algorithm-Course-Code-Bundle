#include <iostream>

using namespace std;


void traceback(int i,int j, int **s){
    if(i==j){
        return;
    }
    traceback(i,s[i][j], s);
    traceback(s[i][j]+1,j, s);
    cout<<"数乘: A"<<i<<","<<s[i][j]<<" and A"<<s[i][j]+1<<","<<j<<endl;
}

void matrixChain(int *p, int n, int **m, int **s){
    for (int i = 1; i <= n; i++){
        m[i][i] = 0;                // 对角线设置为 0
    }
    for (int r=2; r <= n; r++){      // r 为段长
        for (int i=1; i <= n-r+1; i++){
            
            int j = i+r-1;          // j 为此段的起点
            
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;

            for (int k=i+1; k<j; k++){
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
                
            }
        }
    }
}


int main(){
    int n;
    cout << "请输入连乘的矩阵个数：";
    cin >> n;

    int *p = new int[n+1];
    int **m = new int*[n];
    int **s = new int*[n];
    for (int i=0; i<=n; i++){
        m[i]=new int[n];
		s[i]=new int[n];
    }


    cout << "请按 p 数组要求，依次输入矩阵的行/列数：" << endl;
    for(int i=0; i<n; i++){
        cin>>p[i];
    }

    matrixChain(p, n, m, s);
    traceback(1, n, s);

    cout << "最小数乘次数是：" << m[1][n-1] << endl;

    return 0;
}