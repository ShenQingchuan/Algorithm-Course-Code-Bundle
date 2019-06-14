#include <iostream>

using namespace std;

int divide_maxSum(int data[], int first, int end)
{
	if (first == end)
		return data[first];
	else
	{
		int sum = 0;
		int mid = (first + end) / 2;
		int sumLeft = divide_maxSum(data, first, mid);  //情况1
		int sumRight = divide_maxSum(data, mid + 1, end);  //情况2
		//情况3：
		int s1 = 0, lefts = 0;
		for (int i = mid; i >= first; i--)
		{
			lefts += data[i];
			if (lefts > s1)
				s1 = lefts;
		}
		int s2 = 0, rights = 0;
		for (int i = mid + 1; i <= end; i++)
		{
			rights += data[i];
			if (rights > s2)
				s2 = rights;
		}
 
		sum = s1 + s2;
		if (sumLeft > sum)
			sum = sumLeft;
		if (sumRight > sum)
			sum = sumRight;
		
		return sum;  //情况1、2、3中，返回最大的那个
	}
}
 

void dpMaxSum(int n,int *a){
	int sum = 0; // 最大子段和 
	int b = 0; // 局部子段和 
	int start = 0; // 最大子段起始处 
	int end = 0; // 最大子段终止处 
	for(int i=1; i<=n; i++){ // 一直相加，直到和不为正数，当前值取代 
		if(b>0){  
			b += a[i]; 
		//	end = i;
		}
		else{
			b = a[i];
			start = i; 
		}
		
		if(b>sum){
			sum = b;
			end = i;
		}
	}
	
	cout << "\n--------\n(动态规划)最大子段和为："<<endl;
	cout << sum <<endl;
	cout << "最大子段为：" <<endl; 
	for(int i=start; i<=end; i++){
		cout << a[i] << " ";
	}
	cout << endl;
} 

int main(int argc, char *argv[])
{
	int data[20] = {0, 11, -4, 13, -5, -2};  //第0个位置不用
	cout << "(分治法)最大子段和：" <<  divide_maxSum(data, 1, 6);
    dpMaxSum(6, data);
	return 0;
}