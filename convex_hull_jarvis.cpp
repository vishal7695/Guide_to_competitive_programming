#include<bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
};

int orientation(point &p, point &q, point &r)
{
    int d=(((q.y-p.y)*(r.x-q.x))-((r.y-q.y)*(q.x-p.x)));
    return d;
}

double getDistance(point &p, point &q)
{
    double distSq=(pow((p.x-q.x),2)+pow((p.y-q.y),2));
    double dist=sqrt(distSq);
    return dist;
}

void convexHull(vector<point> &points)
{
    vector<point> hull;
    vector<int> order;
    int i,j,k,x,y;
    int n=points.size();
    int l,p,q;
    //pick the leftmost point
    
    l=0;
    for(i=1;i<n;i++)
    {
        if(points[i].x<points[l].x)
            l=i;
    }

    p=l;

    do
    {
		//add this point to the hull
        hull.push_back(points[p]);

        //pick the next one
        q=(p+1)%n;

        for(i=0;i<n;i++)
        {
			//If this point is not the same as the previous one
            if(point[q].x!=point[i].x || point[q].y!=point[i].y)
            {
                int d=orientation(points[p], points[i], points[q]);

				//select the most counter clockwise point to p
                if(d<0)
                    q=i;
            }
        }

        p=q;

    }while(p!=l);

    //display the hull points
    n=hull.size();
    j=0;
	cout<<"the convex hull is "<<endl;
    while(j<n)
    {
        cout<<hull[j].x<<" "<<hull[j].y<<endl;
        j++;
    }
    cout<<endl;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);

    int i,j,k,n;
    int t,x,y,z;
    cin>>t;

    while(t--)
    {
        cin>>n;
        vector<point> points(n);

		//get all the points
        for(i=0;i<n;i++)
        {
            cin>>points[i].x>>points[i].y;
        }

        convexHull(points);
    }

    return 0;
}
