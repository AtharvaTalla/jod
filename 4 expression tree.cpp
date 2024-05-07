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











// ALGORITHM :

// Algorithm: Construct Expression Tree from Prefix Expression
// Include Necessary Libraries:
// 1. Include iostream for input/output.
// 2. Include stack for stack data structure.
// 3. Include cctype for character type checking (isalpha).
// Define TreeNode Structure:
// 1. Define a structure named TreeNode with character data, left, and right pointers.
// 2. Define Operator Checking Function:

// a. Define a function isOperator(c) that checks if a given character is an operator (+, -, *, /).
//     Construct Expression Tree Function:
// Define a function constructExpressionTree(prefix) that takes a prefix expression as input.
// 1. Create an empty stack of TreeNode pointers.
// 2. Iterate through the characters of the prefix expression in reverse order:
// 3. If the current character is an operand (isalpha), create a TreeNode and push it onto the stack.
// 4. If the current character is an operator, create a TreeNode with the operator, pop two elements from
// the stack and set them as the left and right children of the new TreeNode. Push the new TreeNode
// onto the stack.
// 5. The top of the stack now contains the root of the expression tree. Return it.
// Post-order Traversal Function:
// Define a function postOrderTraversal(root) that performs post-order traversal of the expression
// tree.
// 1. Create two stacks: one for tree traversal and another to store the result characters.
// 2. Push the root onto the traversal stack.
// 3. While the traversal stack is not empty:
// 4. Pop a node from the traversal stack.
// 5. Push the data of the node onto the result stack.
// 6. If the node has a left child, push it onto the traversal stack.
// 7. If the node has a right child, push it onto the traversal stack.
// 8. Print the characters from the result stack in reverse order.
// Delete Tree Function:
// Define a function deleteTree(root) that deletes the entire expression tree.
// 1. Use a post-order traversal approach:
// 2. Create a stack and push the root onto it.
// 3. While the stack is not empty:
// 4. Pop a node from the stack.
// 5. If the node has a left child, push it onto the stack.
// 6. If the node has a right child, push it onto the stack.
// 7. Delete the current node.
// Main Function:
// In the main function:
// 1. Declare a prefix expression string, e.g., &quot;+--a*bc/def&quot;.
// 2. Call constructExpressionTree to obtain the root of the expression tree.
// 3. Print the post-order traversal of the expression tree.
// 4. Call deleteTree to free up memory.
// End of Algorithm.
