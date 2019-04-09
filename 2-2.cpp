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
        if (list[i] == list[nEnd]) //当除自身与自身相等还有重复的值时，就不进行交换
            return false;
    return true;
}


template<class Type>
void Perm(Type list[], int k, int m){  	// 产生list[k:m]的全排列 
	if(k==m){  // 仅剩下一个元素 
		for(int i=0; i<=m; i++){
			cout << list[i];
		}
		cout<<endl;
	}
	else{	   // 还有多个元素等待排列, 则递归产生排列  
		for(int i=k; i<=m; i++){
			Swap(list[k], list[i]);
			Perm(list, k+1, m);
			Swap(list[k], list[i]);
		}
	}
}

template<class Type>
void Perm_removeSame(Type list[], int k, int m){  	
	/* 大致代码基本同上 */
	if(k==m){
		for(int i=0; i<=m; i++){
			cout << list[i];
		}
		cout<<endl;
	}
	else{	   
		for(int i=k; i<=m; i++){
			/* 但在此只有没有重叠的字符才交换 */
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
