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
	cost[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		int min=INT_MAX;
		for(int j=i+1;j<=n;j++)
		{
			if(c[i][j]!=0&&c[i][j]+cost[j]<min)
			{
				min=c[i][j]+cost[j];
				d[i]=j;
			}
		}
		cost[i]=min;
	}
	cout<<"1 to "<<n<<"="<<cost[1]<<endl;
	p[1]=1;
	p[stage]=n;
	for(int i=2;i<stage;i++)
	p[i]=d[p[i-1]];
	cout<<"Path=";
	for(int i=1;i<=stage;i++)
	cout<<p[i]<<" ";
}
