#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool compare1(const pair<int, int> &l, const pair<int, int> &r)
{
    //Ascending
    return l.second<r.second;
}


bool compare2(const pair<int, int> &l, const pair<int, int> &r)
{
    //descending
    return l.second>r.second;
}

int main()
{

    int i,j,n;

    cout<<"no. of pairs ??  ";
    cin>>n;
    vector<pair<int, int> > p(n);

    cout<<"enter the values of pairs "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    //sort in ascending order
    sort(p.begin(), p.end(),compare1);

    //display
    cout<<endl<<"displaying the pairs in ascending order"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<p[i].first<<"  "<<p[i].second<<endl;
    }

    //sort in descending order
    sort(p.begin(), p.end(),compare2);

    //display
    cout<<endl<<"displaying the pairs in descending order"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<p[i].first<<"  "<<p[i].second<<endl;
    }

    return 0;
}
