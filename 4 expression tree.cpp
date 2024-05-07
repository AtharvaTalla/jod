#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char d) : data(d), left(nullptr), right(nullptr) {}
};
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
TreeNode* constructExpressionTree(string prefixExpr) {
    stack<TreeNode*> stk;
    for (int i = prefixExpr.length() - 1; i >= 0; --i) {
        char c = prefixExpr[i];
        if (isalnum(c)) { 
            stk.push(new TreeNode(c));
        } else if (isOperator(c)) { 
            TreeNode* newNode = new TreeNode(c);
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }
    
   
    return stk.top();
}
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
    deleteTree(root);
    return 0;
}
