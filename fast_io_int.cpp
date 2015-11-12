//This program uses getchar function to input only positive integers
//and display their output using putchar function
//This is a faster method to input large data
//Used in competitive programming

#include<cstdio>
#define gc getchar
#define pc putchar

using namespace std;

inline void in(int &x)
{
	register char c = gc();
	while(c<'0' || c>'9')
		c = gc();

	x=0;
	while(c>='0' && c<='9')
	{
		x = 10 * x + c - 48;
		c = gc();
	}

}

inline void out(int a)
{
	char snum[12];
	int i=0;
	do
	{
		snum[i++]=a%10+'0';
		a=a/10;
	}while(a);
	i=i-1;

	while (i>=0)
	{
		pc(snum[i--]);
	}
}


inline void in_neg(int &x)
{
	register char c = gc();
	int neg=0;
	while( (c<'0' || c>'9') && c!='-')
		c = gc();

	if(c=='-')
	{
		neg=1;
		c=gc();
	}

	x=0;
	while(c>='0' && c<='9')
	{
		x = 10 * x + c - 48;
		c = gc();
	}

	if(neg)
		x=-x;

}

inline void out_neg(int a)
{
	if(a<0)
	{
		pc('-');
		a=-a;
	}

	char snum[12];
	int i=0;
	do
	{
		snum[i++]=a%10+'0';
		a=a/10;
	}while(a);
	i=i-1;

	while (i>=0)
	{
		pc(snum[i--]);
	}
}




int main()
{
	int x;
	in(x);
	out(x);

	in_neg(x);
	out_neg(x);
	
	return 0;
}
