#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Expression Tree Node
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char d) : data(d), left(nullptr), right(nullptr) {}
};

// Function to check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to construct expression tree from prefix expression
TreeNode* constructExpressionTree(string prefixExpr) {
    stack<TreeNode*> stk;
    
    // Traverse the prefix expression in reverse order
    for (int i = prefixExpr.length() - 1; i >= 0; --i) {
        char c = prefixExpr[i];
        if (isalnum(c)) { // If operand, create a node and push onto stack
            stk.push(new TreeNode(c));
        } else if (isOperator(c)) { // If operator, create a node and attach left and right children
            TreeNode* newNode = new TreeNode(c);
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }
    
    // Root of the expression tree will be at the top of stack
    return stk.top();
}

// Function to traverse expression tree using post-order traversal (non-recursive)
void postOrderTraversal(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (current || !stk.empty()) {
        if (current) {
            stk.push(current);
            current = current->left;
        } else {
            TreeNode* topNode = stk.top();
            if (topNode->right && lastVisited != topNode->right) {
                current = topNode->right;
            } else {
                cout << topNode->data << " ";
                lastVisited = topNode;
                stk.pop();
            }
        }
    }
}

// Function to delete the entire expression tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    string prefixExpr = "+--a*bc/def";
    TreeNode* root = constructExpressionTree(prefixExpr);

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Deleting the entire tree to avoid memory leaks
    deleteTree(root);

    return 0;
}
