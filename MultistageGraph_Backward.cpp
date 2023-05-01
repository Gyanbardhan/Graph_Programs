#include<iostream>
using namespace std;
int main()
{
	int stage,n;
	cout<<"Enter stage=";
	cin>>stage;
	cout<<"Enter no. of nodes=";
	cin>>n;
	int cost[n+1],d[n+1],p[stage+1];
	cout<<"Enter graph=";
	int c[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		cin>>c[i][j];
	}
	cost[1]=0;
	for(int i=2;i<=n;i++)
	{
		int min=INT_MAX;
		for(int j=1;j<=i-1;j++)
		{
			if(c[j][i]!=0&&c[j][i]+cost[j]<min)
			{
				min=c[j][i]+cost[j];
				d[j]=i;
			}
		}
		cost[i]=min;
	}
	cout<<"1 to "<<n<<"="<<cost[n]<<endl;
	p[1]=1;
	p[stage]=n;
	for(int i=2;i<stage;i++)
	p[i]=d[p[i-1]];
	cout<<"Path=";
	for(int i=1;i<=stage;i++)
	cout<<p[i]<<" ";
}
