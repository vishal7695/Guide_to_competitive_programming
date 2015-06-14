// A Divide and Conquer based program for maximum subarray sum problem

#include<iostream>
#include <cstdio>
#include <climits>
using namespace std;


// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
   // Base Case: Only one element
   if (l == h)
     return arr[l];

   // Find middle point
   int m = (l + h)/2;

   int maxLeftSum=maxSubArraySum(arr,l,m);
   int maxRightSum=maxSubArraySum(arr,m+1,h);
   int maxLeftBorderSum=INT_MIN,maxRightBorderSum=INT_MIN,leftBorderSum=0,rightBorderSum=0;

   int i;

   for(i=m;i>=l;i--)
   {
       leftBorderSum+=arr[i];
       if(leftBorderSum>maxLeftBorderSum)
        maxLeftBorderSum=leftBorderSum;
   }

   for(i=m+1;i<=h;i++)
   {
       rightBorderSum+=arr[i];
       if(rightBorderSum>maxRightBorderSum)
        maxRightBorderSum=rightBorderSum;
   }

   //now, return the highest of left, right and crossing max sum

   if(maxLeftSum>maxRightSum)
   {
       if(maxLeftSum>(maxLeftBorderSum+maxRightBorderSum))
        return maxLeftSum;

       else
        return (maxLeftBorderSum+maxRightBorderSum);
   }

   else if(maxRightSum>(maxLeftBorderSum+maxRightBorderSum))
    return maxRightSum;

   else
    return (maxLeftBorderSum+maxRightBorderSum);

}

/*Driver program to test maxSubArraySum*/
int main()
{
    int n;
    cout<<"how many elements you want to enter ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;

    for(int i=0;i<n;i++)
        cin>>arr[i];

   int max_sum = maxSubArraySum(arr, 0, n-1);
   printf("Maximum contiguous sum is %d\n", max_sum);

   return 0;
}
