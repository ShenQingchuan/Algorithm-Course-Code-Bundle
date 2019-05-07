#include <iostream>

using namespace std;

/*
问题的提出：给定有n个整数(可能为负整数)组成的序列a1,a2,...,an,
求该序列连续的子段和的最大值。如果该序列的所有元素都是负整数时定义其最大子段和为0。
例如，当(a1,a2,a3,a4,a5)=(-5,11,-4,13,-4-2)时，最大子段和为11+(-4)+13=20。
*/

// 1. 解法1：分治策略
//left是做端点下标，right是右端点下标
int maxSubSum(int a[],int left,int right){
	int sum=0;
	if(left==right)//这是递归调用必须要有的终值情况。
		sum=(a[left]>0?a[left]:0);
	else{
		int center=(left+right)/2;
		int leftSum=maxSubSum(a,left,center);//求出左序列最大子段和
		int rightSum=maxSubSum(a,center+1,right);//求出右序列最大子段和
    //----------------------
    //求跨前后两段的情况，从中间分别向两端扩展。
		//从中间向左扩展。这里注意，中间往左的第一个必然包含在内。
		int ls=0;int lefts=0;
		for(int i=center;i>=left;i--){
			lefts+=a[i];
			if(lefts>ls)
				ls=lefts;
		}
		//从中间向右扩展。中间往右的第一个必然包含在内
		int rs=0;int rights=0;
		for(int i=++center;i<=right;i++){
			rights+=a[i];
			if(rights>rs)
				rs=rights;
		}
		sum=ls+rs;//sum保存跨前后两段情况的最大子段和
    //求跨前后两段的情况完成
    //----------------------
		if(sum<leftSum)
			sum=leftSum;//记住，leftSum表示前段序列的最大子段和
		if(sum<rightSum)
			sum=rightSum;//rightSum表示后段序列的最大字段和
	}
	return sum;
}


// 解法2：动态规划:
int MaxSum_DP(int a[],int n){
    int sum=0,prev=0;
    for (int i=1; i<=n; i++){
        
        // 只要前头的还是正数，就给他加进来, 如果前头的都是负数了，那就扔了不要了，只从当前这个再开始算
        if(prev > 0)  prev + a[i];
        else        prev = a[i];
        
        // 再和 已知的 sum 比一比谁大，大的留下
        if(prev>sum) sum = prev;
    }
    return sum;
}


int main(){
    int a[] = {-2, 11, -4, 13, -5, -2, -7, -8, -9};
    cout << "分治策略：sum = " << maxSubSum(a, 0, 8) << endl;
    cout << "动态规划：sum = " << MaxSum_DP(a, 8) << endl;

    return 0;
}