//This program uses getchar function to input only positive integers
//and display their output using putchar function
//This is a faster method to input large data
//Used in competitive programming

#include<cstdio>
#define gc getchar
#define pc putchar

using namespace std;

inline void scanint(int &x)
{
  char c = gc();

  while(c<'0' || c>'9')
   c = gc();

  x=0;

  while(c>='0' && c<='9')
  {
   x = 10 * x + c - 48;
   c = gc();
  }

}

inline void fastWrite(int a)
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


int main()
{
 int x;
 scanint(x);
 fastWrite(x);

 return 0;
}
