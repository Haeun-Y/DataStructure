#include <iostream>
using namespace std;
typedef struct TreeNode 
{
    char ch;
    TreeNode* left;
    TreeNode* right;
}TreeNode;
void init_tree(TreeNode * root)
{
    root->ch = 'A';
    root->left = root->right = NULL;
}

TreeNode* find_node(TreeNode* cur, char ch)
{
    if(cur->ch == ch) return cur;
    else if(cur == NULL) 
    {
        TreeNode * new_node = (TreeNode*)malloc(sizeof(TreeNode));
        new_node->ch = ',';
        return new_node;
    }
    
    else
    {
        cout << "cur->ch : " << cur->ch << "\n";
        TreeNode * child = find_node(cur->left, ch);
        cout << "cur->ch : " << cur->ch << "\n";
        if(child->ch != ',') return child;

        child = find_node(cur->right, ch);
        if(child->ch != ',') return child;
        
    }
    
    TreeNode * r_node = (TreeNode*)malloc(sizeof(TreeNode));
    r_node->ch = ',';
    return r_node;

}
void insert_node(TreeNode* root, char cur, char left, char right)
{
    TreeNode* new_node = find_node(root, cur);
    if(new_node == NULL)
    {
        cout << "fail to find\n";
        return;
    }
    cout << "check the cur_node : " << new_node->ch << "\n";

    if(left != '.')
    {
        TreeNode * left_child = (TreeNode*)malloc(sizeof(TreeNode));
        left_child->ch = left;
        left_child->left = left_child->right = NULL;

        new_node -> left = left_child;
    }

    if(right != '.')
    {
        TreeNode * right_child = (TreeNode*)malloc(sizeof(TreeNode));

        right_child->ch = right;
        right_child->left = right_child->right = NULL;
        
        new_node -> right = right_child;
    }

    cout << "cur : " << new_node->ch;
    if(new_node -> left != NULL) cout << "  left : " << new_node->left->ch;
    if(new_node -> right != NULL) cout << "  right : " << new_node->right->ch;
    cout << "\n";
}
void preorder(TreeNode * node)
{
    if(node == NULL) return;
    else
    {
        cout << node->ch;
        preorder(node->left);
        preorder(node->right);
    }


}
void inorder(TreeNode * node)
{
    
    if(node == NULL) return;
    else
    {
        inorder(node->left);
        cout << node->ch;
        inorder(node->right);
    }

}
void postorder(TreeNode * node)
{
    if(node == NULL) return;
    else
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->ch;
    }
    

}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    TreeNode root;
    init_tree(&root);

    int total_node_num;
    cin >> total_node_num;

    for(int i = 0; i<total_node_num; i++)
    {
        char cur, left, right;
        cin >> cur >> left >> right;

        cout << "cur : " << cur << "  left : " << left << "  right : " << right << "\n";

        insert_node(&root, cur, left, right);
    }

    /*preorder(&root);
    cout << "\n";

    inorder(&root);
    cout << "\n";

    postorder(&root);
    cout << "\n";*/


    





}
