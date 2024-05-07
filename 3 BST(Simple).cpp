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











