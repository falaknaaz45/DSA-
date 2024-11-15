#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Class for the Binary Tree
class BinaryTree {
public:
    TreeNode* root;
    
    BinaryTree() : root(NULL) {}

    // Pre-order traversal (Root, Left, Right)
    void preOrder(TreeNode* node) {
        if (node == NULL)
            return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // In-order traversal (Left, Root, Right)
    void inOrder(TreeNode* node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    // Post-order traversal (Left, Right, Root)
    void postOrder(TreeNode* node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);

    cout << "Pre-order Traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "In-order Traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Post-order Traversal: ";
    tree.postOrder(tree.root);
    cout << endl;

    return 0;
}

