//Binary search tree operations

#include<bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int data;
    tree* left;
    tree* right;
}node;

node *newNode()
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    cout<<endl<<"enter the value of node  ";
    int x;
    cin>>x;
    n->data=x;

    return n;
}

node *newNode(int x)
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    n->data=x;

    return n;
}

bool findNode(node* &root, int x)
{
    if(!root)
        return false;

    node* temp=root;
    while(temp)
    {
        if(temp->data==x)
            return true;

        if(temp->data>x)
        {
            //left
            temp=temp->left;
        }

        else
            temp=temp->right;
    }

    return false;
}

void insert(node* &root, int x)
{
    node* nw=newNode(x);
    
    if(!root)
    {
        root=nw;
        return;
    }

    //if root is not null
    //find the correct position of the new node
    
    node* temp=root;

    while(temp)
    {
        if(temp->data==x)
        {
            //element already there
            return ;
        }

        else if(temp->data>x)
        {
            //new element will go on the left side
            if(temp->left)
            {
                temp=temp->left;
            }

            else
            {
                //insert here
                temp->left=nw;
                return ;
            }
        }

        else 
        {
            //new element will go on the right side
            if(temp->right)
            {
                temp=temp->right;
            }

            else
            {
                //insert here
                temp->right=nw;
                return ;
            }
        }

    }

}

int findMin(node* &root)
{
    if(!root)
        return -1;

    node *temp=root;
    int mn;

    while(temp)
    {
        if(!temp->left)
            mn=temp->data;

        temp=temp->left;
    }

    return mn;
}

int findMax(node* &root)
{
    if(!root)
        return -1;

    int mx;
    node *temp=root;

    while(temp)
    {
        if(!temp->right)
            mx=temp->data;

        temp=temp->right;
    }

    return mx;
}

bool deleteNode(node* &root, int x)
{
    if(!root)
    {
        return false;
    }

    else if(root->data>x)
    {
        return deleteNode(root->left,x);
    }

    else if(root->data<x)
    {
        return deleteNode(root->right,x);
    }

    //data is in the current node
    //proceed to deletion
    else
    {

        //if it is a full node
        if(root->left && root->right)
        {
            //replace the current node with the maximum node in its left
            //and then delete the max node
            
            int mx=findMax(root->left);
            root->data=mx;
            return deleteNode(root->left,mx);
        }

        //if it has a single child
        else
        {
            node* temp=root;

            if(root->left)
            {
                root=root->left;
            }

            else
            {
                root=root->right;
            }

            delete temp;

        }

        return true;
    }

}



node* deleteNodeRecursive(node* &root, int x)
{
    if(!root)
    {
        return NULL;
    }

    else if(root->data>x)
    {
        root->left=deleteNodeRecursive(root->left,x);
    }

    else if(root->data<x)
    {
        root->right=deleteNodeRecursive(root->right,x);
    }

    //data is in the current node
    //proceed to deletion
    else
    {

        //if it is a full node
        if(root->left && root->right)
        {
            //replace the current node with the maximum node in its left
            //and then delete the max node
            
            int mx=findMax(root->left);
            root->data=mx;
            root->left=deleteNodeRecursive(root->left,mx);
        }

        //if it has a single child
        else
        {
            node* temp=root;

            if(root->left)
            {
                root=root->left;
            }

            else
            {
                root=root->right;
            }

            delete temp;
        }

    }

    return root;
}


void levelorder(node* &root)
{
    if(!root)
        return ;

    queue<node*> q;
    node* temp;

    q.push(root);

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        
        //display
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }
    
}

void inorder(node* &root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void levelWiseDisplay(node* &root)
{
    if(root==NULL)
        return; 

    //let us consider a node with value equal to -1 as unique node to be used as a level separator

    node *unique=newNode(-1);

    queue<node*> q;
    q.push(root);
    q.push(unique);

    while(!q.empty())
    {
        if(q.front()->data==-1)
        {
            //unique symbol
            cout<<endl;

            q.pop();
            if(!q.empty())
                q.push(unique);
        }

        else
        {
            if(q.front()->left)
                q.push(q.front()->left);

            if(q.front()->right)
                q.push(q.front()->right);

            cout<<q.front()->data<<" ";
            q.pop();
        }
    }

}

int lca(node* &root,int x, int y)
{
    if(!root)
        return -1;

    node* temp=root;

    while(temp)
    {
        if(temp->data<x && temp->data<y)
        {
            temp=temp->right;
        }

        else if(temp->data>x && temp->data>y)
        {
            temp=temp->left;
        }

        else
        {
            //if x and y are on different sides of temp
            //or if one of them is on temp
            //in both cases temp is the lca
            
            //But we need to check whether x and y are present in the tree or not
           
            if(x<temp->data)
            {
                if(!findNode(temp->left,x))
                        return -1;

                else
                {
                    //x found
                    //find y
                    if(y<temp->data)
                    {
                        if(!findNode(temp->left,y))
                            return -1;
                    }

                    else if(y>temp->data)
                    {
                        if(!findNode(temp->right,y))
                            return -1;
                    }
                }
            }

            else if(x>temp->data)
            {
                if(!findNode(temp->right,x))
                        return -1;

                else
                {
                    //x found
                    //find y
                    if(y<temp->data)
                    {
                        if(!findNode(temp->left,y))
                            return -1;
                    }

                    else if(y>temp->data)
                    {
                        if(!findNode(temp->right,y))
                            return -1;
                    }
                }
            }

            else
            {
                //if x is found at temp
                //find y
                if(y<temp->data)
                {
                    if(!findNode(temp->left,y))
                        return -1;
                }

                else if(y>temp->data)
                {
                    if(!findNode(temp->right,y))
                        return -1;
                }

            }

            return temp->data;
            //end of else
        }

        //end of while loop
    }

    return -1;
    //end of function
}

int ksmallest(node* &root, int k, int &count)
{
/*
    if(root)
    {
        cout<<endl<<"Entry "<<root->data<<", "<<count;
    }
*/
    if(!root)
        return -1;

    int x=ksmallest(root->left,k,count);

    if(x!=-1)
        return x;

    count++;


    //cout<<endl<<"Exit "<<root->data<<", "<<count;

    if(count==k)
        return root->data;

    return ksmallest(root->right,k,count);
}


bool predecessor(node* &root, int &pre, int x)
{
    if(!root)
        return false;

    if(root->data==x)
    {
        //max value in left subtree is the predecessor
        
        //if left child is NULL, then the current value in pre is the predecessor
        
        if(root->left)
        {
            //find the max element in the left subtree
            pre=findMax(root->left);
        }

        return true;
    }

    else if(root->data<x)
    {
        pre=root->data;
        return predecessor(root->right,pre,x);
    }

    return predecessor(root->left,pre,x);
}


bool successor(node* &root, int &suc, int x)
{
    if(!root)
        return false;

    if(root->data==x)
    {
        //min value in right subtree is the successor
        
        //if right child is NULL, then the current value in suc is the successor
        
        if(root->left)
        {
            //find the min element in the right subtree
            suc=findMin(root->right);
        }

        return true;
    }

    else if(root->data>x)
    {
        suc=root->data;
        return successor(root->left,suc,x);
    }

    return successor(root->right,suc,x);
}



int main()
{
    int x,y,n;
    int i,j;
    node *root=NULL;

    do
    {
        cout<<endl<<endl;
        cout<<"BINARY SEARCH TREE OPERATIONS "<<endl<<endl;
        cout<<"1 insert"<<endl;
        cout<<"2 delete recursive"<<endl;
        cout<<"3 find"<<endl;
        cout<<"4 level order display"<<endl;
        cout<<"5 level wise display"<<endl;
        cout<<"6 inorder display"<<endl;
        cout<<"7 delete node differently"<<endl;
        cout<<"8 LCA of two nodes"<<endl;
        cout<<"9 kth smallest element"<<endl;
        cout<<"10 Inorder predecessor"<<endl;
        cout<<"11 Inorder successor"<<endl;

        cout<<"12 exit"<<endl;
        cout<<endl<<"Enter your choice ";
        cin>>x;

        switch(x)
        {
            case 1:cout<<"How many elements do you want to insert in the BST ";
                   cin>>n;
                   cout<<"Enter "<<n<<" elements"<<endl;
                   for(i=1;i<=n;i++)
                   {
                       cin>>y;
                       insert(root,y);
                   }
                break;

            case 2:cout<<"Enter the element to delete from the BST ";
                   cin>>y;
                   deleteNodeRecursive(root,y);

                   cout<<endl;
                break;

            case 3:cout<<"Enter the element to find in the BST ";
                   cin>>y;
                   if(findNode(root,y))
                       cout<<"Element found";
                   else
                       cout<<"Element not found";

                   cout<<endl;
                break;

            case 4:cout<<"The BST diplayed in level order is "<<endl;
                   levelorder(root);
                break;

            case 5:cout<<"The BST diplayed levelwise is "<<endl;
                   levelWiseDisplay(root);
                break;
                
            case 6:cout<<"Inorder display "<<endl;
                   inorder(root);
                break;

            case 7:cout<<"Enter the element to delete from the BST ";
                   cin>>y;
                   if(deleteNode(root,y))
                       cout<<"Element deleted";
                   else
                       cout<<"Could not delete";

                   cout<<endl;
                break;

            case 8:cout<<"Enter the value of two nodes whose lca is required"<<endl;
                   cin>>i>>j;
                   y=lca(root,i,j);
                   if(y!=-1)
                       cout<<"The lca of two nodes is "<<y<<endl;
                   else
                       cout<<"LCA not found"<<endl;
                
                   break;

            case 9:cout<<"Enter the value of K ";
                   cin>>y;
                   i=0;
                   j=ksmallest(root,y,i);
                   if(i==y)
                       cout<<"Kth smallest element is "<<j<<endl;
                   else
                       cout<<"Not enough elements in the BST"<<endl;
                    break;

            case 10:cout<<"Enter the value whose predecessor you want ";
                    cin>>y;
                    i=-1;
                    if(predecessor(root,i,y) && i!=-1)
                        cout<<"Predecessor of required key is "<<i<<endl;
                    else
                        cout<<"Predecessor not found"<<endl;

                    break;

            case 11:cout<<"Enter the value whose successor you want ";
                    cin>>y;
                    i=-1;
                    if(successor(root,i,y) && i!=-1)
                        cout<<"successor of required key is "<<i<<endl;
                    else
                        cout<<"successor not found"<<endl;

                    break;

            case 12:cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid input"<<endl;
        }

    }while(x!=12);


    return 0;
}
