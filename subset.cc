#include <iostream>

using namespace std;

int flag, sum=0;
int *s, *x, n, c;
 
void backtrack(int t)
{
	int i;
	if(t==n)
	{
		if(sum==c)
		{
			flag=1;
			for(i=0;i<n;i++)
				if(x[i])
					cout << s[i] << "   ";
			cout << endl;
			return;
		}
	}
	else
	{
		sum+=s[t];
		x[t]=1;
		backtrack(t+1);
		x[t]=0;
		sum-=s[t];
		backtrack(t+1);
	}
}

int main()
{
	int i;
	cout << "请输入数字个数: "; 
	cin >> n;
	cout << "请输入和: ";
	cin >> c;
	s = new int[n];
	x = new int[n];
	for(i=0;i<n;i++){
		cin >> s[i];
		x[i]=0;
	}
	backtrack(0);
	if(flag)
		cout << "找到了解...";
	else 
		cout << "没有找到解...";
	return 0;
}