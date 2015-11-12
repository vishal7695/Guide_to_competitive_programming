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

string find_max_common(string s, int x, vs &str)
{
    //check whether s is present in all strings
    bool found=true;

    for(int i=0;i<str.sz;i++)
    {
        //check whether s is present in str[i]
        //if not set found=false
        //else iterate next
        if(str[i].find(s)==string::npos)
        {
            found=false;
            break;
        }
    }

    if(found==true)
        return s;

    else
    {
        //return lexicographically smaller one
        string s1=find_max_common(s.substr(0,x-1),x-1,str);
        string s2=find_max_common(s.substr(1,x-1),x-1,str);

        if(s1.len>s2.len)
            return s1;

        else if(s1.len<s2.len)
            return s2;

        else
        {
            //both of equal length
            if(lexicographical_compare(s1.begin(),s1.end(), s2.begin(), s2.end()))
                    {        
                        return s1;
                    }

            else
                return s2;
        }
    }
}

int main()
{
    int j,k,x,y,z;
    int t,n;
    int m,s,p,q;
    in(t);
    W(t)
    {       
        in(n);
        cin.ignore(256,'\n');
        vs str(n);
        x=50;j=0;
        repn(i,n)
        {
            cin>>str[i];
            y=str[i].len;
            if(y<x)
            {
                x=y;
                j=i;
            }
        }

        swap(str[0],str[j]);
        string s=find_max_common(str[0],x,str);

        cout<<s<<endl;
        
    }
    return 0;
}

