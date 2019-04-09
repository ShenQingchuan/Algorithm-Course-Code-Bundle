/* 	2-2.cpp 
*/

#include <iostream>

using namespace std;

template<class Type>
void Swap(Type &a, Type &b){
	Type temp = a; a = b; b = temp;
}

template<class Type>
bool IsSwap(Type list[], int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (list[i] == list[nEnd]) //����������������Ȼ����ظ���ֵʱ���Ͳ����н���
            return false;
    return true;
}


template<class Type>
void Perm(Type list[], int k, int m){  	// ����list[k:m]��ȫ���� 
	if(k==m){  // ��ʣ��һ��Ԫ�� 
		for(int i=0; i<=m; i++){
			cout << list[i];
		}
		cout<<endl;
	}
	else{	   // ���ж��Ԫ�صȴ�����, ��ݹ��������  
		for(int i=k; i<=m; i++){
			Swap(list[k], list[i]);
			Perm(list, k+1, m);
			Swap(list[k], list[i]);
		}
	}
}

template<class Type>
void Perm_removeSame(Type list[], int k, int m){  	
	/* ���´������ͬ�� */
	if(k==m){
		for(int i=0; i<=m; i++){
			cout << list[i];
		}
		cout<<endl;
	}
	else{	   
		for(int i=k; i<=m; i++){
			/* ���ڴ�ֻ��û���ص����ַ��Ž��� */
			if(IsSwap(list, k, i)){
				Swap(list[k], list[i]);
				Perm_removeSame(list, k+1, m);
				Swap(list[k], list[i]);
			}
		}
	}
}


int main(){
	int n = 0;
	cout << "Please input how many numbers do you wanna perm: " ;
	cin >> n;
	
	int *arr1 = new int[n];
	int *arr2 = new int[n];
	cout << "\n Please input the element one by one: \n";
	int tmp = 0;
	for(int i=0; i<n; i++){
		cin >> tmp;
		arr1[i] = tmp;
		arr2[i] = tmp;
	}
	
	cout<< "Perm without removing same: \n";
	Perm(arr1, 0, n-1);
	
	cout<<"------------------------------"<<endl;
	cout<< "Perm with removing same:\n";
	Perm_removeSame(arr2, 0, n-1);
	
	return 0;
}
