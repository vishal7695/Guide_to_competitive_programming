#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    int t,i,j,k,x1, x2, y1, y2,ix1,ix2,iy1,iy2,s,result,x,y;

    scanf("%d",&t);

    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        result=0;

        if(x1<x2)
        {
            ix1=x1;
            ix2=x2;
        }


        else
        {
            ix1=x2;
            ix2=x1;
        }

        if(y1<y2)
        {
            iy1=y1;
            iy2=y2;
        }

        else
        {
            iy1=y2;
            iy2=y1;
        }

        for(x=ix1;x<=ix2;x++)
        {
            for(y=iy1;y<=iy2;y++)
            {
                s = ((y-y1)*(x2-x1))-((y2-y1)*(x-x1));

                if(s==0)
                {
                    if(!(x==x1&&y==y1) && !(x==x2&&y==y2))
                        result++;
                }
            }
        }

        cout<<result<<endl;
    }


    return 0;
}
