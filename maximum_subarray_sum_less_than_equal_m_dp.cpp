// maximum subarray of sum less than equal to m
// dynamic programming
// twisted kadane's algorithm

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


int main()
{
    int j,k,x,y,z;
    int t,n;
    int m,s,p,q;
    in(n),in(m);
    vi a(n);
    repn(i,n)
        in(a[i]);

    int max_so_far=a[0];
    int curr_max=a[0];

    int i=1;
    j=0;

    while(i<n)
    {
        x=curr_max+a[i];

        if(x==m)
        {
            max_so_far=m;
            break;
        }

        else if(x<m)
        {
            curr_max=x;

            if(curr_max>max_so_far)
                max_so_far=curr_max;

            i++;
        }

        else
        {
            //need to remove some element
            curr_max-=a[j];
            j++;
        }
    }

    out(max_so_far),pn;
    
    return 0;
}

