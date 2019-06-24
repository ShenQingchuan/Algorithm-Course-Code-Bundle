#include <iostream>
#include <cstring>
using namespace std;


class Traveling{
private:
	friend int TSP(int**,int*,int,int); 
	void backTrack(int i);
	int city;
	int* x;//当前旅行策略
	int* bestx;//最优旅行策略
	int** a; 
	int current_cost;//当前代价
	int bestc;//存放最小代价值
	int NoEdge;//不连通的标志，这里设为-1
};

void Traveling::backTrack(int i)
{
	if(i==city){ 
		if(a[x[city-1]][x[city]]!=NoEdge &&
			a[x[city]][1]!=NoEdge &&
			(current_cost+a[x[city-1]][x[city]]+a[x[city]][1]<bestc || bestc==NoEdge))
		{
			bestc=current_cost+a[x[city-1]][x[city]]+a[x[city]][1];
			for(int j=1;j<=city;j++)
				bestx[j]=x[j];
		}	
	}else{
		for(int j=1;j<=city;j++)
			if(a[x[i-1]][x[j]]!=NoEdge &&
				(current_cost+a[x[i-1]][x[i]]<bestc || bestc==NoEdge))
			{
				swap(x[i],x[j]);
				current_cost+=a[x[i-1]][x[i]];
				backTrack(i+1);
				current_cost-=a[x[i-1]][x[i]];
				swap(x[i],x[j]);
			}
	}
}




int TSP(int** a,int* bestPath,int city,int NoEdge)
{
	Traveling Y;
	Y.x=new int[city+1];
	for(int i=1;i<=city;i++)
		Y.x[i]=i;
	Y.a=a;
	Y.city=city;
	Y.bestc=NoEdge; 
	Y.bestx=bestPath;
	Y.current_cost=0;
	Y.NoEdge=NoEdge;
	Y.backTrack(2); 
	delete[] Y.x;

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<"  "<<a[i][j];
		}
		cout<<endl;
	}
	cout<<"The path: ";
	for(int i=1;i<=city;i++)
	{
		cout<<" "<<Y.bestx[i];
	}
	cout<<endl;
	return Y.bestc;
}

int main()
{
	int **map;
	int * bestpath;

	map = new int*[5];
	for(int i=0;i<5;i++)
	{
		map[i] = new int[5];
	}
	int a[5][5]=
	    {0,1,2,3,4,
		1,-1,30,6,4,
		2,30,-1,5,10,
		3,6,5,-1,20,
		4,4,10,20,-1};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			map[i][j] = a[i][j];
		}
	}
	bestpath = new int[5];
	memset(bestpath,0,sizeof(bestpath));
	cout<<"The min cost: "<<TSP(map,bestpath,4,-1)<<endl;

    return 0;
}