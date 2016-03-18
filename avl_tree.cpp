//AVL tree

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    int height;
};

int height(node* &root)
{
    if(!root)
        return 0;

    return root->height;
}

node *newNode()
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
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
    n->height=1;
    n->data=x;

    return n;
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

void levelWiseDisplayWithHeight(node* &root)
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

            cout<<q.front()->data<<"("<<height(q.front())<<") ";
            q.pop();
        }
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

int balanceFactor(node* &root)
{
    if(!root)
        return 0;

    return height(root->left)-height(root->right);
}

/*
let w be the newly inserted node

while travelling up from w, 
    node z is the first unbalanced node 

    node y is the child of z on the path from w to z
   
    node x is the grandchild of z on the path from w to z (ie. x is child of y)


The case will be decided by -
*  y is the left/right child of z and x is the left/right child of y


Cases -

1) Left left case - y is left child of z and x is left child of y
                    RightRotate z

2) Left right case -y is left child of z and x is right child of y


3) Right Right case -y is right child of z and x is right child of y
                     LeftRotate z

4) Right left case -y is right child of z and x is left child of y


* The parameter of the rotate functions is z 


*/

void rightRotate(node* &z)
{
    node* y=z->left;
    node* tempZ=z;

    z=y;
    tempZ->left=y->right;
    y->right=tempZ;

    //update heights
    z->right->height=max(height(z->right->left),height(z->right->right))+1;
    z->height=max(height(z->left),height(z->right))+1;

}

void leftRotate(node* &z)
{
    node* y=z->right;
    node* tempZ=z;

    z=y;
    tempZ->right=y->left;
    y->left=tempZ;

    //update heights
    z->left->height=max(height(z->left->left),height(z->left->right))+1;
    z->height=max(height(z->left),height(z->right))+1;

}


void insert(node* &root, int x)
{
    node* nw=newNode(x);
    
    if(!root)
    {
        root=nw;
        return;
    }

    if(x<root->data)
        insert(root->left,x);

    else
        insert(root->right,x);

    //update height of the ancestors
    root->height=max(height(root->left),height(root->right))+1;

    //check the balance
    int balance=balanceFactor(root);

    //Now, find the case to be applied here
    //depending upon the balance factor and the key inserted
    
    // Left Left Case
    if (balance > 1 && x < root->left->data)
    {
        cout<<"LL at "<<root->data<<endl;

        rightRotate(root);
        return ;
    }
 
    // Right Right Case
    if (balance < -1 && x > root->right->data)
    {
        cout<<"RR at "<<root->data<<endl;

        leftRotate(root);
        return ;
    }
 
    // Left Right Case
    if (balance > 1 && x > root->left->data)
    {
        cout<<"LR at "<<root->data<<endl;

        leftRotate(root->left);
        rightRotate(root);
        return ;
    }
 
    // Right Left Case
    if (balance < -1 && x<root->right->data)
    {
        cout<<"RL at "<<root->data<<endl;

        rightRotate(root->right);
        leftRotate(root);
        return ;
    }


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
        if(!deleteNode(root->left,x))
            return false;
    }

    else if(root->data<x)
    {
        if(!deleteNode(root->right,x))
            return false;
    }

    //element to delete found in the current node
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

        //if it has a single child or no child
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


    //If no node is left in the tree
    if(root==NULL)
        return true;

    //update height of the ancestors
    root->height=max(height(root->left),height(root->right))+1;

    //check the balance
    int balance=balanceFactor(root);

    //Now, find the case to be applied here
    //depending upon the balance factor and the key inserted
    
    // Left Left Case
    if (balance > 1 && x < root->left->data)
    {
        cout<<"LL at "<<root->data<<endl;

        rightRotate(root);
    }
 
    // Right Right Case
    else if (balance < -1 && x > root->right->data)
    {
        cout<<"RR at "<<root->data<<endl;

        leftRotate(root);
    }
 
    // Left Right Case
    else if (balance > 1 && x > root->left->data)
    {
        cout<<"LR at "<<root->data<<endl;

        leftRotate(root->left);
        rightRotate(root);
    }
 
    // Right Left Case
    else if (balance < -1 && x<root->right->data)
    {
        cout<<"RL at "<<root->data<<endl;

        rightRotate(root->right);
        leftRotate(root);
    }

    return true;
}


int main()
{
    node* root=NULL;
    int x,y,i,j;

    do
    {
        cout<<endl<<endl;
        cout<<"AVL tree operations"<<endl<<endl;
        cout<<"1 Insertion"<<endl;
        cout<<"2 Deletion"<<endl;
        cout<<"3 level order display"<<endl;
        cout<<"4 inorder display"<<endl;
        cout<<"5 levelwise display"<<endl;
        cout<<"6 levelwise display with height"<<endl;

        cout<<"10 Exit"<<endl;

        cout<<"Enter your choice ";
        cin>>x;

        switch(x)
        {
            case 1:cout<<"How many elements do you want to insert in the AVL tree ";
                   cin>>j;
                   cout<<"Enter "<<j<<" elements"<<endl;
                   for(i=1;i<=j;i++)
                   {
                       cin>>y;
                       insert(root,y);
                   }
                break;

            case 2:cout<<"Enter the element to delete from the BST ";
                   cin>>y;
                   deleteNode(root,y);
                break;

           case 3:cout<<"Level order traversal of the AVL tree is "<<endl;
                  levelorder(root);
                break;

           case 4:cout<<"Inorder traversal of the AVL tree is "<<endl;
                  inorder(root);
                break;

           case 5:cout<<"Levelwise traversal of the AVL tree is "<<endl;
                  levelWiseDisplay(root);
                break;

           case 6:cout<<"Levelwise traversal with height of the AVL tree is "<<endl;
                  levelWiseDisplayWithHeight(root);
                break;


           case 10:cout<<"Exiting"<<endl;
                break;

           default:cout<<"Invalid choice";

        }


    }while(x!=10);


    return 0;
}
