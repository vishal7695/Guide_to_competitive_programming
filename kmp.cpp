// A C++ program that implements KMP algorithm for pattern searching
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int j = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[j])
       {
         j++;
         lps[i] = j;
         i++;
       }
       else // (pat[i] != pat[j])
       {
         if (j != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           j = lps[j-1];

           // Also, note that we do not increment i here
         }
         else // if (j == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

// Driver program to test above function
int main()
{
    char text[100];
    char pattern[50];
    gets(text);
    gets(pattern);

   char *txt = text;
   char *pat = pattern;

   KMPSearch(pat, txt);
   return 0;
}
