#include <iostream>
#include <map>
using namespace std;

map<string, string> dictionary;

void AddKeyword() {
    string word, meaning;
    cout << "Enter keyword: ";
    cin >> word;
    cout << "Enter meaning: ";
    cin >> meaning;
    dictionary[word] = meaning;
    cout << "Keyword added successfully.\n";
}

void DeleteKeyword() {
    string word;
    cout << "Enter keyword to delete: ";
    cin >> word;
    if (dictionary.erase(word) == 1) {
        cout << "Keyword deleted successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void UpdateKeyword() {
    string word, meaning;
    cout << "Enter keyword to update: ";
    cin >> word;
    if (dictionary.find(word) != dictionary.end()) {
        cout << "Enter new meaning: ";
        cin >> meaning;
        dictionary[word] = meaning;
        cout << "Meaning updated successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void DisplayAscending() {
    cout << "Dictionary in Ascending Order:\n";
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void DisplayDescending() {
    cout << "Dictionary in Descending Order:\n";
    for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void FindMaxComparisons() {
    string word;
    cout << "Enter keyword to find maximum comparisons: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        cout << "Maximum comparisons required: " << distance(dictionary.begin(), it) + 1 << endl;
    } else {
        cout << "Keyword not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Add Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Meaning\n";
        cout << "4. Display in Ascending Order\n";
        cout << "5. Display in Descending Order\n";
        cout << "6. Find Maximum Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddKeyword();
                break;
            case 2:
                DeleteKeyword();
                break;
            case 3:
                UpdateKeyword();
                break;
            case 4:
                DisplayAscending();
                break;
            case 5:
                DisplayDescending();
                break;
            case 6:
                FindMaxComparisons();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}












// ALGORITHM:
// Algorithm: Dictionary Operations Using BST
// 1. Creating a Dictionary
// 1. Start the CreateDictionary function.
// 2. Use a do-while loop to repeatedly read input for creating a new node in the DICTIONARY.
// 3. Create a new node temp to store the key and meaning.
// 4. Prompt the user to enter the key and meaning.
// 5. Initialize left and right pointers of temp to nullptr.
// 6. Check if the BST is empty (root is nullptr).
// 7. If empty, set root to temp.
// 8. If not empty, call the Insert function with root and temp as arguments.
// 2. Inserting a New Node
// 1. Start the Insert function with parameters Node* root and Node* temp.
// 2. Check if the root is not nullptr.
// 3. If not nullptr, compare the lengths of the keys (l1 and l2) and determine the minimum length (l).
// 4. Iterate through the characters of the keys up to the minimum length.
// 5. Compare characters at the same position.
// 6. If the character in the root&#39;s key is greater, check the left subtree.
// 7. If the left child is nullptr, set temp as the left child.
// 8. If not nullptr, recursively call Insert with left child as the new root.
// 9. If the character in the root&#39;s key is lesser, check the right subtree.
// 10. If the right child is nullptr, set temp as the right child.
// 11. If not nullptr, recursively call Insert with right child as the new root.
// 12. If the root is nullptr, print &quot;No tree exists.&quot;
// 3. Tree Traversal Algorithms
// 1. Preorder Traversal:
// a. Start the Preorder function with parameter Node* temp.
// b. If temp is not nullptr:
// c. Print the key of the current node.
// d. Recursively call Preorder for the left subtree.
// e. Recursively call Preorder for the right subtree.
//     2. Inorder Traversal:
// a. Start the Inorder function with parameter Node* temp.
// b. If temp is not nullptr:
// c. Recursively call Inorder for the left subtree.
// d. Print the key of the current node.
// e. Recursively call Inorder for the right subtree.
// 3. Postorder Traversal:
// a. Start the Postorder function with parameter Node* temp.
// b. If temp is not nullptr:
// c. Recursively call Postorder for the left subtree.
// d. Recursively call Postorder for the right subtree.
// e. Print the key of the current node.
// 4. Printing the Dictionary
// a. In Ascending Order:
// 1. Start the InorderPrint function with parameter Node* temp.
// 2. Call the Inorder function with temp as an argument.
// b. In Descending Order:
// 1. Start the DescendingOrderPrint function with parameter Node* temp.
// 2. Call the descending_order function with temp as an argument.

// 5. Searching an Element in BST
// 1. Start the Search function with parameters Node* root, Node* temp, and Node*&amp; parent.
// 2. Check if the root is not nullptr.
// 3. If not nullptr, compare the lengths of the keys (l1 and l2) and determine the minimum length (l).
// 4. Iterate through the characters of the keys up to the minimum length.
// 5. Compare characters at the same position.
// 6. If the character in the root&#39;s key is greater, recursively call Search with the left subtree.
// 7. If the character in the root&#39;s key is lesser, recursively call Search with the right subtree.
// 8. If characters are equal and strings match, print &quot;Value is found successfully&quot; and return the parent
// node.
// 9. If the root is nullptr, return nullptr (indicating an unsuccessful search).
