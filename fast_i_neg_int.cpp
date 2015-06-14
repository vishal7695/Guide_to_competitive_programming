//This program is to input integers (negative as well as positive) using getchar()
//This is a faster method for large data input
//Mainly used in competitive programming

#include<cstdio>

inline void fastRead_int(int &x)
{
   register int c = getchar();
   x = 0;
   int neg = 0;
	
   //all the digits 0 to 9 lie in the ascii range of 48 to 57
   
   for(; ((c<48 || c>57) && c != '-');c = getchar());                   //loop until first digit of the entered number appears

   if(c=='-')
   {
       neg = 1;
	   c = getchar();
   }

	    for(; c>47 && c<58 ; c = getchar())
        {
	        x = (x<<1) + (x<<3) + c - 48;
	    }

	    if(neg)
	        x = -x;
}

int main()
{

	  int n;
      fastRead_int(n);
      printf("%d\n", n);
	  return 0;
}
