#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;


template<typename T>

class Node{
    public:
    T data;
    vector<Node<T>*>child;
    
    //constructor
    Node(T data)
    {
        this->data = data;
    }
    
    //Destructor (Runs when we call delete function & 
    //first of all Destructor complete then the called node actually deleted)
    ~Node()
    {
        for(int i=0;i<child.size();i++)
        {
            delete child[i];
        }
    }
};


//function to create treeNode
Node* Maketree()
{
    int data;
    cin>>data;
    Node* root = new Node(data);
    int n;
    cout<<"Enter no of child"<<data<<"have :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Node* childnode = Maketree();
        root->child.push_back(childnode);
    }
    return root;
}

int main()
{
    Node* root = Maketree();
    return 0;
}