#include <iostream>

using namespace std;


int abs(int);
long nQueen(int n);
// 主函数

int main(){
    int number, result;
    cout<<"输入要放的皇后个数: ";
    cin >> number;
    result = nQueen(number);
    cout<<endl<<"解决方案的个数: " << result;
    return 0;
}

class Queen {
    friend long nQueen(int);
    private:
        bool Place(int k);
        void Backtrack(int t);
        int n, *x;  // 皇后个数 与 当前解，x[i]表示皇后放在棋盘的第 i 行的第 x[i] 列
        long sum;
};

bool Queen::Place(int k) {
    for(int j=1; j<k; j++) {
        if((abs(k-j)==abs(x[j]-x[k])) || (x[j]==x[k]))
            return false;
    }
    return true;
}

void Queen::Backtrack(int t) {
    if(t>n) {
        sum++;
        for(int row=1; row<t; row++) {
            for(int col=1; col<t; col++) {
                if(x[row]==col)
                    cout << "1" << " ";
                else
                    cout << "0" << " "; 
                // 当前 row 行的列的值等于 x[row] 的值就证明这一行的皇后放在该列，
                // 即把该位置标志设为 1 否则为 0 
            }
            cout << endl;
        }
        cout << endl;
    } else {
        for(int i=1; i<=n; i++) {
            x[t] = i;
            if(Place(t))
                Backtrack(t+1);
        }
    }
}

long nQueen(int n) {
    Queen q;
    q.n = n;
    q.sum = 0;
    
    int *p = new int[n+1];
    for(int i=1; i<+n; i++){
        p[i] = 0;
    }

    q.x = p;
    q.Backtrack(1);
    delete[] p;
    return q.sum;
}

int abs(int a) {
    return a>=0?a:0-a;
}