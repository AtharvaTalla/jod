#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

// Node structure for Binary Search Tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a value into the BST
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Function to find the number of nodes in the longest path from the root
    int longestPathLength() {
        return longestPathLengthRecursive(root);
    }

    // Recursive function to find the number of nodes in the longest path
    int longestPathLengthRecursive(TreeNode* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftPathLength = longestPathLengthRecursive(current->left);
        int rightPathLength = longestPathLengthRecursive(current->right);

        return 1 + max(leftPathLength, rightPathLength);
    }

    // Function to find the minimum data value in the tree
    int findMin() {
        return findMinRecursive(root);
    }

    // Recursive function to find the minimum data value
    int findMinRecursive(TreeNode* current) {
        if (current == nullptr) {
            return INT_MAX; // Return maximum possible integer value if tree is empty
        }

        int minValue = current->data;
        int leftMin = findMinRecursive(current->left);
        int rightMin = findMinRecursive(current->right);

        return min(minValue, min(leftMin, rightMin));
    }

    // Function to swap the left and right pointers at every node
    void swapLeftRight() {
        swapLeftRightRecursive(root);
    }

    // Recursive function to swap left and right pointers
    void swapLeftRightRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        // Swap left and right pointers
        swap(current->left, current->right);

        // Recur for left and right subtrees
        swapLeftRightRecursive(current->left);
        swapLeftRightRecursive(current->right);
    }

    // Function to search for a value in the BST
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Recursive function to search for a value in the BST
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Function to display the BST using inorder traversal
    void displayInorder() {
        inorderTraversal(root);
        cout << endl;
    }

    // Recursive function for inorder traversal
    void inorderTraversal(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }
};

int main() {
    BST bst;

    // Insert values into the BST
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // Display the BST using inorder traversal
    cout << "Inorder Traversal: ";
    bst.displayInorder();
    
    // Find the number of nodes in the longest path from the root
    cout << "Number of nodes in longest path from root: " << bst.longestPathLength() << endl;

    // Find the minimum data value in the tree
    cout << "Minimum data value in the tree: " << bst.findMin() << endl;

    // Swap left and right pointers at every node
    bst.swapLeftRight();

    // Display the modified BST using inorder traversal
    cout << "Inorder Traversal after swapping left and right pointers: ";
    bst.displayInorder();

    // Search for a value in the BST
    int searchValue = 4;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    } else {
        cout << searchValue << " not found in the tree." << endl;
    }

    return 0;
}
