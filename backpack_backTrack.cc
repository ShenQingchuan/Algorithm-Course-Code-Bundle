#include <iostream>

using namespace std;


int n,c,bestp;//物品的个数，背包的容量，最大价值
//物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况
int p[100],w[100],x[100],bestx[100];

void BackTrack(int i, int cp, int cw) {
    if(i>n) {
        if(cp > bestp) {
            bestp = cp;
            for(i=0; i<n; i++) {
                bestx[i] = x[i];
            }
        }
    } //回溯结束 
    else {
        for(int j=0; j<=1; j++) {
            x[i] = j;
            if(cw+x[i]*w[i]<=c) { //判断待装入的物品的容量和已装入物品的容量和背包容量的关系
                cw += w[i]*x[i];
                cp += p[i]*x[i];
                BackTrack(i+1, cp, cw);
                cw -= w[i]*x[i];
                cp -= p[i]*x[i];
            }
        }
    }
}

int main() {
    int i;
    bestp = 0;
    cout << "请输入背包最大容量： ";
    cin >> c;
    cout << "请输入物品个数： ";
    cin >> n;
    cout << "请依次输入物品的重量、价格: "<<endl;
    for(i=0; i<n; i++){
        cout<<"物品"<<i+1<<": ";
        cin >> w[i] >> p[i];
    }

    BackTrack(0,0,0);
    cout<<"最大价值为："<<bestp<<endl;
    cout<<"装入结果为："<<endl;
    for(i=0; i<n; i++){
        cout << bestx[i] << " ";
    }
    cout << endl;

    return 0;
}