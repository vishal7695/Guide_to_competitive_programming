#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

#define in(a) scanf("%d",&a)
#define out(a) printf("%d",a)

#define pb push_back
#define len length()
#define sz size()

#define gc getchar_unlocked
#define pc putchar_unlocked
#define pn printf("\n")
#define ps printf(" ")

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repn(i,n) rep(i,0,n)
#define W(a) while(a--)

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
    in(x);
    n->data=x;

    return n;
}

void create(node* &root)
{
    int i,j,k,n;
    cout<<endl<<"Enter the no. of nodes you want to insert ";
    cin>>n;

    if(n<=0)
        return ;

    queue<node*> q;
    root=newNode();
    q.push(root);

    i=1;
    while(i<n)
    {
        node *temp=q.front();
        if(!temp->left)
        {
            //left child is empty
            temp->left=newNode();
            i++;
            q.push(temp->left);
        }

        else if(!temp->right)
        {
            //right child is empty
            temp->right=newNode();
            i++;
            q.push(temp->right);
        }

        else
        {
            //both childs present
            //pop
            q.pop();
        }

    }

 }

void insert(node* &root)
{
    if(root==NULL)
    {
        create(root);
        return ;
    }

    //the tree already has some data in it
    //first, generate the queue by applying bfs
    queue<node*> q;
    node* temp;
    q.push(root);
    
    while(q.front()->left && q.front()->right)
    { 
       temp=q.front();
       q.push(temp->left);
       q.push(temp->right);

       q.pop();

    }

    if(q.front()->left)
        q.push(q.front()->left);

    //now, start the insertion process, similar to creation
    int i,j,k,n;
    cout<<endl<<"Enter the no. of nodes you want to insert ";
    cin>>n;

    if(n<=0)
        return ;

    i=1;
    while(i<=n)
    {
        temp=q.front();
        if(!temp->left)
        {
            //left child is empty
            temp->left=newNode();
            i++;
            q.push(temp->left);
        }

        else if(!temp->right)
        {
            //right child is empty
            temp->right=newNode();
            i++;
            q.push(temp->right);
        }

        else
        {
            //both childs present
            //pop
            q.pop();
        }

    }
}

void preorder(node* &root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* &root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";

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


void preorderIterative(node* &root)
{
    if(!root)
        return ;

    stack<node*> s;
    node* temp;

    s.push(root);
    while(!s.empty())
    {
        temp=s.top();
        cout<<temp->data<<" ";
        
        s.pop();
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);

        
    }

}

void postorderIterative(node* &root)
{
    if(!root)
        return ;

    stack<node*> s1,s2;
    node* temp;
    s1.push(root);
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
    
}

void inorderIterative(node* &root)
{
   if(!root)
       return ;
   stack<node*> s;
   node* temp=root;

   while(temp || !s.empty())
   {
       if(temp==NULL)
       {
           //display from stack 
           cout<<s.top()->data<<" ";
           if(s.top()->right)
               temp=s.top()->right;

           s.pop();
       }

       else
       {
            if(temp->left)
            {
                //push temp to the stack and update temp
                s.push(temp);
                temp=temp->left;
            }

            else
            {
                cout<<temp->data<<" ";
                if(!s.empty())
                {
                    cout<<s.top()->data<<" ";
                    if(s.top()->right)
                        temp=s.top()->right;
                    else
                        temp=NULL;

                    s.pop();
                }

                else
                    temp=NULL; //breaking point
            }
       }
   }
}

void search(node* &root,int x)
{
    if(root==NULL)
    {
        cout<<"empty tree"<<endl;
        return ;
    }

    queue<node*> q;
    q.push(root);

    node *temp;

    bool found=false;
    while(found==false && !q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp->data==x)
        {
            cout<<"element found"<<endl;
            found=true;

            return ;
        }

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);

    }

    if(found==false)
    {
        cout<<"element not found"<<endl;
    }
}


void deleteNode(node* &root,int x)
{
    if(root==NULL)
    {
        cout<<"empty tree"<<endl;
        return ;
    }

    bool found=false;
    node *temp,*deep;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        deep=q.front();
        q.pop();

        if(deep->data==x)
        {
            temp=deep;
            found=true;
        }
        
        if(deep->left)
            q.push(deep->left);

        if(deep->right)
            q.push(deep->right);        
    }

    if(found==false)
    {
        cout<<"element not found"<<endl;
        return ;
    }


    //replace the deepest node with temp, then delete deepest node
    cout<<"temp="<<temp->data<<endl<<"deep="<<deep->data<<endl;

    temp->data=temp->data+deep->data;
    deep->data=temp->data-deep->data;
    temp->data=temp->data-deep->data;

    levelorder(root);
    
    delete deep;

    cout<<"element deleted"<<endl;

}

void deleteTree(node* &root)
{
     //deletion using post order traversal

    if(root==NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root; 
}

void levelWiseDisplay(node* &root)
{

}


int main()
{
    node* root=NULL;
    int x,y;

    do
    {
        cout<<endl<<endl<<"MENU"<<endl<<endl;
        cout<<" 1 insert"<<endl;
        cout<<" 2 preorder traversal"<<endl;
        cout<<" 3 postorder traversal"<<endl;
        cout<<" 4 inorder traversal"<<endl;
        cout<<" 5 levelorder traversal"<<endl;
        cout<<" 6 preorder iterative"<<endl;
        cout<<" 7 postorder iterative"<<endl;
        cout<<" 8 inorder iterative"<<endl;
        cout<<" 9 search an element"<<endl;
        cout<<" 10 delete an element"<<endl;
        cout<<" 11 delete tree"<<endl;

        cout<<" 15 exit"<<endl;

        cout<<endl<<"Enter your choice  ";
        in(x);

        switch(x)
        {
            case 1:insert(root);
                break;

            case 2:cout<<"preorder traversal"<<endl;
                   preorder(root);
                break;

            case 3:cout<<"postorder traversal"<<endl;
                   postorder(root);
                break;
           
            case 4:cout<<"inorder traversal"<<endl;
                   inorder(root);
                break;

            case 5:cout<<"levelorder traversal"<<endl;
                   levelorder(root);
                break;

            case 6:cout<<"preorder iterative traversal"<<endl;
                   preorderIterative(root);
                break;

            case 7:cout<<"postorder iterative traversal"<<endl;
                   postorderIterative(root);
                break;
           
            case 8:cout<<"inorder iterative traversal"<<endl;
                   inorderIterative(root);
                break;

            case 9:cout<<"enter the value of node to be searched  ";
                   in(y);
                   search(root,y);
                   break;

            case 10:cout<<"enter the value of node to be deleted  ";
                   in(y);
                   deleteNode(root,y);
                   break;

            case 11:cout<<"deleting tree"<<endl;
                    deleteTree(root);
                    break;

            case 15:cout<<"exiting..."<<endl;
                break;

            default:cout<<"invalid option...please try again"<<endl;

        }

    }while(x!=15);

    return 0;
}
