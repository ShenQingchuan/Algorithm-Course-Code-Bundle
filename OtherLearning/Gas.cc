#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/*  PAT Advanced Level 1033:
    一辆汽车加满油后可以行驶n公里，旅途中有加油站，
    设计一个有效算法，指出应在哪些加油站停靠加油，使沿途加油次数最少。 
*/

struct station {
    double distance, price;
} stations[510];

bool cmp(station a, station b) {
    return a.distance < b.distance;
}

int main() {
    double cap, aimDistance, unitRun;
    int n;
    cin >> cap >> aimDistance >> unitRun >> n;

    double FULLRUN = cap * unitRun;
    for(int i=0; i<n; ++i) {
        cin >> stations[i].price >> stations[i].distance;
    }
    // 把终点也看成是一个加油站
    stations[n].distance = aimDistance;
    stations[n].price = 0;
    
    // 经过按照离杭州距离越近越靠前的排序方式，stations[] 就成了从杭州到目的地之间的加油站序列
    sort(stations, stations+n+1, cmp);
    
    if(stations[0].distance) {
        // 如果出生点（第一个加油站）的距离不是0，则空着油箱出发的我们都没有加油的地方
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    
    /* 开始开车... */
    int now = 0;
    double money = 0, gas = 0;
    while (now < n){
        int minPriceIndex = -1; double minPrice = 100000; 
        //每次循环都选择前方加油站里最便宜的加油站
        for(int i=now+1; i<=n && stations[i].distance-stations[now].distance <= FULLRUN; ++i) {
            // within FULLRUN 在满油箱能跑到的距离里：找到了第一个油价低于当前加油站的另一个加油站；若没有就高个儿里头挑最矮
            if (stations[i].price < minPrice) {
                minPrice = stations[i].price;
                minPriceIndex = i;
                if (minPrice < stations[now].price) break; // 若比now还便宜，请参见下面的 Cheaper 标记:
            }
        }
        if (minPriceIndex == -1) break; // FULLRANK内找不到续命的加油站。退出循环
        //若能找到则开始计算费用：
        double needGas = (stations[minPriceIndex].distance - stations[now].distance) / unitRun;
        if (minPrice < stations[now].price) {
            // Cheaper: 如果下一轮最便宜的比 now 还便宜，就加油加到刚刚好能到那一站就行了，就不要在当前站费太多钱
            // 涵盖了终点的情况、终点的 price 是 0，是最低的
            if (gas < needGas) {
                money += (needGas - gas) * stations[now].price;
                gas = 0;
            } else gas -= needGas;
        }
        else {
            // 下一轮最便宜的比 now 贵，则在 now 加满油
            money += (cap - gas) * stations[now].price;
            gas = cap - needGas;
        }
        now = minPriceIndex;
    }
    if (now == n)
        printf("%.2f\n", money);
    else
        printf("The maximum travel distance = %.2f\n", stations[now].distance + FULLRUN);

     return 0;
}