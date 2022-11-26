//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        int curr = 0;
        string temp;
        while(curr<str.size() && isdigit(str[curr]))
        {
            temp += str[curr];
            curr++;
        }
        int x = stoi(temp);
        Node* root = new Node(x);
        root->data = x;
        
        for(int i = curr;i<str.size();i++)
        {
            int open = 1;
            string te;
            int j = i+1;
            while(open)
            {
                if(str[j]=='(')open++;
                else if(str[j]==')')open--;
                if(!open)   {j++;continue;}
                te += str[j];
                j++;
            }
            
            if(i==curr)
            {
                root->left = treeFromString(te);
            }
            else
            {
                root->right = treeFromString(te);
            }
            i = j - 1;
        }
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends