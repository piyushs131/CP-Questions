#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void inorder(Node* root1,Node* root2, int &sum)
    {
        if(root1==NULL && root2==NULL) return;
        else if(root1 == NULL && root2!=NULL){
            sum+= abs(root2->data);
        } 
        else if(root2 == NULL && root1!=NULL){
            sum+= abs(root1->data);
        } 
        else sum+= abs(root1->data - root2->data);
        
        inorder(root1 ? root1->left : NULL, root2 ? root2->left : NULL, sum);
        inorder(root1 ? root1->right : NULL, root2 ? root2->right : NULL, sum);
    }
    int differenceSum(Node* root1, Node* root2) {
        int ans =0;
        inorder(root1,root2,ans);
        return ans;
    }
};