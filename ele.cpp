#include<stdio.h> 
#include<math.h> 
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[6],b[6],t[6];
int MIN=100000000;
int g[11],tt[6],p[6];
void fuck( int g[],int tot[],int time,int floor,int flag)
{
	int i, k=0;
	bool f=true;
	for( i=1;i<=10;i++)
		if	( g[i]==1 )
			{
				f=false;
				break;
			}
	if	(f)
		{
			int sum=tot[1]+tot[2]+tot[3]+tot[4]+tot[5]-t[1]-t[2]-t[3]-t[4]-t[5];
			if	( sum<MIN )
				{
					tt[1]=tot[1];tt[2]=tot[2];tt[3]=tot[3];tt[4]=tot[4];tt[5]=tot[5];
					MIN=sum;	
				}
		}					
	for( i=1;i<=10;i++ )
		if	( g[i]==1 )
			{
				if	( i<6 )
					{
						g[i]=0;
						g[i+5]=1;
						if	( floor==b[i] )
							k=flag;
						else
							k=abs( b[i]-floor )+1;	

							fuck(g,tot,max(time+k,t[i]),b[i],0);

						g[i]=1;
						g[i+5]=0;	
					}
				else
					{
						g[i]=0;
						if	( floor==a[i-5] )
							k=0;//防止有人在原楼层上在原楼层下计算两次时间 
						else
							k=abs( a[i-5]-floor )+1;					
						tot[i-5]=time+k-1;
						fuck( g,tot,time+k,a[i-5],0);
						g[i]=1;
					}
			}
}//很关键
int main()  
{
	int i,j,k;
	int time;
	for( i=1;i<=5;i++ )
		scanf("%d%d%d",&t[i],&b[i],&a[i]);
	for( i=1;i<=10;i++)
		if	( i<6 )
			{
				g[i]=1;
				tt[i]=0;
				p[i]=0;
				if	( a[i]==0 )
					a[i]=10;
				if	( b[i]==0 )
					b[i]=10;
			}
		else
			g[i]=0;
	fuck(g,p,0,1,1);
	for(int i=1;i<=5;i++)
		printf("%d时，stop%d\n",tt[i],a[i]); 
	printf("%d",MIN); 
	return 0;
}

