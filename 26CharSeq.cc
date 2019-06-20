#include <iostream>

using namespace std;

char *a;

bool check(int i) {
    for(int j=0; j<i; j++) {
        if(a[i] == a[j]) {
            // 相同
            return false;
        }
    }
    return true;
}

void output( char *a, int n ){
    for(int i = 0; i<n; i++) {
        cout<< a[i] << " ";
    }
    cout << endl;
} 

void backTrack(int i, int n, int m) {
    if(i >= m) {
        output(a, m);
    } else {
        for(int j=0; j<n; j++){
            a[i] = 'A' + j;
            if(check(i)) {
                backTrack(i+1, n, m);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "请输入您的排列范围, 即排列字母表前多少个字母: ";
    cin >> n;
    cout << "请输入 序列的长度: ";
    cin >> m;
    a = new char[n];
    backTrack(0,n,m);

    return 0;
}