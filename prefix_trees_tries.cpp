//Trie (prefix trees) 
//insertion, deletion, searching, displaying all words with a given prefix, displaying longest word with a given prefix

//this program creates a prefix tree for words made from lowercase alphabets only
#include<bits/stdc++.h>
using namespace std;

struct trieNode
{
    int value;  //if non-zero value means a word ends here else zero value indicates no ending word here
    //trieNode* child[26];
    vector<trieNode*> child;  //26 lowercase alphabets
};


trieNode* getNew()
{
    trieNode* temp=new trieNode;
    temp->value=0;  //indicating no word ending here

    temp->child.resize(26);

    for(int i=0;i<26;i++)
        temp->child[i]=NULL;  

    return temp;
}


int CHAR_TO_INDEX(char ch)
{
    return ch-'a';
}

char INDEX_TO_CHAR(int i)
{
    return char(i+'a');
}


//Trie ADT functions
bool insertWord(trieNode* &head, string str)
{
    //return false, if word already present in the trie
    //else returns true and increment wordCount(head->value)
    
    trieNode *temp=head;
    int i=0;
    while(i<str.length())
    {
        if(!temp->child[CHAR_TO_INDEX(str[i])])
        {
            //create child
            temp->child[CHAR_TO_INDEX(str[i])]=getNew();
        }

        temp=temp->child[CHAR_TO_INDEX(str[i])];
        i++;
    }

    if(temp->value==0)
    {
        head->value++;
        temp->value=head->value;
        return true;
    }

    else
    {
        return false;
    }
    
    
}

bool findWord(trieNode* &head, string str)
{
    //return true if word found
    //else return false
    
    if(head->value==0)
        return false;
    
    trieNode* temp=head;
    int i=0;

    while(i<str.length())
    {
       if(!temp->child[CHAR_TO_INDEX(str[i])])
       {
           //not found
           return false;
       }

       temp=temp->child[CHAR_TO_INDEX(str[i])];
       i++;
    }

    if(temp->value==0)
        return false;

    return true;
}

bool isLeafNode(trieNode* &temp)
{
    int i=0;
    bool leaf=true;
    while(leaf==true && i<26)
    {
        if(temp->child[i])
            return false;

        i++;
    }

    return true;
}

bool deleteWord(trieNode* &head, string str)
{
    //if word present, delete it and return true
    //else return false
    
    if(head->value==0)
    {
        //trie empty
        return false;
    }

    trieNode *temp=head,*temp2;
    int i=0;
    stack<pair<trieNode*,int> > s;

    while(i<str.length())
    {
        if(!temp->child[CHAR_TO_INDEX(str[i])])
        {
            //word not found
            return false;
        }

        s.push(make_pair(temp,CHAR_TO_INDEX(str[i])));

        temp=temp->child[CHAR_TO_INDEX(str[i])];
        i++;
    }

    if(temp->value==0)
    {
        //word not found
        return false;
    }

    //word found
    //proceed for deletion
    

    //if temp is not the leaf node, simply set its value to zero
    //otherwise, keep deleting the nodes from temp towards the root until a word is found
    

    //decreasing the no. of words in trie by one
    head->value--;

    //checking for leaf node
    if(isLeafNode(temp)==false)
    {
        //not a leaf node
        temp->value=0;
        return true;
    }

    //deletion of a leaf node
    do
    {
        temp2=s.top().first;
        i=s.top().second;
        s.pop();
        delete temp;

        temp2->child[i]=NULL;
        temp=temp2;

    }while(isLeafNode(temp));

    return true;

}

void display(trieNode* &temp, string str)
{
    if(temp->value)
    {
        cout<<str<<endl;
    }

    int i=0;
    while(i<26)
    {
        if(temp->child[i])
        {
            display(temp->child[i],str+INDEX_TO_CHAR(i));
        }

        i++;
    }
}

void displayWordsWithGivenPrefix(trieNode* &head, string str)
{

    if(head->value==0)
    {
        cout<<"trie is empty"<<endl;
        return ;
    }

    trieNode* temp=head;
    int i=0;
    bool found=true;

    while(i<str.length())
    {
       if(!temp->child[CHAR_TO_INDEX(str[i])])
       {
           //not found
           found=false;
           break;
       }

       temp=temp->child[CHAR_TO_INDEX(str[i])];
       i++;
    }

    if(found==false)
    {
        cout<<"No word in the trie with the given prefix";
        return;
    }

    //now, display the words
    cout<<"words with given prefix are"<<endl;
    display(temp,str);

}


string displayLongest(trieNode* &temp, string str, string longStr)
{
    if(temp->value)
    {
        if(str.length()>longStr.length())
            longStr=str;

    }

    int i=0;
    string str3,strMax="";

    while(i<26)
    {
        if(temp->child[i])
        {
            str3=displayLongest(temp->child[i],str+INDEX_TO_CHAR(i),longStr);
            if(str3.length()>strMax.length())
                strMax=str3;
            
        }

        i++;
    }

    if(strMax.length()>longStr.length())
        longStr=strMax;

    return longStr;
}


void longestWordWithGivenPrefix(trieNode* &head, string str)
{

    if(head->value==0)
    {
        cout<<"trie is empty"<<endl;
        return ;
    }

    trieNode* temp=head;
    int i=0;
    bool found=true;

    while(i<str.length())
    {
       if(!temp->child[CHAR_TO_INDEX(str[i])])
       {
           //not found
           found=false;
           break;
       }

       temp=temp->child[CHAR_TO_INDEX(str[i])];
       i++;
    }

    if(found==false)
    {
        cout<<"No word in the trie with the given prefix";
        return;
    }

    //now, display the word
    cout<<"longest word with given prefix is"<<endl;
    cout<<displayLongest(temp,str,str);

}


int main()
{
    int x;
    string str1,str2,str;
   
    //trie root node and wordCount variable
    trieNode* head=getNew();

    //head->value stores wordCount
    
    do
    {
        cout<<endl<<endl<<"Trie functions";
        cout<<endl<<"1). insert a word in the trie";
        cout<<endl<<"2). search a word in the trie";
        cout<<endl<<"3). delete a  word from the trie";
        cout<<endl<<"4). Find longest matching prefix of a word in the trie";
        cout<<endl<<"5). Find all words with a given prefix";
        cout<<endl<<"6). exit";

        cout<<endl<<endl<<"Enter your choice  ";
        cin>>x;
        cin.ignore(256,'\n');

        switch(x)
        {

            case 1:cout<<endl<<"Enter the word(only lowercase alphabets) to insert in the trie  ";
                    cin>>str;
                    if(insertWord(head,str))
                        cout<<"Successfully inserted";

                    else
                        cout<<"Given word already present in the trie";
                    break;


            case 2:cout<<endl<<"Enter the string(only lowercase alphabets) to search in the trie ";
                    cin>>str;
                    if(findWord(head,str))
                            cout<<"word found";
                    else
                        cout<<"word not found";
                        
                    break;

            case 3:cout<<endl<<"Enter the string(only lowercase alphabets) to delete from the trie ";
                    cin>>str;
                    if(deleteWord(head,str))
                    {
                        cout<<"deleted";
                    }

                    else
                        cout<<"required word not found in the trie"<<endl;

                    break;

                    case 4:cout<<endl<<"Enter the string(only lowercase alphabets) whose longest matching prefix\n you want to find in the trie ";
                    getline(cin,str);
                    longestWordWithGivenPrefix(head, str);
                    break;

            case 5:cout<<endl<<"Enter the prefix string  ";
                   getline(cin,str);
                   displayWordsWithGivenPrefix(head,str);
                   break;

            case 6:cout<<endl<<"exiting ";
                    break;

            default: cout<<endl<<"invalid option";

        }

    }while(x!=6);

    return 0;
}
