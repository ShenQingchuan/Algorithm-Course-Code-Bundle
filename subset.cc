#include <stdio.h>
int flag,sum=0;
int *s, *x, n,c;
 
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
					printf("%3d",s[i]);
			printf("\n");
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
	scanf("%d%d",&n,&c);
	s = new int[n];
	x = new int[n];
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
		x[i]=0;
	}
	backtrack(0);
	if(flag)
		printf("找到了解...");
	else 
		printf("没有找到解...");
	return 0;
}