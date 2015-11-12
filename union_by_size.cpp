// improvement 1
// union by size (make the smaller tree as the subset of the larger tree)

/*
element i has a parent stored in parent[i]
the root element of the set tree has parent[i]=negative of the size of the tree (initially all equals -1)
find returns the root of the set tree
union(x,y) changes x's root to the root of y or y's root to the root of x depending upon which one is smaller
and changes the size of the root of the single tree as well

*/


void makeSet(int parent[],int size)
{
	for(int i=0;i<size;i++)
	{
		parent[i]=-1;
	}
}

// with this implementation, find takes O(log n)
int find(int parent[], int i)
{
	//also include the condition if i is not in any set if required
	//not included here

    if (parent[i] < 0)  //negative parent means i is a root node
        return i;

    return find(parent, parent[i]);
}

// by size implementation of union()
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

	if(xset==yset)
		return;

	//now, check for the smaller set
	if(parent[xset]<parent[yset])
	{
		parent[xset]+=parent[yset];
		parent[yset]=xset;
	}

	else
	{
		parent[yset]+=parent[xset];
		parent[xset]=yset;
	}
}
