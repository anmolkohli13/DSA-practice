#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Trienode
{   
public:
    Trienode* children[26];
    int freq;
};
Trienode* newnode()
{
    Trienode* temp= new Trienode();
    for(int i=0;i<26;i++)
    {
        temp->children[i]=NULL;
    }

    temp->freq=0;
    return temp;
}
void Insert(Trienode* root,string key)
{
    Trienode* temp=root;
    
    for(int i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        
        if(!temp->children[index])
            temp->children[index] = newnode();
        
        
        (temp->children[index]->freq)++;
        temp=temp->children[index];
    }
}

int Search(Trienode* root,string key)
{   
    Trienode* temp=root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        temp=temp->children[index];
        
        if(temp->freq==1)return i;
    }
    
    return key.length();
    
}
void prefix(vector<string> &A) {
    
    Trienode* root= newnode();
    for(int i=0;i<A.size();i++)
    {
        Insert(root,A[i]);
    }
    vector<string>ans;
    for(int i=0;i<A.size();i++)
    {
        int j = Search(root,A[i]);
        
        cout<<A[i]<<"----"<<A[i].substr(0,j+1)<<endl;
    }
    
}

int main()
{
    vector<string> arr={"geeksgeeks","geeksquiz","geeksforgeeks","geeksfforgeeks"}; 
    prefix(arr);
    
    return 0;
}
