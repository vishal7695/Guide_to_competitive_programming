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

	x=0; while(c>='0' && c<='9') { x = 10 * x + c - 48; c = gc(); } 
} 


int main()
{
    //clock_t start = clock();
    //ios_base::sync_with_stdio(false);
    /*
    #ifndef ONLINE_JUDGE    
        freopen("i_p","r",stdin);
    #endif
    */

    //main starts here
    int j,k,l,m,n;
    int a,b,c;
    int x,y,z;
    int t;

    string str="vishal sharma";
    x=7636363;
    float f=77373737.7378;


    printf("%d",x); pn;
    printf("%d",x);pn;
    printf("%5d",x);pn;
    printf("%9d",x);pn;
    printf("%09d",x);pn;
    printf("%-9d",x);pn;
    printf("%9d",x);pn;

    printf("%f",f);pn;
    printf("%8f",f);pn;
    printf("%9f",f);pn;
    printf("%10f",f);pn;
    printf("%08f",f);pn;
    printf("%09f",f);pn;
    printf("%010f",f);pn;
    printf("%-8f",f);pn;
    printf("%-9f",f);pn;
    printf("%-10f",f);pn;
    printf("%.7f",f);pn;
    printf("%.8f",f);pn;
    printf("%.9f",f);pn;
    printf("%8.7f",f);pn;
    printf("%9.8f",f);pn;
    printf("%10.9f",f);pn; 
    printf("%09.8f",f);pn;
    printf("%010.9f",f);pn;
    printf("%-8.7f",f);pn;
    printf("%-9.8f",f);pn;
    printf("%-10.9f",f);pn;


    pn,pn;

    int Fahrenheit;

    for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
            printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));


	pn,pn;

	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Float number: %3.2f\n", 3.14159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Unsigned value: %u\n", 150);
	printf("Just print the percentage sign %%\n", 10);

	pn,pn;

	printf(":%s:\n", "Hello, world!");
	printf(":%15s:\n", "Hello, world!");
	printf(":%.10s:\n", "Hello, world!");
	printf(":%-10s:\n", "Hello, world!");
	printf(":%-15s:\n", "Hello, world!");
	printf(":%.15s:\n", "Hello, world!");
	printf(":%15.10s:\n", "Hello, world!");
	printf(":%-15.10s:\n", "Hello, world!");



    //cout << (((double)clock() - start) / CLOCKS_PER_SEC )<< "\n";
    return 0;

