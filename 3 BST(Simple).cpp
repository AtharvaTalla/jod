#include <iostream>
#include <climits> 
#include <stack>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
public:
    TreeNode* root;
    BST() : root(nullptr) {}
    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }  
    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    void displayInorder() {
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }
    int findMin() {
        if (root == nullptr)
            return INT_MAX;

        TreeNode* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }
    void swapLeftRight() {
        if (root == nullptr)
            return;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();

            if (current->left != nullptr)
                s.push(current->left);
            if (current->right != nullptr)
                s.push(current->right);

            swap(current->left, current->right);
        }
    }
    int longestPathLength() {
        if (root == nullptr)
            return 0;

        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int maxPath = 0;

        while (!s.empty()) {
            auto nodePair = s.top();
            s.pop();
            TreeNode* current = nodePair.first;
            int pathLength = nodePair.second;

            maxPath = max(maxPath, pathLength);

            if (current->left != nullptr)
                s.push({current->left, pathLength + 1});
            if (current->right != nullptr)
                s.push({current->right, pathLength + 1});
        }

        return maxPath;
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    cout << "Inorder Traversal: ";
    bst.displayInorder();
    cout << "Number of nodes in longest path from root: " << bst.longestPathLength() << endl;
    cout << "Minimum data value in the tree: " << bst.findMin() << endl;
    bst.swapLeftRight();
    cout << "Inorder Traversal after swapping left and right pointers: ";
    bst.displayInorder();
    int searchValue = 4;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
    }

    return 0;
}






// ALGORITHM :
// Algorithm CreateBinaryTree():
// // This algorithm is used to create a binary tree with no input and return nothing.

// Repeat
// Read data element from the user into &#39;Value&#39;;
// Create a new node;
// temp = new node;
// temp-&gt;data = value;
// temp-&gt;left = NULL;
// temp-&gt;right = NULL;
// If (root is NULL) then // Tree is Empty.
// root = temp;
// Else // Add a new node into the existing tree.
// Insert(root, temp);
// Until (false);

// Algorithm Insert(root, temp):
// // This algorithm is used to add a new node in an existing tree pointed to by root. It returns
// nothing.
// If (root is not NULL)
// {
// If (root-&gt;data &gt; temp-&gt;data) then // Left Subtree
// {
// If (temp-&gt;left is NULL) then // Left child is NULL
// temp-&gt;left = temp;
// Else
// Insert(temp-&gt;left, temp); // Check next left link
// }
// Else
// {
// If (ch is Right side) then // Right Subtree
// {
//     If (temp-&gt;right is NULL) then // Right child is NULL
// temp-&gt;right = temp;
// Else
// Insert(temp-&gt;right, temp); // Check next right link
// }
// }
// }
// Algorithm Preorder(temp):
// // This algorithm is used to display the nodes in VLR (Value-Left-Right) way.
// If (temp is not NULL) then
// {
// Write(temp-&gt;data);
// Call Preorder(temp-&gt;lptr);
// Call Preorder(temp-&gt;rptr);
// }
// Algorithm Inorder(temp):
// // This algorithm is used to display the nodes in LVR (Left-Value-Right) way.
// If (temp is not NULL) then
// {
// Call Inorder(temp-&gt;lptr);
// Write(temp-&gt;data);
// Call Inorder(temp-&gt;rptr);
// }
// Algorithm Postorder(temp):
// // This algorithm is used to display the nodes in LRV (Left-Right-Value) way.
// If (temp is not NULL) then
// {
// Call Postorder(temp-&gt;lptr);
// Call Postorder(temp-&gt;rptr);
// Write(temp-&gt;data);
// }
// Algorithm Search(root, val, parent):
// // This algorithm is used to search for an element in a Binary Search Tree (BST).
// If (root is not NULL) then // Tree exists.
// {
// If (root-&gt;data &gt; val) then // Search in the Left subtree.
// Search(root-&gt;llink, val, root);
// Else If (root-&gt;data &lt; val) then // Search in the Right subtree.
// Search(root-&gt;rlink, val, root);
// If (root-&gt;data == val) then // Successful search.
// {
// Write(&quot;Value is found successfully&quot;);
// Return parent;
// }
// }
// Else // Unsuccessful search.
// Return NULL;

// Algorithm Smallest(root):
// // This algorithm finds the minimum data value found in the tree.
// While (root-&gt;ln is not NULL)
// {
// root = root-&gt;ln;
// }
// Print root-&gt;key;

// Algorithm LongestPath(root):
// // This algorithm finds the number of nodes in the longest path in the tree.
// If (root is NULL)
// Return 0;
// L = LongestPath(root-&gt;ln);
// R = LongestPath(root-&gt;rn);
// If (L &gt; R)
// Return (L + 1);
// else
// Return (R + 1);

// Algorithm swapNodes(root):
// // This algorithm changes a tree so that the roles of the left and right pointers are swapped at every
// node.
// Node* temp;
// If (root is NULL)
// Return NULL;
// temp = root-&gt;ln;
// root-&gt;ln = root-&gt;rn;
// root-&gt;rn = temp;
// swapNodes(root-&gt;ln);
// swapNodes(root-&gt;rn);







