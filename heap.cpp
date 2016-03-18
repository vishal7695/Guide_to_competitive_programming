//Binary Heap
//max binary heap

#include<bits/stdc++.h>
using namespace std;

struct heap
{
    int *array;
    int count;
    int capacity;
    int heap_type;   //min or max heap 
};

//parent of node at ith index in array
int parent(heap* &head, int i)
{
    if(i<=0 || i>=head->count)
        return -1;

    return (i-1)/2;
}

//children of a node at ith index in the array
int leftChild(heap* &head, int i)
{
    int left=2*i+1;
    if(left>=head->count)
        return -1;

    return left;
}

int rightChild(heap* &head, int i)
{
    int right=2*i+2;
    if(right>=head->count)
        return -1;

    return right;
}



void resizeHeap(heap* &head)
{
    int* old_array=head->array;
    head->array=new int[2*head->capacity];

    for(int i=0;i<head->capacity;i++)
    {
        head->array[i]=old_array[i];
    }

    head->capacity*=2;
    delete[] old_array;
}

//minimum element is always at the root of min heap(first index of array)
int getMin(heap* &head)
{
    if(head->count==0)
        return -1;

    return head->array[0];
}

void percolateDown(heap* &head, int i)
{
    int left=leftChild(head,i);
    int right=rightChild(head,i);

    int mn=i;

    if(left!=-1 && head->array[left]<head->array[mn])
        mn=left;

    if(right!=-1 && head->array[right]<head->array[mn])
        mn=right;


    if(mn!=i)
    {
        //need to heapify
        swap(head->array[i],head->array[mn]);

        percolateDown(head,mn);
    }

}

int deleteMin(heap* &head)
{
    if(head->count==0)
        return -1;

    int mn=head->array[0];

    //replace with the last element
    head->array[0]=head->array[head->count-1];
    head->count--;

    //heapify the disturbed heap
    percolateDown(head,0);

    return mn;
} 

//percolate up
void insert(heap* &head, int x)
{
    if(head->count==head->capacity)
        resizeHeap(head);

    head->count++;

    //i will store the index where we should store the new value
    //we will start with the last index ie, count-1 and percolate up accordingly
    int i=head->count-1;

    while(i>0 && x<head->array[parent(head,i)])
    {
        head->array[i]=head->array[parent(head,i)];
        i=parent(head,i);
    }

    //now, insert the new value
    head->array[i]=x;
}

void display(heap* &head)
{
    if(head->count==0)
        return ;

   queue<int> q;
   q.push(0);
   q.push(-1);

   int i,left,right;

   while(!q.empty())
   {
        i=q.front();
        q.pop();

        //display
        if(i==-1 )
        {
            cout<<endl; 
            
            if(!q.empty() )
                q.push(-1);
        }

        else
        {
            cout<<head->array[i]<<" ";

            left=leftChild(head,i);
            if(left!=-1)
                q.push(left);

            right=rightChild(head,i);
            if(right!=-1)
                q.push(right);

        }
            
   }
}

//create heap
void create(heap* &head)
{
    //keeping default capacity of 15
    int capacity=15;

    head=new heap;

    head->count=0;
    head->capacity=capacity;
    head->array=new int[capacity];

    //heap_type=1 for max heap
    //and heap_type=0 for min heap
    head->heap_type=0;
}

int main()
{
   heap* head=NULL; 
   create(head);

   int x,i,j;

   do
   {
       cout<<endl<<endl;
       cout<<"BINARY HEAP OPTIONS "<<endl<<endl;

       cout<<"1 Insert"<<endl;
       cout<<"2 Delete minimum"<<endl;
       cout<<"3 Display"<<endl;
       cout<<"10 Exit"<<endl;

       cout<<"Enter your choice ";
       cin>>x;

       cout<<endl;

       switch(x)
       {
           case 1:cout<<"How many elements to insert ";
                  cin>>j;
                  cout<<"Enter "<<j<<" values "<<endl;
                  for(int k=1;k<=j;k++)
                  {
                      cin>>i;
                      insert(head,i);
                  }

               break;

           case 2:i=deleteMin(head);
                  if(i!=-1)
                      cout<<"The minimum element in the heap is "<<i;

                  else
                      cout<<"No element in the heap";
               break;

           case 3:cout<<"The binary heap is "<<endl;
                  display(head);

               break;

           case 10:cout<<"Exiting...";
               break;

           default:cout<<"Invalid choice ";
       }

   }while(x!=10);


   return 0;
}
