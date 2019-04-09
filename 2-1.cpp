/* 2-1.cpp */
#include <iostream>

using namespace std;

/* 	��������n�����л�����, ��������n1 ������m�Ļ��ָ�����Ϊ q(n,m)
	���Խ���q(n,m)�����µݹ��ϵ: 

	(1) q(n,1)=1, 					n>=1, ��������n1������1ʱ,�κ�������nֻ��һ�ֻ�����ʽ����n=1+1+...+1+1
	(2) q(n,m)=q(n,n), 				m>=n ������n1ʵ���ϲ��ܴ���n, ���q(1,m) = 1
	(3) q(n,n)=1+q(n,n-1),	 		������n�Ļ����� n1=n �Ļ��� �� n1<=n-1 �Ļ������ 
	(4) q(n,m)=q(n,m-1) + q(n-m,m), n>m>1  ������n��������n1������m�Ļ����� n1=m �Ļ��ֺ� n1<=m-1 �Ļ������ 
	
	���Զ� q(n,m) �������µݹ���ʽ:
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
