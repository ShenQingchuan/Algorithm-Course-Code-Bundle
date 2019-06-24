/*
    0-1背包问题：dp思路
        有 N 件物品和一个容量为 V 的背包。
        第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使价值总和最大。

    例子：5个物品，（重量，价值）分别为：（5，12），（4，3），（7，10），（2，3），（6，6）    
*/

#include <iostream>

using namespace std;

typedef struct product {
    int value;  //价值
    int weight; //重量
} product;

const int N = 4;  //物品个数
const int W = 50; //背包的容量

//初始物品信息
product goods[] = {
    {0,0}, {4,10}, {60,10}, {100,20}, {120,30}
};

/*  load 数组的意思是： 
 */
int load[N+1][W+1];

int max_value() {

    //初始没有物品时候，背包的价值为0
    for (int w = 1; w <= W; ++w){
        load[0][w] = 0;
    }

    for (int i = 1; i <= N; ++i){ // 该过程表示 “装东西” 的过程，装的东西由 i 确定，又由于是从头到尾顺次选择，i 同时也表达了选的第几个、选了几个
        
        // 背包容量为 0 时，最大价值也就为 0
        load[i][0] = 0;
        
        for (int w = 1; w <= W; ++w){ // 该过程对 选择这个东西时背包的容量 进行遍历
            // 从 容量只剩 1 开始，到背包容量还余 W （空包，什么还没装）
            // 这么做的意义是：综合记录 背包里只有它，和可能装了其他的，已经占了一些空间时的 选择情况
            if (goods[i].weight <= w) { // 若当前物品的重量小于等于 w 则表示有容量装进来，但到底装不装，要进行选择
                
                if( (goods[i].value + load[i-1][w-goods[i].weight]) > load[i-1][w] ){
                    // 若走到这里，说明性价比很高，则选择装进来
                    load[i][w] = goods[i].value + load[i - 1][w - goods[i].weight];
                }

                else {
                    // 性价比很低，选择不装
                    load[i][w] = load[i - 1][w];
                }
            }
            
            else { // 当前物品重量大于 w，说明没容量，自然选择不装
                load[i][w] = load[i - 1][w];
            }
        }
    }

    return load[N][W];
}

int main(){
    int maxvalue = max_value();
    cout << "最大价值为: ";
    cout << maxvalue << endl;
    int remainspace = W;
    //输出所选择的物品列表：
    for (int i = N; i >= 1; i--)
    {
        if (remainspace >= goods[i].weight)
        {
            if ((load[i][remainspace] - load[i - 1][remainspace - goods[i].weight] == goods[i].value))
            {
                cout << "物品 No. " << i << " 已被装入!" << endl;
                remainspace = remainspace - goods[i].weight; //如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量 ;
            }
        }
    }

    return 0;
}