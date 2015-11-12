//program to print product of gcd of all subsets of an array
#include <bits/stdc++.h>

using namespace std;

#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define W(x) while(x--)

struct tree
{
	int index,gcd;
	tree **next;

};

int euclid_gcd(int a, int b)
{
    if(a==0)
        return b;

    return euclid_gcd(b%a,a);
}

int pos;

void createNode(int index, int gcd, tree *&parent,int n,vector<int> &a,int position)
{
    cout<<endl<<"(index,position,children,gcd,parent_position)="<<index<<", "<<pos<<", "<<(n-1-index)<<", "<<gcd<<", "<<position<<"  ";    

    int temp=pos;

    if(index==n-1)
    {
        cout<<"leaf node"<<endl;
        return ;
    } 

    parent->next=new tree*[n-1-index];

    for(int i=0;i<(n-1-index);i++)
    {
        pos++;
        cout<<endl<<"current_index="<<index+1+i<<endl;
        parent->next[i]=new tree;
        parent->next[i]->index=index+1+i;
        parent->next[i]->gcd=euclid_gcd(gcd,a[index+1+i]);

        //now, create subtree for this subtree recursively
        createNode(parent->next[i]->index,parent->next[i]->gcd,parent->next[i],n,a,temp);
    }
}

void print(int n, tree *&parent)
{
    cout<<parent->index<<", "<<pos<<", "<<parent->gcd<<endl;

    for(int i=0;i<(n-parent->index-1);i++)
    {
        /*
        if(index+1!=parent->next[i]->index)
        {
            //print spaces
            for(int j=0;j<spaces;j++)
                cout<<endl<<"      ";
        }
        cout<<" ";
        */

        pos++;
        print(n,parent->next[i]);
    }
    
}

int main()
{
	int i,j,k,l;
	int t,n;
        pos=0;

	in(t);
	W(t)
	{
		in(n);
		vector<int> a(n);
		for(i=0;i<n;i++)
			in(a[i]);
		
		//now create a tree
		tree *start=new tree;
		start->index=-1;
		start->gcd=1;
                start->next=new tree*[n];
                for(i=0;i<n;i++)
                {
                    start->next[i]=new tree;
                    start->next[i]->index=i;
                    start->next[i]->gcd=a[i];
                }

                //now, build the tree
                for(i=0;i<n;i++)
                {
                    pos++;
                    createNode(i,a[i],start->next[i],n,a,0);
                }

                //now, print the tree(level wise, if possible)
                cout<<endl<<"The tree being traversed recursively is (index,position,gcd) "<<endl;
                pos=0; 
                for(i=0;i<n;i++)
                {
                    pos++;
                   //cout<<"("<<start->next[i]->index<<","<<start->next[i]->gcd<<")";
                    print(n,start->next[i]);
                }

	}

	return 0;
}


