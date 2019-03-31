#include<cstdio>
using namespace std;
int n,oil=0;         //oil为当前油箱油量，n为油站数 
float d1,c,d2,p,opri=0;
void price(float,int);
struct ol{
	float p;       //该站的油价 
	float d;      //油站到离出发点的距离 
}oils[7];
void price(float ste,int N)          //ste为当前位置到起点的距离,N为当前油站 
{
	if(ste<d1)
	{
		int mino=N;
		float minP=oils[N].p;
		for(int i=N;i<=n;++i)
		if(minP>oils[i].p)
		{
			minP=oils[i].p;
			mino=i;
		}
		if(N==mino&&c*d2>=d1-ste)
		{
			opri+=(d1-ste)/d2*oils[N].p;
			ste=d1;
		}
		else
		{
			F:
			if(c*d2<oils[mino].d-ste)
			{
				opri+=oils[N].p*(c-oil);
				int mio=N;
				float miP=oils[N].p;
				for(int i=N;oils[i].d<=(c*d2+ste);++i)
				if(miP>oils[i].p)
				{
					miP=oils[i].p;
					mio=i;
				};
				oil-=(oils[mio].d-ste)/d2;
				ste=oils[mio].d;
				N=mio;
				if(c*d2<oils[mino].d-ste)
					goto F;
			}
			else
			{
				if(((oils[mino].d-ste)/d2-oil)>=0)
				opri+=oils[N].p*((oils[mino].d-ste)/d2-oil);
				oil-=(oils[mino].d-ste)/d2;
				N=mino;
				ste=oils[mino].d;
			/*	opri+=minP*(c-oil);
				oil=c;*/
				price(ste,N);
			};
		}
	}	
}
int main()
{
	scanf("%f%f%f%f%d",&d1,&c,&d2,&p,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%f",&oils[i].d);
		scanf("%f",&oils[i].p);
	};
	oils[0].p=p;
	oils[0].d=0;
		for(int i=1;i<=n;i++)
    {
        if(oils[i].d-oils[i-1].d>c*d2){printf("No Solution");return 0;}
    }
	price(0,0);
	printf("%.2lf",opri);
}
