//This program uses getchar function to input string
#include <cstdio>

inline void fastRead_string(char *str)
{
	    register char c = 0;
	    register int i = 0;

	    while (c < 33)
	        c = getchar();

	    while (c != '\n')
        {
 	        str[i] = c;
	        c = getchar();
	        i = i + 1;
	    }

	    str[i] = '\0';
}

int main()
{
	  char s[100];
	  fastRead_string(s);
      printf("%s\n", s);
	  return 0;
}
