#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
    
}TreeNode;
int leaf_node(TreeNode* node)
{
    if(node == NULL) retun 0;
    else if(node->left == NULL && node->right ==NULL)
        return 1;
    
    else return leaf_node(node->left) + leaf_node(node->right);
    
}
node* find_node(int key, TreeNode * node)
{
    TreeNode * result = NULL;
    if(node == NULL) return result;
    else if(node->key == key)
    {
        result = node; 
        return result;
    }
    else
    {
        find_node(node->left);
        find_node(node->right);
    }
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    TreeNode root;
    
    int node_num;
    cin >> node_num;
    
    for(int i = 0; i<node_num; i++)
    {
        int parent;
        cin >> parent;
        TreeNode* p = find_node(parent, &root);
    }
    
    cout << leaf_node;
    
}
