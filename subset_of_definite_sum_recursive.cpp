//subset with a definite sum
//recursive solution
//A variant of the knapsack problem

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

//#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)

#define pb push_back
#define len length()
#define sz size()

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pn printf("\n")
#define ps printf(" ")

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repn(i,n) rep(i,0,n)
#define W(a) while(a--)

/*======================================Templates Ends========================*/
/* Main Code Starts from here */


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

bool subset_sum(vi &set,int curr_sum, int sum, int n)
{
    if(curr_sum==sum)
        return true;

    if(n==0)
        return false;

    return subset_sum(set,curr_sum,sum,n-1)|| subset_sum(set,curr_sum+set[n-1],sum,n-1);

}
int main()
{
    int j,k,x,y,z;
    int t,n;
    int m,s,p,q;
    cout<<"No. of elements ";
    cin>>n;
    vi set(n);
    if(n>0)
        cout<<"Enter the no. of elements"<<endl;

    repn(i,n)
    {
        in(set[i]);
    }

    cout<<"Enter the value of required sum ";
    cin>>m;

    cout<<endl<<"set with sum="<<m;
    if(!subset_sum(set,0,m,n))
    {
        cout<<" not";
    }

    cout<<" found\n";

    return 0;
}
//subset with a definite sum
//recursive solution
//A variant of the knapsack problem

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

//#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)

#define pb push_back
#define len length()
#define sz size()

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pn printf("\n")
#define ps printf(" ")

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repn(i,n) rep(i,0,n)
#define W(a) while(a--)

/*======================================Templates Ends========================*/
/* Main Code Starts from here */


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

bool subset_sum(vi &set,int curr_sum, int sum, int n)
{
    if(curr_sum==sum)
        return true;

    if(n==0)
        return false;

    return subset_sum(set,curr_sum,sum,n-1)|| subset_sum(set,curr_sum+set[n-1],sum,n-1);

}
int main()
{
    int j,k,x,y,z;
    int t,n;
    int m,s,p,q;
    cout<<"No. of elements ";
    cin>>n;
    vi set(n);
    if(n>0)
        cout<<"Enter the no. of elements"<<endl;

    repn(i,n)
    {
        in(set[i]);
    }

    cout<<"Enter the value of required sum ";
    cin>>m;

    cout<<endl<<"set with sum="<<m;
    if(!subset_sum(set,0,m,n))
    {
        cout<<" not";
    }

    cout<<" found\n";

    return 0;
}

