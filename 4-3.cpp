#include <iostream>
using namespace std;

/* 用贪心算法求解 0-1 背包问题 */


// https://www.jianshu.com/p/4b97a7e1c250

class Goods {
public:
    int weight;
    int value;
    int status;
    Goods();
    Goods(int weight, int value, int status);
    ~Goods();
};

Goods::Goods(){
    this->weight = 0;
    this->value = 0;
    this->status = 0;
}
Goods::Goods(int weight, int value, int status) : weight(weight), value(value), status(status) {}
Goods::~Goods() {}

// @param goods 物品的集合
// @param n     物品数量
// @param total 背包的空闲重量

// 策略
int strategy(Goods goods[], int n, int total)
{
    int index = -1;
    float wvRate = (float)goods[0].value / (float)goods[0].weight;
    for (int i = 1; i < n; i++)
    {
        Goods currentGood = goods[i];
        if (currentGood.status == 0 &&
            currentGood.weight <= total &&
            ((float)currentGood.value / (float)currentGood.weight) >= wvRate)
        {
            index = i;
            wvRate = (float)goods[index].value / (float)goods[index].weight;
        }
    }

    return index;
}


Goods* greed(Goods goods[], int n, int total) {
    Goods *result = new Goods[10];
    Goods *pResult = result;
    
    while (true)
    {
        int s = strategy(goods, n, total);
        if (s == -1) {
            break;
        }

        total -= goods[s].weight;
        goods[s].status = 1;
        *pResult = goods[s];
        pResult++;

    }

    return result;
}

int main()
{
    Goods g1(10, 4, 0);
    Goods g2(10, 60, 0);
    Goods g3(20, 100, 0);    
    Goods g4(30, 120, 0);

    Goods goods[] = {g1, g2, g3, g4};
    int total = 50;

    Goods *result = greed(goods, 4, total);
    int vSum = 0;

    for (Goods *pResult = result; pResult->status==1; pResult++){
        cout << "Goods: 物品 (w:" << pResult->weight << ", v:" << pResult->value << ") 已被装入！" << endl;
        vSum += pResult->value;
    }
    cout << "Value: 最大价值为: " << vSum << endl;

    return 0;
}