//lis in O(NLogN)
#include <bits/stdc++.h>
using namespace std;

int getBound(vector<int> &a, int l, int r, int x){

    while (r-l > 1){
        int mid = l + (r-l)/2;

        if (a[mid] >= x)
            r = mid;

        else
            l = mid;
    }
 
    return r;
}
 
int LIS(vector<int> &a){
    int i,j,k,n=a.size();

    vector<int> lis(n, 0);
    int result = 1;
 
    lis[0] = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] < lis[0])
            lis[0] = a[i];

        else if (a[i] > lis[result-1])
            lis[result++] = a[i];

        else
            lis[getBound(lis, -1, result-1, a[i])] = a[i];
    }
    
    return result;
}

