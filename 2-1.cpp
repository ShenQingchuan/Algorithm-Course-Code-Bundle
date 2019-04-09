/* 2-1.cpp */
#include <iostream>

using namespace std;

/* 	在正整数n的所有划分中, 将最大加数n1 不大于m的划分个数记为 q(n,m)
	可以建立q(n,m)的如下递归关系: 

	(1) q(n,1)=1, 					n>=1, 当最大加数n1不大于1时,任何正整数n只有一种划分形式，即n=1+1+...+1+1
	(2) q(n,m)=q(n,n), 				m>=n 最大加数n1实际上不能大于n, 因此q(1,m) = 1
	(3) q(n,n)=1+q(n,n-1),	 		正整数n的划分由 n1=n 的划分 和 n1<=n-1 的划分组成 
	(4) q(n,m)=q(n,m-1) + q(n-m,m), n>m>1  正整数n的最大加数n1不大于m的划分由 n1=m 的划分和 n1<=m-1 的划分组成 
	
	所以对 q(n,m) 给出如下递归算式:
	 = 1  						n=1,m=1 
	 = q(n,n)					n<m
	 = 1 + q(n,n-1)				n=m
	 = q(n,m-1) + q(n-m,m)		n>m>1
*/

int q(int n, int m){
	if((n<1) || (m<1)){
		return 0;
	}
	else if((n==1) || (m==1)){
		return 1;
	}
	else if(n<m){
		return q(n,n);
	}
	else if(n==m){
		return q(n, m-1)+1;
	}
	
	return q(n, m-1) + q(n-m, m);
}

int main(){
	int n = 0;
	cout << "Please input the number you wanna divide: ";
	cin >> n;
	
	cout << q(n,n);
	
	return 0;
}
