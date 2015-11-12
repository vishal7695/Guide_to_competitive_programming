// program to sort words lexicographically by hashing

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

#define in(a) scanf("%d",&a)
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


int main()
{
    int i,j,k,x,y,z;
    int t,n;
    int m,s,p,q;
    
    in(n);
    msi mp;
    string str;
    cin.ignore(256,'\n');
    repn(i,n)
    {
        cin>>str;
        if(mp.find(str)!=mp.end())
            mp[str]++;

        else
            mp[str]=1;
    }

    cout<<endl<<"input words in sorted order are"<<endl;
    for(msi::iterator it=mp.begin();it!=mp.end();it++)
        cout<<it->first<<endl;
 
    return 0;
}

