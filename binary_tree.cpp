//Complete binary tree operations

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

node *newNode(int x)
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
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

    i=2;
    while(i<=n)
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
   node* nxtNode=root;

   while(nxtNode || !s.empty())
   {
       if(nxtNode==NULL)
       {
           //display from stack 
           cout<<s.top()->data<<" ";
           if(s.top()->right)
               nxtNode=s.top()->right;

           s.pop();
       }

       else
       {
            if(nxtNode->left)
            {
                //push temp to the stack and update temp
                s.push(nxtNode);
                nxtNode=nxtNode->left;
            }

            else
            {
                cout<<nxtNode->data<<" ";
                if(!s.empty())
                {
                    cout<<s.top()->data<<" ";
                    if(s.top()->right)
                        nxtNode=s.top()->right;
                    else
                        nxtNode=NULL;

                    s.pop();
                }

                else
                    nxtNode=NULL; //breaking point
            }
       }
   }
}

bool search(node* &root,int x)
{
    if(root==NULL)
    {
        return false;
    }

    queue<node*> q;
    q.push(root);

    node *temp;

    bool found=false;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp->data==x)
        {
            return true;
        }

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);

    }

    return false;
}


void deleteNode(node* &root,int x)
{
    if(root==NULL)
    {
        cout<<"empty tree"<<endl;
        return ;
    }

    bool found=false;
    node *temp,*parent,*child;
    queue<node*> q;
    q.push(root);
    
    //search the node, and store in temp
    while(!q.empty()&&found==false)
    {
        temp=q.front();
        q.pop();

        if(temp->data==x)
        {
            found=true;
            break;
        }

        //store left and right children
        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);

    }

    if(found==false)
    {
        cout<<"element not found"<<endl;
        return ;
    }

    //find the deepest node
    parent=root;
    if(parent->right)
    {
        child=root->right;
    }

    else if(parent->left)
    {
        child=root->left;
    }

    else
    {
        //only single node in the tree
        root=NULL;
        cout<<"element deleted"<<endl;

        return ;
    }

    while(child->left||child->right)
    {
        if(child->right)
        {
            parent=child;
            child=child->right;
        }

        else
        {
            parent=child;
            child=child->left;
        }
    }

    //replace the deepest node with temp, then delete deepest node
    temp->data=temp->data+child->data;
    child->data=temp->data-child->data;
    temp->data=temp->data-child->data;

    //now, delete the child
    if(parent->right)
    {
        delete child;
        parent->right=NULL;
    }

    else
    {
        delete child;
        parent->left=NULL;
    }

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

void deleteTreeIterative(node* &root)
{
     //deletion using post order traversal

    if(root==NULL)
        return;

    stack<node*> s1;
    node *temp;
    
    s1.push(root);
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        
        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);

        //delete temp now
        delete temp;
        temp=NULL;

    }

    root=NULL;
    
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

int height(node* &root)
{
    if(!root)
        return 0;

    return 1+max(height(root->left),height(root->right));
}

int heightWrapper(node *&root)
{
    if(!root)
        return 0;
    
    if(!root->left && !root->right)
        return 0;

    return max(height(root->left),height(root->right));
}

bool isFullNode(node* &root)
{
    if(root->left && root->right)
        return true;

    return false;
}

int diameter(node* root)
{
    if(!root)
        return 0;

    int x=diameter(root->left);
    int y=diameter(root->right);

    int z;

    if(isFullNode(root))
        z=height(root->left)+1+height(root->right);

    else
        z=1;

    return max(x,max(y,z));
}

void printRootToLeafPaths(node* &root,vector<int> path,int pathLen)
{
    if(!root)
        return ;

    //add this element to the path
    path.push_back(root->data);
    pathLen++;

    //if this is a leaf node
    if(!root->left && !root->right)
    {
        //print the path
        for(int i=0;i<pathLen;i++)
            cout<<path[i]<<" ";

        cout<<endl;
    }

    //display other paths
    printRootToLeafPaths(root->left,path,pathLen);
    printRootToLeafPaths(root->right,path,pathLen);
}


bool checkSumPath(node* &root,int sum)
{
    if(!root)
        return false;

    sum=sum-root->data;

    if(sum==0)
    {
        //path found
        return true;
    }

    //check remaining paths
    if(checkSumPath(root->left,sum))
        return true;

    else 
        return checkSumPath(root->right,sum);

}

bool findPath(node* &root, int x, vector<int> &pathX, int lenX)
{
    if(!root)
        return false;

    //add this to path
    if(pathX.size()>lenX)
    {
        pathX[lenX]=root->data;
        lenX++;
    }
    
    else
    {
        pathX.push_back(root->data);
        lenX++;
    }

    if(root->data==x)
    {
        //erase extra elements in the path 
        //the required element is at the index lenX-1
        //so delete remaining elements (if there)

        if(pathX.size()>lenX)
            pathX.erase(pathX.begin()+(lenX),pathX.end());
        
        return true;
    }


    //search in the children
    bool found=findPath(root->left,x,pathX,lenX);

    if(found)
        return true;

    return findPath(root->right,x,pathX,lenX);
}

int lca(node* &root,int x, int y)
{
    if(!root)
        return -1;

    vector<int> pathX;
    vector<int> pathY;

    if(!findPath(root,x,pathX,0))
        return -1;
    
    if(!findPath(root,y,pathY,0))
        return -1;
    
    //now, we have the paths of x and y 
    //compare 
    int length=min(pathX.size(),pathY.size());

    for(int i=length-1;i>=0;i--)
        if(pathX[i]==pathY[i])
            return pathX[i];
}


int main()
{
    node* root=NULL;
    int x,y;
    int sum;
    int a,b;
    vector<int> path;

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
        cout<<" 11 delete tree iterative"<<endl;
        cout<<" 12 delete tree"<<endl;
        cout<<" 13 Level Wise Display"<<endl;
        cout<<" 14 height of tree"<<endl;
        cout<<" 15 Diameter of tree"<<endl;
        cout<<" 16 Print root to leaf paths"<<endl;
        cout<<" 17 Check the existence of a path from root to any of the nodes with the given sum"<<endl;
        cout<<" 18 Find path of a node from the root"<<endl;
        cout<<" 19 Least Common Ancestor of two nodes"<<endl;

        cout<<" 20 exit"<<endl;

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
                   cin>>y;
                   if(search(root,y))
                       cout<<"Element found";
                   else
                       cout<<"Element not found";

                   cout<<endl;
                   break;

            case 10:cout<<"enter the value of node to be deleted  ";
                   in(y);
                   deleteNode(root,y);
                   break;

            case 11:cout<<"deleting tree iteratively"<<endl;
                    deleteTreeIterative(root);
                    break;

            case 12:cout<<"deleting tree"<<endl;
                    deleteTree(root);
                    break;

            case 13:cout<<"Level wise display"<<endl;
                    levelWiseDisplay(root);
                    break;

            case 14:cout<<"height of the tree"<<endl;
                    cout<<heightWrapper(root);
                    break;

            case 15:cout<<"diameter of the tree"<<endl;
                    cout<<diameter(root);
                    break;
            
            case 16:cout<<"All the root to leaf paths in the tree are"<<endl;
                    printRootToLeafPaths(root,path,0);
                    path.clear();
                    break;

            case 17:cout<<"Enter the sum whose path you want to find in the tree"<<endl;
                    cin>>sum;
                    if(checkSumPath(root,sum))
                        cout<<"Path with required sum found";
                    else
                        cout<<"No path found for given sum";

                    cout<<endl;
                    break;

            case 18:cout<<"Enter the value of node whose path you want to find"<<endl;
                    cin>>a;
                    if(!findPath(root,a,path,0))
                        cout<<"No such element found";

                    else
                    {
                        //display path
                        cout<<"The path of required node is "<<endl;
                        for(b=0;b<path.size();b++)
                            cout<<path[b]<<" ";

                        cout<<endl;
                        path.clear();
                    }

                    break;

            case 19:cout<<"Enter the value of two nodes whose LCA you want to find"<<endl;
                    cin>>a>>b;
                    cout<<"Least Common Ancestor of the given numbers is ";
                    y=lca(root,a,b);
                    if(y!=-1)
                        cout<<y;
                    else
                        cout<<"Not Found";

                    break;


            case 20:cout<<"exiting..."<<endl;
                break;

            default:cout<<"invalid option...please try again"<<endl;

        }

    }while(x!=20);

    return 0;
}
