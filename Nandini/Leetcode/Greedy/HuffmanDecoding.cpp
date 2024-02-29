#include<bits/stdc++.h>
using namespace std;
class node
{
    public : 
    node* left;
    node* right;
    int val;
    node(int value)
    {
        left = NULL;
        right = NULL;
        val = value;
    }
};

class cmp
{
    public:
    bool operator()(node* a,node* b)
    {
        return a->val > b->val;
    }
};
class Solution
{
	public:
	
	    void traverse(node* root,vector<string> &ans,string temp)
	    {
	        if(root->left==NULL && root->right==NULL)
	        {
	            ans.push_back(temp);
	            return;
	        }
	        traverse(root->left,ans,temp+'0');
	        traverse(root->right,ans,temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    node* root= NULL;
		    node* temp;
		    priority_queue<node*, vector<node*> ,cmp > pq;
		    for(int i=0 ; i<N ; i++)
		    {
		        temp = new node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() >1)
		    {
		        node* left = pq.top(); pq.pop();
		        node* right = pq.top(); pq.pop();
		        
		        temp = new node(left->val + right->val);
		        temp->left = left;
		        temp->right = right;
		        pq.push(temp);
		    }
		    root = pq.top();
		    vector<string> ans;
		    string tempp = "";
		    traverse(root,ans,tempp);
		    return ans;
		}
};